/triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H

class triangle
{
private:
    double x1, y1,
    x2, y2,
    x3, y3;
public:
    
    triangle();
    triangle(double x1,double y1,
             double x2,double y2,
             double x3,double y3);
    
    double getPerimeter();
    
    double getSide1();
    double getSide2();
    double getSide3();
    
    double getArea();
};

#endif TRIANGLE_H

--------------------------------------------------------------------------------------------------------------

//triangle.cpp
#include<iostream>
#include "triangle.h"
using namespace std;


triangle::triangle(double x1,double y1,
                   double x2,double y2,
                   double x3,double y3)
{
    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;
    this->x3=x3;
    this->y3=y3;
    
}
//returns perimiter
double triangle::getPerimeter()
{
    return (getSide1()+getSide2()+getSide3())/2.0;
}
//return side1
double triangle::getSide1()
{
    double a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return a;
    
}
//return side2
double triangle::getSide2()
{
    double b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    return b;
}

//return side3
double triangle::getSide3()
{
    double c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    return c;
}

//Returns area
double triangle::getArea()
{
    double s=getPerimeter();
    double area=sqrt(s*(s-getSide1())*(s-getSide2())*(s-getSide3()));
    return area;
}

--------------------------------------------------------------------------------------------------------------

//main.cpp
//header files
#include<iostream>
#include<fstream>
#include<iomanip>
#include "triangle.h"
using namespace std;
int main()
{
    char fileName[20];
    
    ifstream fin;
    double x1, y1,
    x2, y2,
    x3, y3;
    
    cout<<"Enter name of data file: ";
    cin>>fileName;
    
    fin.open(fileName);
    
    
    //check for file error
    if(!fin)
    {
        cout<<"ERROR: Bad File Name"<<endl;
        system("pause");
        exit(0);
    }
    
    double total=0;
    double max=INT_MIN;
    double min=INT_MAX;
    int count=0;
    
    //read until end of file
    while(fin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        triangle t(x1,y1,x2,y2,x3,y3);
        
        cout<<fixed<<setprecision(2)<<
        "( "<<x1<<", "<<y1<<") ("<<
        x2<<", "<<y2<<") ( "<<x3<<","<<y3<<")    area = "<<t.getArea()<<endl;
        double area=t.getArea();
        total+=area;
        
        if(area>max)
            max=area;
        
        if(area<min)
            min=area;
        
        count++;
        
    }
    
    cout<<"Maximum area ="<<max<<endl;
    cout<<"Minimum area ="<<min<<endl;
    cout<<"Average area = "<<(total)/count<<endl;
    
    fin.close();
    //pause program output on console
    system("pause");
    return 0;
}

