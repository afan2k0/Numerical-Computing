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
#include <unordered_map>
using namespace std;

//global variables


//fix mantissa: currently outputs too many characters!

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
void toHex(string& hexString, string doubleString); //convert double to hex
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
    string hexString = "";
    //1. ask the user to enter the value to convert to IEEE
    cout << "Please enter a value to convert to IEEE: ";
    cin >> number;
    //2. find the significant bit
    sign_collection(number, sign);

    //1. function to isolate integer part from the decimal
    // 10.25 - integer part = 10 decimal part = 0.25

    isolate(number, intpart, decpart);
    inttable(intpart, integerbinary, 18);
    toBinaryDec(decpart, decbinary);
    binRepresenation(bin, integerbinary, decbinary);
    getMantissa(mantissa, bin, shifts);
    getExponent(exponent, shifts);
    ieeeDouble(sign, exponent, mantissa, stringDouble);
    toHex(hexString, stringDouble);
    return 0;


}

// communicating by pass by reference
void collect(double& x) {
    cout << "Please enter a value to convert to IEEE: ";
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
    decIndex = bin.find('.');
    firstOccurenceIndex = bin.find('1');


    shifts = decIndex - firstOccurenceIndex - 1;
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
    mantissa = mantissa.substr(0, 52);
}

void getExponent(string& exponent, int shifts)
{
    inttable(1023+shifts, exponent, 11);
}

void ieeeDouble(char sign, string exponent, string mantissa, string& stringDouble)
{
    stringDouble += sign;
    stringDouble += exponent;
    stringDouble += mantissa;
}

void toHex(string& hexString, string doubleString)
{
    unordered_map<string, char> umap;
    umap["0000"] = '0';
    umap["0001"] = '1';
    umap["0010"] = '2';
    umap["0011"] = '3';
    umap["0100"] = '4';
    umap["0101"] = '5';
    umap["0110"] = '6';
    umap["0111"] = '7';
    umap["1000"] = '8';
    umap["1001"] = '9';
    umap["1010"] = 'A';
    umap["1011"] = 'B';
    umap["1100"] = 'C';
    umap["1101"] = 'D';
    umap["1110"] = 'E';
    umap["1111"] = 'F';

    string temp = "";
    hexString = "0x";
    for(int i = 0; i<64; i+=4)
    {     
        temp = doubleString.substr(i,4);
        hexString += umap.at(temp);
    }
    cout << endl << hexString;
}