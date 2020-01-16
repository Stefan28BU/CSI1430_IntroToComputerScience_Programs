/*
 * Author:                 Yufan_Xu
 * Assignment Title:       GPS
 * Assignment Description: This program will process a stream of GPS data, and
                           each line of data starts with a command and followed
                           by the data for that command
 * Due Date:               10/1/2016
 * Date Created:           10/1/2016
 * Date Last Modified:     10/1/2016
 */

/*
 * Data Abstraction:
 * 		if data file is opened
 *          17 variables are read by the program: x, y, x1, y1, x0, y0, X,
 *          Y, x2, y2, leth, totalD, distce, comd, fileN, lineOf, failtimes
 *      if data file is not opened
 *          ask user for valid file name for 3 times
 * Input:
 *      the user enter the name of the file as the input which can let the
 *          program reads the data file, and the user can try three times
 * Process:
 * 		If user entered a valid file name, the program will read the data of
 *          that particular file and then it will skip the first two lines in
 *          the file and then make the calculations of total distance, 
 *          final position, and the distance between the final point to the
 *          original point based on the remaining data
 *      If the user entered the invalid file name, the program will ask the user
 *          for three more times, and if the user still entered the wrong thing,
 *          the program will ends
 * Output:
 * 		The value of total distance, final position, and the distance between the
 *          final point and the starting point are calculated
 * Assumptions:
 * 		It is assumed that the user only wants to solve the requiring solutions in
 *          that particular file
 * 		It is assumed that the user only wants real solutions to the formula
 */

#include <fstream> //infile, outfile
#include <iostream> //cout, cin
#include <string> //string command, file name, lines skipped
#include <cmath> //mathmatic
#include <iomanip> //keep one decimal place
#include <cstdlib> // to exit the program

using namespace std;

int main()
{
    //variables, data abstraction (initialized variables)
    int failtimes = 0;
    double x = 0, x0 = 0, x1 = 0, x2 = 0;
    double y = 0, y0 = 0, y1 = 0, y2 = 0;
    double X = 0, Y = 0;
    double leth; //length
    double totalD = 0; //total distane traveled
    double distce = 0; //distance between initial point and final point
    string comd, fileN, lineOf; //command, file name, line of file
    
    ifstream infile; //input file
    ofstream outfile; //output file
    outfile.open("GPS.report"); //name of the outpput file
   
    do //supposing file name is correct
    {
        cout << "Please Enter The Name Of The Data File: \n" << endl;
        cin >> fileN;
        
        infile.open(fileN.c_str());
        failtimes = failtimes + 1; //do the steps again if failed
        
        if (!infile)
        {
            cout << "ERROR: File did NOT open - try again. \n" << endl;
        }
    }
    while (failtimes <= 3 && !infile); //do the steps again if failed
    
        if (failtimes >= 4)
        {
            cout << "STOP ENTERING INVALID FILE NAME!";
            exit(1); //ends the program if exceed limited times
        }
    
        getline(infile, lineOf); //skip the first line in file
        getline(infile, lineOf); //skip the second line in file
        
        while (infile >> comd >> x >> y)
        {
            if (comd == "START")
            {
                x0 = x;
                x1 = x;
                y0 = y;
                y1 = y;
            }
            else if (comd == "DATA")
            {
                x2 = x;
                y2 = y;
                x1 = x2;
                y1 = y2;
                leth = sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));
                totalD = totalD + leth;
            }
            else if (comd == "STOP")
            {
                X = x;
                Y = y;
                leth = sqrt(pow((X - x1), 2.0) + pow((Y - y1), 2.0));
                distce = sqrt(pow((X - x0), 2.0) + pow((Y - y0), 2.0));
                totalD = totalD + leth;
            }
            else
                cout << "Bad Command.\n";
        }
        
    cout << showpoint << setprecision(1); //keep one decimal place
    outfile << showpoint << setprecision(1);
 
    cout << "Final Location: " << "(" << X << ", " << Y << ")" << endl;
    outfile << "Final Location: " << "(" << X << ", " << Y << ")" << endl;
 
    cout << "Total distance traveled " << totalD << endl;
    outfile << "Total distance traveled " << totalD << endl;
 
    cout << "Distance to starting point " << distce << endl;
    outfile << "Distance to starting point " << distce << endl;
    
    infile.close();
    outfile.close(); //close the opened file
        
    return 0;
}
