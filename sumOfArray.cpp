#include <iostream>
using namespace std;
int SumOfArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
int main()
{
    int n;
    cout << "enter size of array " << endl;
    cin >> n;
    int num[n];
    int mask;
    mask= SumOfArray(num,n);
    cout << "sum is " << mask<< endl;
    return 0;
}
