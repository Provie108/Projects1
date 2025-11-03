/******************************************************************************
 * This program is designed to replicate the basic system of an ATM
 * The features of this ATM will alow;
 *  the user to verify their PIN 
 *  change their PIN
 * Display to standard output the number of times the user has entered their PIN successfully and incorrectly
 * The program should allow for error checking if the user enters the wrong PIN or invslid characters.
 * The program should only close when the user decodes theyre finish with the program
 * 
 * compiler used: Visual Studio Code
 * Author: Providence Obiozor

*******************************************************************************/

#include <stdio.h>

int
main ()
{
  int pin1 = 1;			//Pin represents our current pin digits
  int pin2 = 2;
  int pin3 = 3;
  int pin4 = 4;
  int npin1;
  int npin2;
  int npin3;
  int npin4;
  int exit1;			// Will behave as an on/off switch if exit is assigned to a certain value teh prgram will back out to the menu
  int success = 0;
  int failed = 0;
  int sum = 0;
  char error1;
  char choice;			// variable used to display our options entered 
  int ent1;			// the ent variable represents the charecter which has been entered
  int ent2;
  int ent3;
  int ent4;
  int end = 0; //This end variable will work similarly to our exit variable when it is assigned to a certain value it will end our program

    do
        {
        //The following code display our menu to standard output
        printf ("WELCOME TO THE ATM SERVICE\n");
        printf ("1. ENTER AND VERIFY PIN\n");
        printf ("2. CHANGE PIN\n");
        printf ("3. NUMBER OF FAILLED AND SUCCESSFULL PIN ATTEMPTS\n");
        printf ("4. END PROGRAM\n");
        printf ("PLEASE ENTER ONE DIGIT AS THIS ATM HAS BEEN DESIGNED TO DISCARD EVERY DIGIT AFTER THE FIRST ONE\n");
        printf ("ENTER YOUR CHOICE\n");
        scanf ("%s", &choice);	// depending on the number entered will determine which feature the ATM will run
        


        //I used a switch statement here instead of an if as it is more efficient 
        switch (choice)
        {
        //case'' = if the user inputs '' {then do}
        case '1':
            exit1 = 1; //in all our cases we will assign exit1 any number bar 0 as once exit1 becomes 0 the case funtion should end
            printf ("\nENTER YOUR PIN\n");
            // here the ATM will ask for the current pin again the ent variable represents the digits entered
            scanf ("%1d %1d %1d %1d", &ent1, &ent2, &ent3, &ent4);
            //This getchar code will be displayed underneath a number scanf's this will be used as validation for special charecters and letters
            while (getchar () != '\n');

            if (ent1 == pin1 && ent2 == pin2 && ent3 == pin3 && ent4 == pin4)	//This if statement basically states if the digits entered and the same value as the current PIN the do the following. This code will be used throughout the program
                {
                success = success + 1;	//first thing will be our successful PIN counter will go up by one
                printf ("VERIFY PIN\n");
                ent1 = 0; 
                ent2 = 0;
                ent3 = 0; 
                ent4 = 0;
                scanf ("%1d %1d %1d %1d", &ent1, &ent2, &ent3, &ent4); while (getchar () != '\n');

                if (ent1 == pin1 && ent2 == pin2 && ent3 == pin3 && ent4 == pin4)
                    {
                    success = success + 1;	// once pin has been verified counter will go up again by 1
                    printf ("VERIFIED\n");
                    }

                else
                    {
                    failed = failed + 1;	// if not failed counter will go up by one if we fail to verify PIN
                    printf ("FAILED TO VERIFY PIN\n");
                    }


                }
            else
                {
                failed = failed + 1;	// if not failed counter will go up by one if we fail to verify PIN
                printf ("INCORRECT PIN\n");
                }

            printf ("ENTER 0 TO RETURN TO MENU\n");
            scanf ("%1d", &exit1);	//This is the code that will return the user back to the menu it will be displayed a number of times in this program

            if (exit1 == 0) //This code will be displayed throughout the code and it tells our program that if the variable exit is assigned the value 0 the we will end the program
                {
                printf ("RETURNING TO MENU\n");
                }

            else
                {
                printf ("INVALID KEY WAS ENTERED ENTER 0 TO RETURN TO MENU\n");
                scanf ("%1d", &exit1);
                }
                
        break;


        case '2':

            printf ("TO CHANGE PIN ENTER PREVIOUS PIN\n");
            scanf ("%1d %1d %1d %1d", &ent1, &ent2, &ent3, &ent4);
            while (getchar () != '\n');

            if (ent1 == pin1 && ent2 == pin2 && ent3 == pin3 && ent4 == pin4)
                {
                success = success + 1;
                printf ("ENTER NEW PIN\n");
                scanf ("%1d %1d %1d %1d", &npin1, &npin2, &npin3, &npin4);	// Now here the program will now assign new values to the NPIN(new pin) this is how we will change our PIN
                while (getchar () != '\n');
                printf ("RE-ENTER NEW PIN\n");
                scanf ("%1d %1d %1d %1d", &ent1, &ent2, &ent3, &ent4);	//After changing NPIN we will ask the user the user to enter the value  of our nPIN (This will behave as a temporary variable)
                while (getchar () != '\n');
                if (ent1 == npin1 && ent2 == npin2 && ent3 == npin3  && ent4 == npin4)
                {
                    //if the npin values are entered correctly we will assign the new pin values to our current pin
                    pin1 = npin1;	
                    pin2 = npin2;
                    pin3 = npin3;
                    pin4 = npin4;
                    exit1 = 1;
                    success = success + 1;
                    printf ("PIN CHANGED\n");
                    printf ("ENTER O TO RETURN TO MENU\n");
                    scanf ("%d", &exit1);

                    if (exit1 == 0)
                        {
                        printf ("RETURNING TO MENU\n");
                        }

                    else
                        {
                        printf ("INVALID KEY WAS ENTERED ENTER 0 TO RETURN TO MENU\n");
                        scanf ("%d", &exit1);
                        }
                }

                else
                    {
                    printf ("FAILED TO CHANGE Pin ENTER 0 TO RETURN TO MENU\n");
                    scanf ("%d", &exit1);
                    while (getchar () != '\n');
                    }
                }

            else
                {
                exit1 = 1;
                failed = failed + 1;
                printf ("INCORRECT PIN\n");
                printf ("ENTER 0 TO RETURN TO MENU\n");
                scanf ("%d", &exit1);
                while (getchar () != '\n');

                if (exit1 == 0)
                    {
                    printf ("RETURNING TO MENU\n");
                    }

                else
                    {
                    printf ("INVALID KEY WAS ENTERED ENTER 0 TO RETURN TO MENU\n");
                    scanf ("%d", &exit1);
                    while (getchar () != '\n');
                    }
                }
        break;

        case '3':
        
            sum = success + failed;
            printf ("IN TOTAL PIN WAS ENTERED\n");
            printf ("%d TIMES\n", sum);	//Sum variable is both our failed counter and successful counter added togehter
            printf ("PIN WAS ENTERED SUCCESSFULLY \n");
            printf ("\n %d TIMES\n", success);
            printf ("PIN WAS ENTERED INCORRECTLY\n");
            printf ("\n%d TIMES\n", failed);

            if (failed > success)	//This if statement is just a recomendation function if the user fails to enter their PIN more times than successfull 
                {
                printf ("WE RECOMMEND YOU TO CHANGE YOUR PIN\n");	//The ATM should recommend to the user to change their pin
                }

            printf ("ENTER 0 TO RETURN TO MENU\n");
            scanf ("%d", &exit1);
            while (getchar () != '\n');

            if (exit1 == 0)
                {
                printf ("RETURNING TO MENU\n");
                }

            else
                {
                printf ("INVALID KEY WAS ENTERED ENTER 0 TO RETURN TO MENU\n");
                scanf ("%d", &exit1);
                }

        break;

        case '4':
            printf ("THANKS FOR USING ATM");
            end = 4; //This how we will use our end variable. Once the use inputs the number 4 it will assign that value to our end variable 
            break;

            default:
            exit1 = 1;

            if (choice != 4)	//This will be the default function if the user enters anything else bar 1,2,3 or 4
                {
                while (getchar () != '\n');
                printf
                ("INVALID KEY WAS ENTERED\n");
                printf ("ENTER 0 TO RETURN TO MENU\n");
                scanf ("%d", &exit1);

                if (exit1 == 0)
                {
                printf ("RETURNING TO MENU\n");
                }

                else
                {
                printf ("INVALID KEY WAS ENTERED ENTER 0 TO RETURN TO MENU\n");
                scanf ("%d", &exit1);
                }

                }

        break;

        }



    fflush(stdin);
        }
    while (end != 4); //This how we will close our do while loop oce the our end variable is assigned the value 0. This stops the program from starting all over again
    printf ("\n\n THANKS FOR USING OUR ATM SERVICE");	// This will be closing ATM program



  return 0;

}
