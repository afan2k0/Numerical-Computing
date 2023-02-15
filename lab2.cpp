/*
A. NAME: Aaron Fan
B. SCHOOL : New Jersey Institute of Technology
C. COURSE : ECET344-002
D. DATE : 26 January, 2023
E. DESCRIPTION : Calculates user BMI given si or imperial units, height, and weight as input 
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
//function prototypes
//global variables
//project entry point

float to_BMI(float weight, float height, bool units) //units=0, SI, units=1, imperial
{
	if (units == true) //imperial
	{
		return float(weight / (pow(height, 2)) * 703);
	}
	else //SI
	{
		return float(weight / pow(height, 2));
	}
}
char to_Range(float BMI)
{
    char range;
    if (BMI >= 30)
	{
		range = 'O';
	}
	else if (BMI <= 29.9 && BMI >= 25)
	{
		range = 'V';
	}
	else if (BMI <= 24.9 && BMI >= 18.5)
	{
		range = 'N';
	}
	else
	{
		range = 'U';
	}
    return range;
}
float in_to_cm(float in)
{
    return 2.54*in;
}

float lb_to_kg(float lb)
{
    return lb/2.205;
}


int main()
{
    cout << string(45, ' ') << "lbs" <<  endl; //print lbs at top of table
    cout << "     "; //pad with spaces
    //loop prints weights in lbs
    for(float weight = 90; weight <= 290; weight+= 10)
    {
        cout << weight << ' ';
    }
    cout << endl << "in" << string(89, '-') << "cm" <<endl; //print line of '-' characters


    //print BMI
	for(float height = 56; height <= 83; height++) //outer for loop will increment height
    {
        cout << height << " | "; //print height in inches on left, and separate with a '|' character
        for(float weight = 90; weight <= 290; weight+= 10) //print BMI column by column
        {
            cout << setw(2) << int(to_BMI(weight, height, 1)) << string(2, ' '); //call to_BMI function, passing the weight, height, and setting units=1(Imperial)
        }
        cout << "\b| " << setprecision(4) << in_to_cm(height) << endl; //print height in cm on right, separted with a '|' character
    }
    //Done printing BMI
    
    cout << "in" << string(89, '-') << "cm" <<endl; //print in, a line of '-' chars, and then cm 
    cout << "    ";//pad with spaces

    //print weight in increasing order, this time in SI(kg)
    for(float weight = 90; weight <= 290; weight+= 10)
    {
        cout << setw(3) << int(lb_to_kg(weight))  << ' ';//call lb_to_kg function for weight conversion, then cast to int
    }
    cout << endl << string(46, ' ') << "kg"; //go to next line, then print kg in the middle

    //print BMI ranges
    cout << string(2,'\n');
    cout << string(45, ' ') << "lbs" <<  endl;
    cout << "\t\b\b\b\b";
    for(float weight = 90; weight <= 290; weight+= 10)
    {
        cout << weight << ' ';
    }
    cout << endl << "in" << string(88, '-') << "cm" <<endl;


    //print ranges
	for(float height = 56; height <= 83; height++) //print row, then go to next column
    {
        cout << height << " |";
        for(float weight = 90; weight <= 290; weight+= 10) //print rows first
        {
            cout << setw(2) << to_Range(to_BMI(weight, height, 1)) << string(2, ' '); //same as previous, this time calling to_Range function and passing BMI
        }
        cout << "\b| " << setprecision(4) << in_to_cm(height) << endl;
    }

    
    cout << "in" << string(88, '-') << "cm" <<endl;
    cout << "   ";
    for(float weight = 90; weight <= 290; weight+= 10)
    {
        cout << setw(3) << int(lb_to_kg(weight))  << ' ';
    }
    cout << endl << string(46, ' ') << "kg";
    int x=0;
    cin >> x;
	return 0;
}

