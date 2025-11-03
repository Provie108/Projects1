#Student Name: Providence Obiozor
#Student Code: C20499732
#LabTest1: The Following code is a problem solving game, based of the "Conundrum Code". The user will be asked to enter a 3 digit code
#In attempts to guess a random 3 digit code created by the program. The user will be given a max amount of guesses before they have to restart or
#End the game. In the users attempts to guess this code there will given hints on whether the postitioning of the digit they entered is correct.
#And whether or not the digit entered matches any digits in the code generated
import random

# Part 1: Generate the secret code
#Following. function will create a random code consisting of 3 digits
def generate_code():
    return str(random.randint(0, 999)).zfill(3)  # zfill adds leading zeros if necessary

# Part 2: Get user input for the guess
def get_user_guess():
    while True:
        #Defines the variable guess
        guess = input("Enter your three digit guess: ")
        #Checks if users guess is in digits and will also check the len the of guess to consits of 3 numbers
        if guess.isdigit() and len(guess) == 3:
            #Return value of guess to the main code and we can use this values in other functions
            return guess
        #If guess doesnt meet the criteria to be considered a "Guess" prunt the following to output
        else:
            print("Invalid input. Please enter a three digit number.")

# Part 3: Provide hints for the user's guess
#Code takes two parameters and compares the two with one another
def provide_hints(code, user_guess):
    #Use a list called hints, reason where using a list is we can use it to print different strings as well as compare the indexs so
    #Each hint can match the guesses relatively
    hints = []
    #Go through the range 0 -2(Matches our code being 3 digits)
    for i in range(3):
        #Compare each value of i to its index between the user guess and the code generated
        if user_guess[i] == code[i]:
            #If they match well add "Bullseye" the list
            hints.append("BULLSEYE")
        #If the number is in the code generated we notify the user that they were Off Target
        elif user_guess[i] in code:
            hints.append("OFF-TARGET")
        #And if the number guessed isnt in the code generated, notify that user with NUll
        else:
            hints.append("NULL")
    return hints

# Part 4: Check game results
#Function will take two parameters, compare the two and make a judgement on the status of the game.
def check_game_results(attempts, max_attempts):
    #If the attempts taken equal/Greater than the max attempts Print the following
    if attempts >= max_attempts:
        print("Sorry, you've reached the maximum number of attempts. The secret code was: " + code)
        return "lose"
    #If the users guess matches the generated code, Print the following
    elif user_guess == code:
        print("HURRAY! You've guessed the secret code: " + code)
        #Value of function will = continue/Win and we can use this value for something else
        return "win"
    else:
        return "continue"

# Part 5: Ask if the user wants to play again
def play_again():
    #While play again is true we'll as the user the following
    while True:
        #Defining the variable choice
        choice = input("Do you want to continue ? (yes/no): ").lower() #Change user input to lowercase for error checkung
        if choice == "yes":
            #Return value of play again function is true
            return True
        elif choice == "no":
            #Return value of function is false
            return False
        #Error checking
        else:
            print("INVALID INPUT. Please enter 'yes' or 'no'.")

# Main game logic
play_game = True
#While value of play game is true do the following
while play_game:
    #Runs function generate code
    code = generate_code()
    #Defines max attempts and attempts variable to be used in other function
    max_attempts = 10
    attempts = 0

    while True:
        #Defines variable user guess and runs the function to get the guess
        user_guess = get_user_guess()
        #Defines variable hints and runs hints function which takes previous variables code and user guess
        hints = provide_hints(code, user_guess)
        print("Hints:", hints)
        #Runs check game results function which uses previous variables attempts and max attempts
        game_results = check_game_results(attempts, max_attempts)
        #if check game results returns "contunue" we'lll continure game and attempts taken will be incremented by 1
        if game_results != "continue":
            break
        attempts += 1

    play_game = play_again()