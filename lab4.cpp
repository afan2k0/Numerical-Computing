//
// Created by Amrit Sriram Murali on 2/16/23.
//
/////ECET 344
//////revison
//////School: NJIT
//////Description: lecture functions

#include "iostream"
#include "string"
#include <cmath>
using namespace std;

//global variables




//prototypes
void collect(double x); //collects number entered by used
void sign_collection(double x, char& s); //gets sign of number
void isolate(double number, int& intpart, double& decpart); //Has 3 parameters, number is the value entered by the user and this function returns the decimal part and the integer part. 
void display(char sign, int intpart, double decpart, string integerbinary); //display sign and exponent part
void inttable(int intpart, string& integerbinary, int bits); //convert int part to binary
void toBinaryDec(double decpart, string& decimaltobinary); //convert decimal part to binary
void binRepresenation(string& bin, string whole, string dec); //concats whole and fraction portion
void getMantissa(string& mantissa, string bin, int& shifts); //gets matissa and shifts
void getExponent(string& exponent, int shifts); //get exponent
void ieeeDouble(char sign, string exponent, string mantissa, string& stringDouble); //combine sign, exponent, mantissa
int main() {

    //declarations/ initialization

    double number;
    char sign;
    int intpart = 0;
    double decpart = 0.0;
    string integerbinary = "";
    string decbinary = "";
    string bin = "";
    int bits = 0;
    int shifts = 0;
    string mantissa = "";
    string exponent = "";
    string stringDouble = "";
    //1. ask the user to enter the value to convert to IEEE
    cout << "Please enter a value to convert to IEEE";
    cin >> number;
    //2. find the significant bit
    sign_collection(number, sign);

    //1. function to isolate integer part from the decimal
    // 10.25 - integer part = 10 decimal part = 0.25

    isolate(number, intpart, decpart);
    cout << "intpart: " << intpart << endl;
    cout << "decpart: " << decpart << endl;

    inttable(intpart, integerbinary, 12);
    cout << "intString: " << integerbinary << endl;
    toBinaryDec(decpart, decbinary);
    cout << "decpart: " << decbinary << endl;
    binRepresenation(bin, integerbinary, decbinary);
    cout << "binary representation: " << bin << endl;

    getMantissa(mantissa, bin, shifts);
    //display(sign, intpart, decpart, integerbinary);

    getExponent(exponent, shifts);
    ieeeDouble(sign, exponent, mantissa, stringDouble);

    cout << endl << "sign: " << sign << endl;
    cout << "exponent: " << exponent << endl;
    cout << "mantissa: " << mantissa << endl;
    cout << "full double: " << stringDouble;
    return 0;


}

// communicating by pass by reference
void collect(double& x) {
    cout << "Please enter a value to convert to IEEE";
    cin >> x;
}


// a function to extract a number sign
void sign_collection(double x, char& s) {


    if (x >= 0)
        s = '0'; //0 for positive
    else
        s = '1'; // 1 for negative
}

//a function that takes a double value and returns an integer and a double
void isolate(double number, int& intpart, double& decpart) {

    number = abs(number);
    intpart = (int)number; //typecast

    decpart = number - intpart;
}


// a function for verification


void display(char sign, int intpart, double decpart, string integerbinary) {

    string st = "";
    if (sign == '0')
        st = "Positive";
    else
        st = "negative";

    cout << "the sign of the number is" << st << endl;
    cout << "the integer part is: " << abs(intpart) << endl;
    cout << "the decimal part is: " << decpart << endl;
    cout << "the binary value ";

}

//convert integer to decimal
void inttable(int intpart, string& integerbinary, int bits) {

    for (int i = 0; i < bits; i++) {

        if (intpart % 2 == 0)
            integerbinary = "0" + integerbinary;
        else
            integerbinary = "1" + integerbinary;

        intpart = int(intpart / 2);
    }
}

//function to convert decimal part to binary
void toBinaryDec(double decpart, string& decimaltobinary) {
    for (int i = 0; i < 52; i++) {

        decpart *= 2;
        if (decpart < 1) {
            decimaltobinary = decimaltobinary + "0";

        }
        else {
            decimaltobinary = decimaltobinary + "1";
            decpart -= 1;
        }
    }
}

void binRepresenation(string& bin, string whole, string dec)
{
    bin += whole;
    bin += ".";
    bin += dec;
}

void getMantissa(string& mantissa, string bin, int& shifts)
{
    int decIndex = 0;
    int firstOccurenceIndex = 0;
    for(int i = 0; i<bin.length(); i++)
    {
        if(bin[i] == '.')
        {
            decIndex = i;
            break;
        }
    }
    decIndex = bin.find('.');
    cout << "decIndex: " << decIndex << endl;
    firstOccurenceIndex = bin.find('1');
    cout << "firstOccurenceIndex: " << firstOccurenceIndex << endl;

    shifts = decIndex - firstOccurenceIndex - 1;
    cout << "shifts: " << shifts << endl;
    mantissa = bin.substr(firstOccurenceIndex+1, bin.length());
    string tempMantissa = mantissa;
    mantissa = "";
    for(int i = 0; i < tempMantissa.length(); i++)
    {
        if(tempMantissa[i] != '.')
        {
            mantissa += tempMantissa[i];
        }
    }
    cout << mantissa;
}

void getExponent(string& exponent, int shifts)
{
    string exp = "";
    inttable(1023+shifts, exp, 11);
    cout << "exponent: " << exp;
    exponent = exp;
}

void ieeeDouble(char sign, string exponent, string mantissa, string& stringDouble)
{
    stringDouble += sign;
    stringDouble += exponent;
    stringDouble += mantissa;
    cout << endl << "full double: " << stringDouble;
}