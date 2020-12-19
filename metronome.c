#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXMETER 25

void metronome(int, unsigned int, int sleepdivisions);
unsigned int calc_sleepy_time(int);
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
        unsigned int sleepy_time;
        int ppm; //pulses per measure
        const int sleepdivisions = 6;   // this is the count of silences within one quarter note
                                        // between all the subdivisions

        meter = atoi(*++argv);

        bpm = atoi(*++argv);
        sleepy_time = calc_sleepy_time(bpm);

        printf("meter: %d\n\tbpm %d\n\tsleepytime = %d\n", meter, bpm,sleepy_time);
        setbuf(stdout, NULL);
        metronome(meter, sleepy_time, sleepdivisions);

   }
   
}

void metronome(int pulse, unsigned int sleepy_time, int sleepdivisions)
{
    int i;
    int j;
    int k = 0;

    for (;;)
    {
        for (i = 0; i < pulse; i++)
        {
            play_quarter(i);
            usleep(sleepy_time/sleepdivisions);
            play_sixteenth(k++%2);
            usleep(sleepy_time/sleepdivisions);
            for (j = 0; j < 2; j++){
                play_eighth(j);
                usleep(sleepy_time/sleepdivisions);
                play_sixteenth(k++%2);
                usleep(sleepy_time/sleepdivisions);
            }
        }
    }
}

unsigned int calc_sleepy_time(int bpm)
{
    const unsigned int milli_in_min = 60000000;
    return (unsigned int) (milli_in_min/ (unsigned int) bpm);
}

void play_quarter(int i)
{
   fprintf(stderr, "Quarter: %d\n", i+1); 
}
void play_eighth(int i)
{
    printf("\tEighth: %d\n", i+1);
}
void play_sixteenth(int i)
{
    printf("\t\tSixteenth: %d\n", i+1);
}
