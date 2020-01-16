/*
 * Author:                 Yufan_Xu
 * Assignment Title:       Guessing Game
 * Assignment Description: This assignment reqiures us to write a C++ program
                           to let the user try to guess the correct number that
                           randomly selected by the computer
 * Due Date:               10/4/2016
 * Date Created:           10/4/2016
 * Date Last Modified:     10/4/2016
 */

/*
 * Data Abstraction:
 *            Two integers are entered into the program that are upper number
 *                  and lower number, and the system automatically selected a 
 *                  random number (lowerI, upperI, n)
 * Input:
 *            Two integers entered by the user in order to form a region of
 *                  random numbers, then the user need to enter a integer
 *                  which is the number guessed by the user (lowerI, upperI, n)
 * Process:
 *            After the time that the two integers are entered, the program
 *                  will then randomly selected serious of integers based on
 *                  the biggest number and the lowset number entered by the
 *                  user, and then the program will ask the user to guess the
 *                  selected integer within the region. If the number entered
 *                  is too high or too low, the program will display the
 *                  relavent suggestion to the user in order to make the user
 *                  select the correct number, if the number is correct, the
 *                  program will tell you and display the number of tries on 
 *                  the screen
 * Output:
 *           The program will tell the user has already entered a correct
 *                  number that is seclected by the system and then display
 *                  the number of tries done by the user
 * Assumptions:
 *           It is assumed that, having been prompted to do so, the user will 
 *                  correctly input data within that region
 */

#include <iostream> //cin, cout
#include <cstdlib> // srand, rand

using namespace std;

int main()
{
    int n; //number you guessed
    int lowerI; //integer with small value
    int upperI; //integer with bigger value
    int count = 0; //initialized count times
    int randNum;// the random number selected by the system
    
    //ask for integers to determine the region
    cout << "Enter two integers: " << endl;
    
    //user input
    cin >> lowerI >> upperI;
    
    //initialize random seed
    srand ((unsigned)time(NULL));
    
    //to determine the region of random number
    randNum = rand() % (upperI - lowerI) + lowerI;
    
    //display the region on screen
    cout << "I’m thinking of a number between " << lowerI << " and " << upperI
    << " inclusive.\n" << endl;
    
    //looping
    while(true)
    {
        //ask for the number gussed
        cout << "Guess the number: ";
        
        //user input
        cin >> n;
        
        //count times increase one by one
        count++;
    
        //supposing the guessed number is greater than the random number
        if(n > randNum)
        {
            //display 'too high' in order to let the user input a smaller one
            cout << "Too high." << endl;
        }
        //supposing the guessed number is smaller than the random number
        else if(n < randNum)
        {
            //display 'too low' in order to let the user enter a greater one
            cout << "Too low." << endl;
        }
        //supposing the above conditions are false
        //the user entered the correct number
        else
        {
            //display the message that is telling the correction of user
            cout << "Correct, it took you " << count
            << " tries to guess my number." << endl;
            break;
        }
    }
    //program ended
    return 0;
}
//in testing this program, if I entered the number 35, 40, the program will
//display "I'm thinking of a number between 35 and 40 inclusive.". However,
//when I tested my program on the upload site, it displayed "I'm thinking of a
//number between 40 and 35 inclusive.". Then the following line is just infinite
//tries to guess the number and ever ended, and I don't know why that happens.
//So, if that is not my problem, hopefully my grade won't be cut critically.
//If it is my problem, I would like to know why.
//Thanks a lot!



