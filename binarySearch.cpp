#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key);


int main()
{
    int even[6] = {2, 4, 76, 82, 99, 190};
    int odd[5] = {23, 34, 56, 88, 90};
    int evenindex=binarySearch(even, 6,99);
    int oddindex=binarySearch(odd, 6,99);
    cout<<"Index of 99 is "<<evenindex<<endl;
    cout<<"Index of 88 is "<<oddindex<<endl;

    return 0;
}

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        /* code */
        if (arr[mid] == key)
        {
            return mid;
        }

        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
