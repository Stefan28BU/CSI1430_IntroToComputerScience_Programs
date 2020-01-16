/*
 * Author:                 Yufan_Xu
 * Assignment Title:       Class Average
 * Assignment Description: This assignment requires us to write a code that
                           will read the input file which includes all the
                           students' name and then read each student's file
                           in order to get their score. The program should
                           be able to calculate the average of each student's
                           score and the average of the class, and it also
                           calculates the maximun and the minimum score of
                           the students
 * Due Date:               10/11/2016
 * Date Created:           10/11/2016
 * Date Last Modified:     10/11/2016
 */

/*
 * Data Abstraction:
 *            Three integer values: i, plusT, stuNum
 *                  Seven double values: stuAvg, clasAvg, Max, Min, score, 
 *                  sum, classSum
 *                  Six string values: fname, frtN, midI, lasN, stuN, 
 *                  stuFileN
 *                  ifstream infile, ifstream stuFile
 * Input:
 *            The user will input the name of data file: fname
 * Process:
 *            This program will first ask the user to input the name of the
 *                  data file. If the file name is not correct, the program
 *                  will ask the same question for another three times, if
 *                  the user still entered the wrong name, the program will
 *                  display a different message to let the user think more
 *                  carefully about the file name. If the user entered the
 *                  correct file name, the program will open the file and 
 *                  then read the file of each student's scores with in the
 *                  original data file. Then, the program will calculate the
 *                  average score of each student and the average of class,
 *                  and the maximum and the minimum score of the class. Then,
 *                  the program will close the student file and the output 
 *                  will be displayed on the screen then close the data file
 * Output:
 *           The program will display the students' name, their average, and
 *                  the class average, and the maximum and the minimum score
 *                  on screen, if the student is not include in the file, the
 *                  program will display 'NO FILE EXISTS'
 * Assumptions:
 *           It is assumed that, the user will try to enter the correct file
 *                  name
 *           Assuming that all the equations and the logics are correct
 *           Assuming that the user only wants the maximun, minimum, class
 *                  average, student average
 */

#include <iostream>        //cout, cin
#include <fstream>         //open and close infile, stuFile
#include <string>          //fname, frtN, midI, LasN, stuN, stuFileN
#include <iomanip>         //setprecision
#include <climits>         //INT_MAX, INT_MIN

using namespace std;

int main()
{
    int i = 1;             //the time of entering file name
    int plusT = 0;         //the time of adding each student's score together
    int stuNum = 0;        //number of students
    double stuAvg = 0.0;   //average score of each student
    double clasAvg;        //average score of the whole class
    double high = INT_MIN; //highest score in class
    double low = INT_MAX;  //lowest score in class
    double score;          //single score of all students
    double sum = 0.0;      //the sum of each student's score
    double classSum;       //the total score of the class adding together
    string fname;          //the name of the data file
    string frtN;           //student's first nme
    string midI;           //student's middle initial
    string lasN;           //student's last name
    string stuN;           //student's full name
    string stuFileN;       //file name of each student
    ifstream infile;       //data file is ready
    ifstream stuFile;      //file of each student is ready
    
    //looping
    do
    {
        //ask user for file name
        cout << "Enter Name of Data File: ";
        
        //user input
        cin >> fname;
        infile.open(fname.c_str());
        
        //if the file name is wrong, the program will ask again
        if (infile.fail())
        {
            cout << "File open attempt #" << i
            << " unsuccessful - try again!\n";
        }
        i++;
    }
    while (i <= 3 && infile.fail());
    
    //suppose the user have entered wrong name for more than three times
    if (i >= 4 && infile.fail())
    {
        //spacing two lines on screen
        cout << endl;
        cout << endl;
        
        cout << "Exceeded maximum number of file opens - check file name.\n";
    }
    
    //suppose the user entered the correct file name within three times
    if (i <= 3 && infile)
    {
        //spacing two lines on screen
        cout << endl;
        cout << endl;
        
        //keep two decimal places
        cout << fixed << setprecision(2);
        
        //keep 24 character spaces including white spaces starting from left
        cout << setw(24) << left << "student Name" << "Average\n";
        
        //the program opened the data file
        while (infile >> lasN >> frtN >> midI)
        {
            //function of student file name
            stuFileN = frtN + lasN + ".dat";
            stuFile.open(stuFileN.c_str());
            
            //suppose the student file name is wrong
            if (stuFile.fail())
            {
                //function of the real student name
                stuN = frtN + " " + midI + " " + lasN;
                
                //keep 24 character spaces including white spaces starting
                //from left
                cout << setw(24) << left << stuN << "NO FILE EXISTS\n";
            }
            
            //suppose the file is opened
            else
            {
                //adding the number of students
                stuNum++;
                
                //read the score in each student's file
                while (stuFile >> score)
                {
                    //sum of each student's score
                    sum += score;
                    
                    //equation of each student's average
                    stuAvg = sum / 4.0;
                    
                    //sum of every score from every student
                    classSum += score;
                    
                    //determing the higgest score
                    if (score > high && plusT <= 3)
                    {
                        high = score;
                    }
                        
                    //determing the lowest score
                    else if (score < low && plusT <= 3)
                    {
                        low = score;
                    }
                    plusT++;
                }
                    
                //suppose more than three students' name in the file
                if (plusT > 3)
                {
                    sum = 0.0;
                    plusT = 0;
                }
                
                //function of student name
                stuN = frtN + " " + midI + " " + lasN;
            
                //keep 24 character spaces including white spaces starting
                //from left
                cout << setw(24) << left << stuN << stuAvg << endl;
            }
            
            //close the student file
            stuFile.close();
        }
        
        //spacing two lines on screen
        cout << endl;
        cout << endl;
        
        //equation of class average
        clasAvg = classSum / (4.0 * stuNum);
        
        cout << setw(24) << left << "Class Average: " << clasAvg << endl;
        cout << setw(24) << left << "Max Score: " << high << endl;
        cout << setw(24) << left << "Min Score: " << low << endl;
    }
    
    //data file closed
    infile.close();
    
    //program ended
    return 0;
}