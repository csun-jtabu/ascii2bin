
/********************************/
/* Program Name: ascii2bin.c    */
/* Author: Jaztin Tabunda       */
/* Date: 2/25/2021              */
/********************************/
/* Description:                 ******************************************************************************/
/* This program takes in a binary number and reads each individual bit as an ascii value. The ascii value is */
/* then used to be converted back into a binary bit. After being converted back into binary, the program     */
/* converts the binary number into its decimal form.                                                         */  
/*                                                                                                           */
/* Validation Checks:                                                                                        */
/* - Each ASCII input character is one of the following characters: '0', '1', or '\n'                        */
/* - The calculated number does not exceed 2^32                                                              */
/* -                                                                                                         */
/* Enhancements:                                                                                             */
/* - Made the program state what's the problem with the input. (Not a 1 or 0 / Exceeds 2^32)                 */
/*************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main (int argc, char * argv[], char ** envp)
{
        const char MAX_POWER = 32; 
        
        char count = 0; 
        char ascii_value = 0;
        char offset = 0x30;                  //0x30 = 48
        char digit = 0;
        unsigned int number = 0;  
        int retval = 0;
        
        retval = read(0, &ascii_value, 1); //1. exercises the read() system call to read a single byte, at a time, from stdin
        
            while (retval == 1)
            {
                                                                    //2. validate that the read byte is appropriate for conversion, e.g., it must be either an ASCII '0' or '1'
                if(ascii_value == 0x30 || ascii_value == 0x31)      //if statement - Loop is terminated if not "1" or "0".
                {                                                   //This leads to the end of the program too.
                    count++;                   
                    digit = ascii_value - offset;                   //3. converts each byte into an integer value via a mathematical expression
                    number = (number << 1) + digit;                 //4. uses the resulting integer as part of the calcuation to determine the final number
                    retval = read(0, &ascii_value, 1);  
                }
                else                                                //5. identifies the end of a input string by either end of file or by a new line
                {                                                   //The program exits the loop and stops reading values if
                        retval = 0;                                 //End of file is detected when read() returns the value '0' or
                }                                                   //A new line is identified in the ASCII table as either: newline, nl, LF, or \n'
                                                                    //The loop also exits when the value is not "1" or "0", but diverges later (as seen in the next if statement) and gives an error
            }
            
        
    if((ascii_value == 0x30 || ascii_value == 0x31 || ascii_value == 0x0a) && MAX_POWER >= count) //7. returns a value of 0 upon success and 1 otherwise
    {   
        printf("%u\n", number);                                 //6. prints this final number on stdout
        return 0;                                               
    }                                                           
    else                                        
    {                                           
        if(MAX_POWER < count)                                           //Makes sure the calculated number does not exceed 2^32  
        {                                                               //(Validation is here, but unnecessary since unsigned int forces the max to be 2^32)
            printf("Sorry, the number calculated exceeds 2^32. " 
            "Please enter a binary number that doesn't exceed 2^32. \n");
        }
        else                                                            //Makes sure each ASCII input character is one of the 
        {                                                               //following characters: '0', '1', or '\n'
            printf("A number that is not a 1 or 0 has been entered. " 
            "Please enter a number in binary with only 1s and 0s. \n");
        }
        return 1;                                           
    }

}
