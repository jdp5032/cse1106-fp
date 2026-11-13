#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pigpio.h>
#include <string.h>
#include <ctype.h>

#define PIN 17

int GatherReadings(float readings[]);
void isInRange(float[], int[], int);
void DisplayStatus(float[], int[], int);
float calculatAverages(float[], int);

int main(int argc, char* argv[])
{
    gpioInitialise();
    gpioSetMode(PIN, PI_OUTPUT);
    gpioWrite(PIN,0); // LED Off
    char input[100] = {};
    char letter = ' ';

    float readings[10] = {};
    int ranges[10] = {};
    
    FILE *FH;
    FH = fopen("../status.txt", "r");
    
    int size = GatherReadings(readings); // Prints to terminal
    isInRange(readings, ranges, size); // Sets ranges to its numbers
    DisplayStatus(readings, ranges, size); // Prints to terminal
    if(FH == NULL)
    {
        printf("\nNo file to print to. \n");
    }
    else
    {
        fclose(FH);
        FH = freopen("../status.txt", "w", stdout);
        DisplayStatus(readings, ranges, size); // Prints to file 
        float averages = calculatAverages(readings, size);
        printf("Average: %2.1fF", averages);
        fclose(FH);
    }
    FH = freopen("/dev/tty", "r", stdout);
    gpioTerminate(); // Terminates the program
    exit(0);
    
    return 0; 
}

int GatherReadings(float readings[])
{
    char readingsArr[100] = {};
    char IsQuit = ' ';
    int size = 0;
    printf("\n--Enter Q to quit when finished--\n"); 
    while(IsQuit != 'Q' && (size < 10))
    {
        
        printf("Please enter temperature #%d: ", size+1);
        fgets(readingsArr, sizeof(readingsArr), stdin);
        IsQuit = toupper(readingsArr[0]);
        if(atof(readingsArr) != 0.0)
        {
            readings[size] = atof(readingsArr);
            size++;
        }
        else if(IsQuit != 'Q' && atof(readingsArr) == 0.0)
        {
            printf("Please enter a temperature\n");
        }
    }
    if(size == 0)
    {
        printf("No temperatures entered. Exting...\n\n");
    }
    else
    {
        printf("\nAll temperatures have been receieved!\n\n");
    }
    
    return size;
}

void isInRange(float readings[], int ranges[], int size)
{
    for(int i = 0; i < size ; i++)
    {
        if(readings[i] < 68 || readings[i] > 76)
        {
            ranges[i] = 0;
        }
        else
        {
            ranges[i] = 1; 
        }
    }
}

void DisplayStatus(float readings[], int ranges[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(ranges[i] == 1)
        {
            printf("%2.1fF\tNORMAL\tOFF\n", readings[i]);
        }
        else
        {
            printf("%2.1fF\tWARNING\tON\n", readings[i]);
            gpioWrite(PIN, 1); //LED ON
        }
    }
}

float calculatAverages(float readings[], int size)
{
    float total = 0; 
    for(int i = 0; i < size; i++)
    {
        total+= readings[i];
    }
    return total / size;
}
