/*
 * Author:                 Yufan_Xu
 * Assignment Title:       Caesar Cipher
 * Assignment Description: This program will first ask the user to input the
                           file name, and then ask the user to input 'decrypt'
                           or 'encrypt'. If the user entered the incorrect file
                           name, the program will display an error message and
                           then exit, if the user did not enter 'decrypt' or
                           'encrypt' at the second step, same thing happens.
                           If the user done the first two steps correctly, the
                           program will display whether decrypted words or
                           encrypted words, depends on which one was entered.
                           Then, the program will write the result to the output
                           file named 'message'
 * Due Date:               9/27/2016
 * Date Created:           9/27/2016
 * Date Last Modified:     9/27/2016
 */

/*
 * Data Abstraction:
 * 		data file is opened by the user's input
 *          the decrypted and encrypted words are read by the program
 * Input:
 * 		The user inputs whether 'decrypt' or 'encrypt' to let the program
 *          display the decrypted words or encrypted words of the opened file.
 *          In addition, before the user enter these, the user should first
 *          enter the correct file name into this program
 * Process:
 * 		If the user entered the invalid file name to the program, the program
 *          will display an error message, same thing happens if the user did
 *          not enter the 'decrypt' or 'encrypt' after entered the file name.
 *          If the user entered correct file name and entered 'decrypt', the
 *          program will then display the decrypted words of that file. If the
 *          user entered 'encrypt' afterwards, the program will display the
 *          encrypted words of that file. After this step, the program will
 *          read the output to the output file
 * Output:
 * 		The decrypted words or encrypted words are displayed and read to the
 *          output file
 * Assumptions:
 * 		It is assumed that the user only wants the decrypted or encrypted words
 *          for that file
 * 		It is assumed that the user only wants real output of that file
 * 		It is assumed that, having been prompted to do so,
 *          the user will correctly input the data
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{   int i;
    string line;
    char command[100];
    char fname[100];
    cout << "Enter File Name: "; //ask for input file name
    cin >> fname;
    
    cout << "Enter encrypt or decrypt: "; //ask for the command
    cin >> command;
    
    ifstream infile (fname);
    ofstream outfile;
    outfile.open ("message"); //open output file
    
    if(infile.good()) //suppose the input file exists
    {
        if(strcmp(command,"encrypt") == 0) //if user wants encrypt
        {
            while(getline(infile,line)) //for the each line in input file
            {
                int line_size = 64;
                for(i = 0; i < line_size; i++)
                line[i] = line[i] + 3;   //shift three places to the right
                outfile << line << endl; //print to the output file
            }
               
        }
        else if(strcmp(command,"decrypt") == 0)
        {
            while(getline(infile,line)) //for each line in input file
            {
                int line_size = 64;
                for(i = 0; i < line_size; i++)
                    line[i] = line[i] - 3;
                outfile << line << endl; //print to the output file
            }
        }
        else
        {
            cout << "Error: Bad Command." << endl;
            //display error message if command is invalid
            return 0; //end the program
        }
    }
    else
        cout << "Error: File did NOT open." << endl;
        //display error message if file cannot be opened
    
        return 0; //end the program
}