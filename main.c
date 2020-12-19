#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void metronome(int, unsigned int);
unsigned int calc_sleepy_time(int);

int main(int argc, char *argv[])
{
   printf("Starting Program\n");
   if (argc == 3)
   {
        int meter;
        int bpm;
        unsigned int sleepy_time;

        meter = atoi(*++argv);
        bpm = atoi(*++argv);
        sleepy_time = calc_sleepy_time(bpm);

        printf("meter: %d\n\tbpm %d\n\tsleepytime = %d\n", meter, bpm,sleepy_time);
        metronome(meter, sleepy_time);

   }
   
}

void metronome(int pulse, unsigned int sleepy_time)
{
    int i;
    for (;;)
    {
        for (i = 0; i < pulse; i++)
        {
            printf("Beat: %d\n", i+1);
            usleep(sleepy_time);
            printf("\a");
        }
    }
}

unsigned int calc_sleepy_time(int bpm)
{
    const unsigned int milli_in_min = 60000000;
    return (unsigned int) (milli_in_min/ (unsigned int) bpm);
}

