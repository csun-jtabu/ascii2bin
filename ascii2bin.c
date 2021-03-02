
/********************************/
/* Program Name: ascii2bin.c    */
/* Author: Jaztin Tabunda       */
/* Date: 2/25/2021              */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[], char ** envp)
{
        char ascii_value = 0;
        char offset = 0x30;                  //0x30  //48
        char digit = 0;
        unsigned int number = 0;
        int retval;

        retval = read(0, &ascii_value, 1);
        
            while (retval == 1)
            {
                if(ascii_value == 0x30 || ascii_value == 0x31) //if statement - UNLESS the ascii_value is 48 or 49
                {                                              //the program will set the retval = 0 to exit the loop
                    //printf("%d\n", ascii_value);             //Alt. meaning: Loop is terminated if not "1" or "0"
                    digit = ascii_value - offset;
                    number = (number << 1) + digit;         //number << 1 + digit //number * 2 + digit
                    retval = read(0, &ascii_value, 1);  
                }
                else
                {
                        retval = 0;    
                }
                //printf("%d\n", digit);
            }
            //printf("%d\n", ascii_value);
        
    if(ascii_value == 0x30 || ascii_value == 0x31 || ascii_value == 0x0a)
    {
        printf("%u\n", number);
        return 0;
    }
    return 1;



}
