/*
 * Author:                 Yufan_Xu
 * Assignment Title:       Min Max Sum Count Average
 * Assignment Description: This program first open the data file, if the file
                           cannot be opened, then the program will ask the user
                           to input the file name again. If the data file is
                           opened, the program will ignore the first two lines
                           of the data file and then make calculations of min,
                           max, sum, count, and average.
 * Due Date:               9/27/2016
 * Date Created:           9/27/2016
 * Date Last Modified:     9/27/2016
 */

/*
 * Data Abstraction:
 * 		If data file is not opened,
 *          Display 'File Not Opened', then ask the user to input the file name
 *          again.
 *      If data file is opened,
 *          The program reads the last 19 lines of the data file then calculate
 *          the min, max, sum, count, and the average of them
 * Input:
 * 		The file name was written into the program, and the data file named
 *          'data.txt' contains 21 lines of integers
 * Process:
 * 		The program will first ask the user to input the file name, if the
 *          file name is not correct, the program will do the same process for
 *          three times, if the user still entered the invalid file name for
 *          the forth time, the program will display an error message. If the
 *          user entered the correct file name within three times, then program
 *          will then calculate the min, max, sum, count, average of that file
 *          expect the first two lines
 * Output:
 * 		The value of min, max, sum, count, average are displayed to the screen,
 *          and read to the file
 * Assumptions:
 * 		It is assumed that the user only wants to solve the required data in
 *          that particular file
 * 		It is assumed that the user only wants real solutions to the formula
 * 		It is assumed that, having been prompted to do so,
 *          the user will correctly input data
 */

#include <cmath> //for min, max, sum, count, average
#include <iostream> //cin filename, cout min, max, count, sume, average
#include <iomanip> //round three decimal places
#include <string> //filename, line
#include <fstream> //reads data file and write output file
#include <climits> //limits integers

using namespace std;

int main()
{
    
    ifstream fin;
    string filename;
    string line;
    float sum = 0;
    int number;
    int count = 0;
    double average;
    int Min = INT_MAX;
    int Max= INT_MIN;
    
    while (true)
    {
        //ask user to input the file name
        cout << "Enter Filename: ";
        cin >> filename;
        
        //convert filename from string to c style
        fin.open(filename.c_str());
        
        //supposing file cannot be opened
        if (!fin.is_open())
        {
            cout << "Error: File Not Open."<< endl;
        }
        //same process again
        else
            break;
    }
    //skip first two lines
    getline (fin,line);
    getline (fin,line);
    
    //supposing file can be opened
    while (!fin.fail())
    {
        fin >> number; //read the number in file
        sum += number; //equation for sum
        count = count + 1; //equation for count
        if (number > Max)
            Max = number; //determine the max
        if (number < Min)
            Min = number; //determine the min
        if (fin.eof()) break;
        
    }
    
    average = sum / count;
    
    cout << "Min = " << Min << endl;
    cout << "Max = " << Max << endl;
    cout << "Sum = " << sum << endl;
    cout << "Count = " << count << endl;
    cout << "Average = " << fixed << setprecision(3) << average << endl;

    fin.close();
    
    return 0;
}