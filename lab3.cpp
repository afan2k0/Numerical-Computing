#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

//function prototyping
void populate_arr(int arr[]);
void display_arr(int arr[]);
float arr_mean(int arr[]);
float arr_variance(int arr[], float mean);
int main()
{
    int arr[100];
    float mean;

    populate_arr(arr);
    display_arr(arr);
    mean = arr_mean(arr);
    cout << arr_mean(arr) << endl;
    cout << arr_variance(arr, mean) << endl;
    cout << sqrt(arr_variance(arr, mean));
}

//populate array function
void populate_arr(int arr[])
{
    srand((unsigned) time(NULL)); //choose seed based on computer clock
    int random; 
    for(int i = 0; i< 100; i++)
    {
        random = rand()%51; //generate random int, [0,50]
        arr[i] = random; //assign randomly generated int to index i in array
    }
}

//print array function
void display_arr(int arr[])
{
    for(int i = 0; i < 100; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//obtain mean of array
float arr_mean(int arr[])
{
    float mean = 0; 
    int sum = 0;
    for(int i = 0; i < 100; i++)
    {
        sum += arr[i]; //get sum of array
    }
    mean = sum/100.0; //divide sum of array by size of array
    return mean;
}

//obtain population variance of array
float arr_variance(int arr[], float mean)
{
    float sum = 0;
    for(int i = 0; i < 100; i++)
    {
        sum += pow((arr[i]-mean),2.0); //subtract each value in array by mean, then square the value
    }
    return sum/100;
}