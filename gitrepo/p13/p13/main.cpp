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
#include <fstream>
#include <string>
#include <iomanip>
#include <cfloat>

using namespace std;

int main()
{
    int plusT;
    int stuNum = 0;
    double stuAvg = 0.0 ;
    double clasAvg = 0.0;
    double Max = DBL_MIN;
    double Min = DBL_MAX;
    double score;
    double sum = 0;
    string fname;
    string frtN, midI, lasN;
    string stuFileN;
    ifstream infile;
    ifstream stuFile;
    
    cout << "Enter Name of Data File: ";
    
    cin >> fname;
    
    infile.open(fname.c_str());
    
    cout << fname << endl << endl;
    
    cout << left << setw(25) << "Student" << "Average" << endl;
    
    while (infile >> lasN >> frtN >> midI)
    {
        cout << fixed << setprecision(2);

        stuFileN = frtN + lasN + ".dat";
        
        stuFile.open(stuFileN.c_str());
       
        for (stuFile >> score; plusT <= 4; plusT++)
        {
            sum += score;
            stuAvg = sum / plusT;
    
            if (score > Max)
            {
                Max = score;
            }
            else if (score < Min)
            {
                Min = score;
            }
            cout << left << setw(25);
            cout << lasN << " " << midI << " " << frtN;
            cout << stuAvg << endl;
        }
        stuNum ++;
    }
        clasAvg += stuAvg;
    
        clasAvg = clasAvg / stuNum;
    
    cout << endl << endl;
    cout << "Class Average: " << clasAvg << endl;
    cout << "Max Score: " << Max << endl;
    cout << "Min Score: " << Min << endl;
    
    infile.close();
    stuFile.close();
        
    return 0;
    }
