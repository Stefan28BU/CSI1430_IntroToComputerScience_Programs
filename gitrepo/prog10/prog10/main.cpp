/*
 * Author:                 Yufan Xu
 * Assignment Title:       GPS
 * Assignment Description: This program will first prompt the user for an
                           input file name, and then open the file if the
                           file exists, then the program will skip the 
                           first two lines and reads the data in the file,
                           then the program will calculates the total 
                           distance that the point traveled and the 
                           distance between the starting point and the end
                           point, then print result both on output file 
                           and secreen
 * Due Date:               2/21/2017
 * Date Created:           2/21/2017
 * Date Last Modified:     2/21/2017
 */

/*
 * Data Abstraction:
 * 		Output file stream is opened and named as 'GPS.report'
 *      Input file is prompted and opened
 * 		double variables, totaldis, x1, y1, x2, y2, x3, y3, dist,
 *          distostart are initialized for use, string infname,
 *          line, double xcod, ycod
 * Input:
 * 		The program reads input from the user entering the name of the
 *          file and then reads the data in the file
 * Process:
 * 		The program will first prompt the user for an exist file over 
 *          and over again until the user did so, after that the program 
 *          will open the file and skip the first two lines and then reads
 *          the different commands, if the command is 'START', the program
 *          will read the x-coordinate and y-coordinate of the starting 
 *          point, if the command is 'DATA', then the program will reads 
 *          all coordinates of each point and calculate the total distance
 *          and the distance between the start point and the end point, if
 *          the command is 'STOP', the program reads the coordinates of 
 *          the ending point
 * Output:
 * 		The total distance and the distance between stop and start are 
 *          calculated the final position is displayed, all results are
 *          both printed on file and screen
 * Assumptions:
 * 		It is assumed that the user only wants to solve one formula at 
 *          a time
 * 		It is assumed that the user only wants real solutions to the 
 *          formula
 * 		It is assumed that, having been prompted to do so, the user will 
 *          correctly input data
 */

#include <iostream> //cin, cout
#include <fstream>  //ifstream, ofstream
#include <string>   //string line, infname
#include <iomanip>  //setprecision
#include <cmath>    //totaldis, distostart

using namespace std;

int main()
{
    ifstream infile; //input file
    ofstream outfile; //output file
    string infname, //name of the input file
           line, //line of input file
           command; //command in the file
    double totaldis = 0.0; //total distance
    double xcod, ycod, distostart = 0.0,
           x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0,
           y3 = 0.0, dist = 0.0;

    outfile.open("GPS.report"); //output file is opened
    
    //while input file name is invalid
    do
    {
        cout << "Please Enter The Name Of The Data File: ";
        cin >> infname;
        
        infile.open(infname.c_str());
        
        cout << infname << endl;
       
    }while (!infile);
    
    //skip the first two lines
    getline (infile, line);
    getline (infile, line);
    
    //while file is opened
    while (infile >> command >> xcod >> ycod)
    {
        if (command == "START")
        {
            x1 = xcod;
            y1 = ycod;
        }
        else if (command == "DATA")
        {
            x2 = xcod;
            y2 = ycod;
        
            dist = sqrt(pow((x2-x1), 2.0) + pow((y2-y1), 2.0));
            totaldis += dist; //total distance when not stop
            
            x1 = xcod;
            y1 = ycod;
        }
        else if (command == "STOP")
        {
            x3 = xcod;
            y3 = ycod;
            dist = sqrt(pow((x3-x1), 2.0) + pow((y3-y1), 2.0));
            totaldis += dist; //final total distance
            distostart = sqrt(pow((x3-x1), 2.0) + pow((y3-x1), 2.0));
            //distance between start point and end point
        }
    }
    //close the input file
    infile.close();

    //round the result to one decimal place
    cout << fixed << setprecision(1);
    
    //print the result on screen
    cout << "Final Location: (" << x3 << ", " << y3 << ")" << endl;
    cout << "Total distance traveled " << totaldis << endl;
    cout << "Distance to starting point: " << distostart << endl;
    
    outfile << fixed << setprecision(1);
    
    //print the result on file
    outfile << "Final Location: (" << x3 << ", " << y3 << ")" << endl;
    outfile << "Total distance traveled " << totaldis << endl;
    outfile << "Distance to starting point: " << distostart << endl;
    
    //close the output file
    outfile.close();
    
    //program ended
    return 0;
}
