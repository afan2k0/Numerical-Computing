#include <iostream>
using namespace std;
int main()
{
    int i = 2;
    int sum = 0;
    while (i <= 15)
    {
        sum = sum + i;
        i = i + 2;
    }
    cout<<sum<<endl;

}