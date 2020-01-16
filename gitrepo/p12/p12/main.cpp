/*
 * Author:                 Yufan_Xu
 * Assignment Title:       Multiplication Table
 * Assignment Description: This assignment asks the user to input 4 integers
                           and then generates a multiplication table that 
                           shows the multiplied number inclusive and print
                           the result on an output file and close the file
 * Due Date:               2/28/2017
 * Date Created:           2/28/2017
 * Date Last Modified:     2/28/2017
 */

/*
 * Data Abstraction:
 *            Four integers entered by the user that are R1, R2, C1, C2, and
 *                integer i and integer j that are the count times of R1, R2
 *                and C1, C2 inclusive, one output file 'outfile' is named
 * Input:
 *            The user inputs the value of R1, R2 C1, C2 in order to determine
 *                the range of the integers that multiplied by the program
 * Process:
 *            The program will first ask the user to enter four integers that
 *                are R1, R2 C1, C2, in order to get the range of the mul-
 *                -tiplication table. After that, the program will display
 *                the table with the following integers that suppose to be
 *                multiplied and printed it on the output file as well
 * Output:
 *           The multiplication table is both displayed on screen and written
 *                to the output file
 * Assumptions:
 *           It is assumed that, having been prompted to do so, the user will
 *                finally input integers to the program
 *           Assumes that the user only wants the integers to be multiplied
 *                within that range
 */

#include <iostream> //cin, cout
#include <iomanip> //setw
#include <fstream> //outfile

using namespace std;

int main()
{
    int R1, //first input
        R2, //second input
        C1, //third input
        C2; //last input
    
    ofstream outfile; //output file
    
    //ask user for input
    cout << "Enter 4 integers: ";
    outfile << "Enter 4 integers: ";
    
    cin >> R1 >> R2 >> C1 >> C2; //user input
    
    //print the user input
    cout << R1 << " " << R2 << " " << C1 << " " << C2 << endl;
    outfile << R1 << " " << R2 << " " << C1 << " " << C2 << endl;

    outfile.open("HandOut.txt"); //open the output file
    
    //keep three white spaces on screen at the begining of the first line
    cout << "   ";
    
    //keep three white spaces on output file at the begining of the first line
    outfile << "   ";
    
    for(int i = C1; i <= C2; i++) //looping
    {
        //keep six character places on screen in total
        cout << setw(6) << i;
        
        //keep six character places on the output file in total
        outfile << setw(6) << i;
    }
    
    cout << endl; //spacing a line on screen
    outfile << endl; //spacing a line on output file
    
    for(int i = C1; i <= C2 + 1; i++) //looping
    {
        cout << "-----|"; //display one screen
        outfile << "-----|"; //write the output file
    }
    
    cout << endl; //spacing a line on screen
    outfile << endl; //spacing a line on output file
    
    for(int i = R1; i <= R2; i++) //looping
    {
        cout << i; //display the integers on screen within the range
        outfile << i; //write the integers to file within the range
        
        //keep two white spaces on screen at the begining of the following line
        cout << "  ";
        
        //keep two white spaces on screen at the begining of the following line
        outfile << "  ";
        
        for(int j = C1; j <= C2; j++) //looping
        {
            cout << setw(6) << i * j; //six spaces in total on screen
            outfile << setw(6) << i * j; //six spaces in total to file
        }
        
        cout << endl; //spacing a line on screen
        outfile << endl; //spacing a line to file
        
        for(int i = C1; i <= C2 + 1; i++) //looping
        {
            cout << "-----|"; //display on screen
            outfile << "-----|"; //write to file
        }
        
        cout << endl; //spacing a line on screen
        outfile << endl; //spacing a line to file
    }
    
    outfile.close(); //close the output file
    return 0; //program ended
}

