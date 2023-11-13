#include <iostream>
using namespace std;
int bubbleSort(int arr[],int size);         //Function Prototype
void printArray(int arr[], int size);       //Function Prototype

int main(){
    int arr[5] = {45,12,74,36,25};
    int size = 5;
    cout<<"Process of bubble sort"<<endl;
    bubbleSort(arr,size);
    printArray(arr,size);
return 0;
}

int bubbleSort(int arr[],int size)
{
    for (int i=0; i<size-1; i++)     //for (n-1) rounds 
    {
        for (int j=0; j<size; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}