#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
//struct key

void filler(int list[10]);
void display(int list[10]);
int main()
{
    int arr[10] = {1,2,6,3,6,3,6,8,3,123};

    cout << endl;
    display(arr);
    cout << endl;
    filler(arr);
    display(arr);
}
void filler(int list[10])
{
    for(int i = 0; i<=9; i++)
    {
        list[i] = i;
    }
}

void display(int list[10])
{
    for(int i=0; i<10; i++)
    {
        cout << list[i] << " ";
    }
}
/*

In Class Array Worksheet
1.  What is the output of the following program?
    #include <iostream>
    Using namespace std;
    int main()
    {
       int a[100], b[100], j, m;
       int suma = 0, sumb = 0, sumdiff = 0;
       cin >> m;
       for (j = 0 ; j < m ; j++)
       {
          cin >> a[j] >> b[j];
          suma = suma + a[j];
          sumb += b[j];
          sumdiff = sumdiff + (a[j] - b[j]);
       }
       for (j = m - 1 ; j >= 0 ; j--)
          cout << a[j] << "  " << b[j] << "  " << a[j] - b[j] << endl;
       cout << suma << "  " << sumb << "  " << sumdiff << endl;
    }
    DATA:
    5
  0  11 15 a={11}, b={15}, suma=11, sumb = 15, sumdiff = -4
  1  19 14 a={11,19}, b={15,14}, suma = 30, sumb = 29, sumdiff = 1
  2  4  2 a={11,19,4}, b={15,14,2}, suma = 34, sumb=31, sumdiff = 3
  3  17 6 a = {11,19,4,17}, b={15,14,2,6} suma = 51, sumb = 37, sumdiff = 14
  4  1  3 a = {11,19,4,17,1}, b={15,14,2,6,3}, suma=52, sumb = 40, sumdiff = 12
    1 3 -2
    17 6 11
    4 2 2
    19 14 5
    11 15 -4
    52 40 12

2.  Given:   int h = 6, p = 2, m = 3;
             int values[7];
    Suppose values contains: -4  0  2  6  -2  -1  14 
    Show the contents of the array values after:
      for (; m <=5; m++)
         values[m] = values[h] + values[p] * values[m];
values[3] = value[6] + values[2]*values[3]: 14+2*6 = 26
values[4] = values[6] + values[2]*values[4]: 14+2*-2 = 10
values[5] = values[6] + values[2]*values[5]: 14+2*-1 = 12
-4 0 2 26 10 12 14
3.  Given the declarations:
       int sample[8], i, k;
    show the contents of the array sample after the following code is 
    executed. Use a question mark to indicate any garbage values
    in the array.

    for (k = 0 ; k < 8 ; k++)
       if (k % 2) k is odd
          sample[k] = 1;
? 1 ? 1 ? 1 ? 1
4.  What is the error in the following program segment?

    int main()
    {
       int i, count[10];
       cout << "please enter 10 numbers:  ";
       for (i = 1; i <= 10; i++)
          cin >> count[i];
    }
count[] will be filled from index 1 to 10, but count index is 0 to 9



5.  Write the statements to multiply every element of an array of ints
    (of size 50) by 2.
for(int i = 0; i < 50; i++)
{
    arr[i] *= 2;
}
6.  Write the statements to add up those elements of an array of ints (of
    size 25) which have an even subscript.
sum=0;
for(int i = 0; i < 25; i++)
{
    if(i%2==0)
    {
        sum += arr[i];
    }
}

7.  Write the statements to add up those elements of an array of ints (of
    size 25) which have an even value.
sum=0;
for(int i = 0; i < 25; i++)
{
    if(arr[i] %2 == 0)
    {
        sum += arr[i];
    }
}
8.  What will the following program segment print?
    int main()
    {
       int nums[10];
       int i;
       for (i = 9 ; i >= 0 ; i--)
       {
          nums[i] = 5 * (i + 1);
          cout << nums[i] << "  ";
       }
       cout << endl;
       for (i = 0 ; i < 9 ; i++)
          cout << nums[i] << "  ";
       cout << endl;
       for (i = 0 ; i < 9 ; i++)
          nums[i+1] = nums[i];
       for (i = 0 ; i < 9 ; i++)
          cout << nums[i] << "   ";
       cout << endl;
    }

9.  What will the following program segment print?
    int main()
    {
       int nums[10];
       int i;
       for (i = 9 ; i >= 0 ; i--)
       {
          nums[i] = 5 * (i + 1);
          cout << nums[i] << "  ";
       }
       cout << endl;
       for (i = 0 ; i < 9 ; i++)
          cout << nums[i] << "  ";
       cout << endl;
       for (i = 8 ; i >= 0 ; i--)
          nums[i+1] = nums[i];
       for (i = 0 ; i < 9 ; i++)
          cout << nums[i] << "   ";
       cout << endl;
    }
10. Given:   int temps[50];
    Write the statements to print "yes" if any element of the array temps     contains the value 100.

11. Given:   int temps[50];
    Write the statements to set the variable found to true if any element of the array temps contains the value 100. If not, the variable found should be false.




*/