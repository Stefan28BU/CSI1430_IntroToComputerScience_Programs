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
 *            Two integers are entered into the program that are Gs1 and Gs2,
 *                  the system automatically selected a random number
 * Input:
 *            Two integers entered by the user in order to form a region of
 *                  random numbers, then the user need to enter a integer
 *                  which is the number guessed by the user
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

#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <ctime> /* time */
using namespace std;

int main()
{
    int n, lower, upper, count = 0;;
    cout << "Enter lower bound: ";
    cin >> lower;
    cout << "Enter upper bound: ";
    cin >> upper;
    /* initialize random seed: */
    srand (time(NULL));
    int randNum = rand() % (upper-lower) + lower;
    
    cout<<"I’m thinking of a number between "<<lower<<" and "<<upper<<"."
    <<endl;
    while(true){
        cout<<"Is it ? ";
        cin >> n;
        count++;
        if(n > randNum){
            cout<<"Too high."<<endl;
        }
        else if(n < randNum){
            cout<<"Too low."<<endl;
        }
        else{
            cout<<"Correct, it took you "<<count<<" tries to guess my number."
            <<endl;
            break;
        }
    }
    return 0;
}


