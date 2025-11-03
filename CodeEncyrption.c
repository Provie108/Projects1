/*

Assigment Project: Creating a program which will encrypt and decrypt code and match the encrypted code with the access code ,
The program should also allow the user to see number of succesfull and failed attempts when it comes to matching the encrypted and access code
Author :Providence Obiozor
Student No: C20499732
Compiler: Virtual Studio Code

*/
#include <stdio.h>

#define SIZE 4

// function signature
int case1(int *, int *);
int case2(int *, int *, int *, int *, int *, int * );
int case3(int *, int *);
int case4(int *, int *);
char case5(char *);

int main()
{

    // comment here
    //Variable used to exit code
    char exit = 0;
    //Variable used to run our program
    char menu = 0;
    // This variable will let our program know the entered code doesnt match the authorised code or if it does match the code
    int wrong = 0;
    //This variable will count how many times the users entered code doesnt match the authorised code
    int wrongcounter = 0;
     //This variable will count how many times the users entered code matches the authorised code
    int correctcounter = 0;
    //The array for the access code
    int accesscode[SIZE] = {4,5,2,3};
    //The array for the entered code
    int usrcode[SIZE];
    //This will act as an enabler for the encryption option
    int encryption_enabled = 0;
    //This will act as an enabler for the decryption option
    int decryptin_enabled = 0;
    

    // This while loop will run our menu
    while(exit == 0)
    {
        //This will print out ur menu options
        printf("Select a menu option: \n1. enter code \n2. encrypt and verify \n3. decrypt \n4. statistics \n5. exit \n");
        //This will read our entered menu option
        scanf("%c", &menu);
        //clears input buffer
        while (getchar() != '\n');

        // Register our menu options to the program
        switch(menu)
        {

            // First case will call out our first function
            case '1':
            {
                // cWill call out our first functions and save any changed values to our main
                case1(usrcode, &encryption_enabled);
                break;
            }

            // Second case will call out our Second function
            case '2':
            {
                // Will call out our first functions and save any changed values to our main
                  case2(usrcode, accesscode, &wrongcounter, &correctcounter, &encryption_enabled, &decryptin_enabled);
                break;
            }

            // Third case will call out our Third function
            case '3':
            {
                //  Will call out our third functions and save any changed values to our main
                 case3(usrcode, &decryptin_enabled);
                break;
            }

            // Fourth case will call out our fourth function
            case '4':
            {
                // Will call out our fourth functions and save any changed values to our main
                case4(&correctcounter, &wrongcounter);
                break;
            }

            // Fifth case will call out our fifth function
            case '5':
            {
                // Will call out our fifth functions and save any changed values to our main
                exit = case5(&exit);
                break;
            }

            // Will be the default case for any unregistered numbers entered 
            default:
            {
                //Will print this default message to standard output
                printf("ERROR INVALID SELECTION\n");
            }

        }
    }

    return 0;
}

// Our Function will ask the user to enter a code 
int case1(int *usrcode, int *encryption_enabled)
{
    int i = 0;
    //print a message to tell user to enter PIN
    printf("\n YOU HAVE ENTERED OPTION 1 PLEASE THE 4 DIGIT PIN (ENTER AS FOLLOWS: DIGIT-> ENTER KEY) \n");

    //For loop that will run through the array PIN the user entered
    for(i = 0; i < SIZE; i++)
   {
       //What will be used to register each digit in the PIN
       scanf("%1d", &usrcode[i] );
       while (getchar() != '\n');
 
   }
    // Prints code to Standard Output
    printf("\n ENTERED CODE\n");

    //For loop that will run through the array PIN the user entered
    for(i = 0; i < SIZE; i++)
   {
        //Will print PIN to Standard Output
          printf(" %d \n", usrcode[i]);

 
   } // end for
   
   //This is how we allow the user to use option2
   *encryption_enabled = 1;
 
}

// Second Function which will encrypt the users entered code
int case2(int *usrcode, int *accesscode,  int *wrongcounter, int *correctcounter, int *encryption_enabled, int *decryption_enabled)
{
    //Starting our function with an if statement as if the encryption 
    if(*encryption_enabled == 1)
    {
        //This will allow the user to access the decryption option
        *decryption_enabled = 1;
        int i = 0;
        int temp1;
        int temp2;
       
        //the following lines of code is how the encryption algorithm will be worked
        temp1 = usrcode[0];
        usrcode[0] = usrcode[2];
        usrcode[2] = temp1;
        temp2 = usrcode[1];
        usrcode[1] = usrcode[3];
        usrcode[3] = temp2;
        int wrong = 0;
    
        //for loop that will  run through the entered code
       for(i = 0; i < SIZE; i++)
         {
             //This will add 1 unit to each digit
            usrcode [i]=  1 + usrcode[i];
            
            //if statment that will switch any digit of the value 10 with zero
            if (usrcode[i] >= 10)
            {
                usrcode[i] = 0;
            }
 
        } 


        //prints following message to the user
        printf("ENCRYPTED CODE:\n");

        //for loop will run through entered code
        for(i = 0; i < SIZE; i++)
        {
         //Will print the entered code to Standard Output
          printf(" %d \n", usrcode[i]);

 
        }
        //Will print the following message to Standard Output
        printf("ACCESS CODE\n");

        //For loop will run through access code
        for(i = 0; i < SIZE; i++)
        {
        
          //Prints accesscode to Standard Output  
          printf(" %d \n", accesscode[i]);

         }
 
   
        //For loop will run through entered code
        for(i = 0; i < SIZE; i++)
        {
            
            //if statement that will register if code enters matches access code
            if(usrcode[i] != accesscode[i])
            {  
                
                wrong = 1;
                 
            }
            else if(usrcode[i] == accesscode[i])
            {
                 wrong = 2;
            }
    
  
        }

        //if wrong has value of 1 do the following
        if (wrong == 1 )
         {
             //Prints following message to Standard Output
              printf("ENTERED CODE DOES NOT MATCH ACCESSCODE\n");

              //Counts number of Failed attemps
             *wrongcounter = *wrongcounter + 1;
         }

         //if wrong has value of 2 do the following
        else if (wrong == 2)
        {
            //Prints following message to Standard Output
            printf("ENTERED CODE MATCHES ACCESS CODE\n"); 
            printf("CODE AUTHORISED\n");

            //Counts number of Successful attemps
            *correctcounter = *correctcounter + 1;
        }

   
    }

    //If Statment  to disable encryption option
    else if (*encryption_enabled == 0)
    {
        //Prints following message to Standard Output
        printf("NO NEW CODE HAS BEEN RECOGNISED\n");

    }

    //This will disable the encryption option
    *encryption_enabled = 0;
 
}

// Third function which will Decrypt the entered code
int case3(int *usrcode, int *decryption_enabled)
{

    //If statement to run following code if decryptions has been enabled
    if(*decryption_enabled == 1)
    {
        int i = 0;
        int temp1;
        int temp2;

        //Following lines of code play as the decryption algorithm
        temp1 = usrcode[0];
        usrcode[0] = usrcode[2];
        usrcode[2] = temp1;
        temp2 = usrcode[1];
        usrcode[1] = usrcode[3];
        usrcode[3] = temp2;
        
        
        //For loop will run through entered code
        for(i = 0; i < SIZE; i++)
        {
            //This will subtract 1 unit from each digit entered
            usrcode [i]=  -1 + usrcode[i];
            //if statement which will turn any entered code of value -1 to 0
            if (usrcode[i] <= -1)
            {
                usrcode[i] = 0;
            }
    
        } 


        //Prints following message to Standard Output
        printf("DECRYPTED CODE:\n");

        //For loop will run through entered code
        for(i = 0; i < SIZE; i++)
        {
            //Prints following message to Standard Output
            printf(" %1d \n", usrcode[i]);

    
        }

    }
    //Else if statment to run if decryption option has been disabled
    else if(*decryption_enabled == 0)
        {
            //Prints following message to Standard Output
            printf("ERROR NO ENCRYPTYED CODE FOUND\n");
        }

        //This will disable the decryption option
        *decryption_enabled = 0;
}

// Function to print successfull and failed attempts
int  case4(int *correctcounter, int *wrongcounter)
{
    //Prints following message to Standard Output
    printf("FAILED ATTEMPTS: %d\n", *wrongcounter);

    //Prints following message to Standard Output
    printf("SUCCESSFULL ATTEMPTS: %d\n", *correctcounter);


}

// Exit Program
char case5(char *exit)
{
     printf("BYE BYE\n");
    return 1;
}