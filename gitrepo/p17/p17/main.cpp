/*
 * Author:                 Yufan_Xu
 * Assignment Title:       Awesome Square
 * Assignment Description: This assignment reqiures us to write a C++ program
 to let the user try to guess the correct number that
 randomly selected by the computer
 * Due Date:               3/23/2017
 * Date Created:           3/23/2017
 * Date Last Modified:     3/23/2017
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

using namespace std;

int main()
{
    bool flag = true;
    ifstream file;
    string filename;
    int total = 0;
    int C;
    int N;
    int sum = 0;
    int number;
    
    do
    {
        cout << "Enter name of file: ";
        
        cin >> filename;
        
        file.open(filename.c_str());
        
        cout << filename << endl;
        
        if (!file)
        {
            cout << "Invalid file." << endl;
        }
        
    }while (file.fail());
    
    while (file >> C)
    {
        while (C --)
        {
            file >> N;
        
            for(int i = 1;i <= N;i++)
            {
                for(int j = 1;j <= N;j++)
                {
                    file >> number;
                    total += number;
                }
                
                if(i == 1)
                {
                    sum = total;
                }
                
                else if(total != sum)
                {
                    flag = false;
                }
            }
            
            if (flag == true)
            {
                cout << "Awesome" << endl;
            }
        
            else
            {
                cout << "Not Awesome" << endl;
            }
            flag = true;
     
        }
    }
    file.close();
    
    return 0;
}