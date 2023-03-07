//
// Aaron Fan 2/28/2023
//
/////ECET 344
//////revison
//////School: NJIT
//////Description: lecture functions

#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
#include <fstream>
using namespace std;

//global variables
struct values_t {
    string integer_binary;
    string decimal_binary;
    string full_binary;
    string mantissa;
    string exponent;
    string number_double;
    string hex_string;
    double number;
    char sign;
    int integer_part = 0;
    double decimal_part = 0.0;
    int shifts = 0;
};

//prototypes
void collect(double& x); //collects number entered by used
void sign_collection(double x, char& s); //gets sign of number
void isolate(double number, int& integer_part, double& decimal_part); //Has 3 parameters, number is the value entered by the user and this function returns the decimal part and the integer part. 
void display(char sign, int integer_part, double decimal_part, string integer_binary); //display sign and exponent part
void inttable(int integer_part, string& integer_binary, int bits); //convert int part to binary
void toBinaryDec(double decimal_part, string& decimaltobinary); //convert decimal part to binary
void binRepresentation(string& full_binary, string whole, string dec); //concats whole and fraction portion
void getMantissa(string& mantissa, string full_binary, int& shifts); //gets matissa and shifts
void getExponent(string& exponent, int shifts); //get exponent
void ieeeDouble(char sign, string exponent, string mantissa, string& number_double); //combine sign, exponent, mantissa
void toHex(string& hex_string, string doubleString); //convert double to hex
void writeToFile(values_t values);
void display(values_t values);

int main() {
    values_t values;
    //declarations/ initialization
    //1. ask the user to enter the value to convert to IEEE
    collect(values.number);
    //2. find the significant bit
    sign_collection(values.number, values.sign);

    //1. function to isolate integer part from the decimal
    //10.25 - integer part = 10 decimal part = 0.25

    isolate(values.number, values.integer_part, values.decimal_part);
    inttable(values.integer_part, values.integer_binary, (int)log2(abs(values.number))+1);
    toBinaryDec(values.decimal_part, values.decimal_binary);
    binRepresentation(values.full_binary, values.integer_binary, values.decimal_binary);
    getMantissa(values.mantissa, values.full_binary, values.shifts);
    getExponent(values.exponent, values.shifts);
    ieeeDouble(values.sign, values.exponent, values.mantissa, values.number_double);
    toHex(values.hex_string, values.number_double);
    display(values);
    
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
void isolate(double number, int& integer_part, double& decimal_part) {
    number = abs(number);
    integer_part = (int)number; //typecast
    decimal_part = number - integer_part;
}

//convert integer to decimal
void inttable(int integer_part, string& integer_binary, int bits) {
      for (int i = 0; i < bits; i++) {

        if (integer_part % 2 == 0)
            integer_binary = "0" + integer_binary;
        else
            integer_binary = "1" + integer_binary;

        integer_part = int(integer_part / 2);
    }
}

//function to convert decimal part to binary
void toBinaryDec(double decimal_part, string& decimaltobinary) {
    int intpart;
    for (int i = 0; i < 64; i++) {
        decimal_part *= 2;
        intpart = decimal_part;
        decimal_part = decimal_part - intpart;
        
        decimaltobinary += to_string(intpart);

    }
}

//obtain binary represenation of user input
void binRepresentation(string& full_binary, string whole, string dec)
{
    full_binary = whole + "." + dec;
}

//obtain mantissa of input
void getMantissa(string& mantissa, string full_binary, int& shifts)
{
    int decIndex = 0;
    int firstOccurenceIndex = 0;
    decIndex = full_binary.find('.');
    firstOccurenceIndex = full_binary.find('1');

    shifts = decIndex - firstOccurenceIndex;
    if(shifts > 0)
    {
        shifts--;
    }
    mantissa = full_binary.substr(firstOccurenceIndex+1, full_binary.length());
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

//obtain exponent portion
void getExponent(string& exponent, int shifts)
{
    inttable(1023+shifts, exponent, 11); 
}

//obtain ieee double in binary
void ieeeDouble(char sign, string exponent, string mantissa, string& number_double)
{
    number_double = sign+exponent+mantissa;
}

void toHex(string& hex_string, string doubleString)
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
    hex_string = "0x";
    for(int i = 0; i<64; i+=4)
    {     
        temp = doubleString.substr(i,4);
        hex_string += umap.at(temp);
    }
}

//Function 9: write to file
void writeToFile(values_t values) {
    ofstream myfile;
    myfile.open("output.txt");
    myfile << "sign: " << values.sign << endl;
    myfile << "integer part: " << values.integer_part << " " << values.integer_binary << endl;
    myfile << "decimal part: " << values.decimal_part << " " << values.decimal_binary << endl;
    myfile << "number entered: " << values.integer_part << to_string(values.decimal_part).substr(1) << " " << values.full_binary << endl;
    myfile << "mantissa: " << values.mantissa << endl;
    myfile << "exponent: " << 1023+values.shifts << " " << values.exponent << endl;
    myfile << "IEEE754 Double Binary: " << values.number_double << endl;
    myfile << "IEEE754 Hex: " << values.hex_string << endl;
    myfile.close();
}

void display(values_t values) {
    cout << "Please choose one of the following operations: " << endl;
    cout << "1. DISPLAY THE SIGN BIT VALUE " << endl;
    cout << "2. DISPLAY THE INTEGER PART IN BOTH BASE-10 AND BINARY FORMATS" << endl;
    cout << "3. DISPLAY THE DECIMAL PART IN BOTH BASE-10 AND BINARY FORMATS" << endl;
    cout << "4. DISPLAY THE NUMBER ENTERED IN BOTH BASE-10 AND BINARY FORMATS" << endl;
    cout << "5. DISPLAY THE MANTISSA IN BINARY FORMAT" << endl;
    cout << "6. DISPLAY THE EXPONENT IN BOTH BASE-10 AND BINARY FORMAT" << endl;
    cout << "7. DISPLAY THE IEEE 754 DOUBLE PRECISION BINARY LAYOUT" << endl;
    cout << "8. DISPLAY THE IEEE 754 DOUBLE PRECISION HEX LAYOUT" << endl;
    cout << "9. SEND THE DETAILED SOLUTION TO AN EXTERNAL FILE" << endl;
    int selection = 1;
    while(selection != 0)
    {
        cout << "enter selection(0 to quit): ";
        cin >> selection;
        switch(selection)
        {          
            case 1:
                cout << values.sign << endl;
                break;
            case 2:
                cout << values.integer_part << " " << values.integer_binary << endl;
                break;
            case 3:
                cout << values.decimal_part << " " << values.decimal_binary << endl;
                break;
            case 4:
                cout << values.integer_part << to_string(values.decimal_part).substr(1) << " " << values.full_binary << endl;
                break;
            case 5:
                cout <<values.mantissa << endl;
                break;
            case 6:
                cout << 1023+values.shifts << " " << values.exponent << endl;
                break;
            case 7:
                cout << values.number_double << endl;
                break;
            case 8:
                cout << values.hex_string << endl;
                break;
            case 9:
                writeToFile(values);
            default:
                break;
        }
    }
}