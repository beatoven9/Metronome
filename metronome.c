#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXMETER 25

void metronome(int, unsigned int, int sleepdivisions);
unsigned int calculate_quarter_length(int);
void play_quarter(int);
void play_eighth(int);
void play_sixteenth(int);

int main(int argc, char *argv[])
{
   printf("Starting Program\n");
   if (argc == 3)
   {
        int meter;
        int bpm;
        unsigned int quarter_length;
        int ppm; //pulses per measure
        const int sleepdivisions = 6;   // this is the count of silences within one quarter note
                                        // between all the subdivisions

        meter = atoi(*++argv);

        bpm = atoi(*++argv);
        quarter_length = calculate_quarter_length(bpm);

        printf("meter: %d\n\tbpm %d\n\tsleepytime = %d\n", meter, bpm,quarter_length);
        setbuf(stdout, NULL);
        metronome(meter, quarter_length, sleepdivisions);

   }
   
}

void metronome(int pulse, unsigned int quarter_length, int sleepdivisions)
{
    int i;
    int j;
    int k = 0;

    for (;;)
    {
        for (i = 0; i < pulse; i++)
        {
            play_quarter(i);
            usleep(quarter_length/sleepdivisions);
   
            play_sixteenth(k++%2);
            usleep(quarter_length/sleepdivisions);
            
            for (j = 0; j < 2; j++){
                play_eighth(j);
                usleep(quarter_length/sleepdivisions);
            
                play_sixteenth(k++%2);
                usleep(quarter_length/sleepdivisions);
            }
        }
    }
}

unsigned int calculate_quarter_length(int bpm)
{
    const unsigned int milli_in_min = 60000000;
    return (unsigned int) (milli_in_min/ (unsigned int) bpm);
}

void play_quarter(int i)
{
   printf("Quarter: %d\n", i+1); 
}
void play_eighth(int i)
{
    printf("\tEighth: %d\n", i+1);
}
void play_sixteenth(int i)
{
    printf("\t\tSixteenth: %d\n", i+1);
}
