#include<iostream>
using namespace std;

///DIFFERENT SORTING TECHNIQUES

///SELECTION SORT
//Take a pointer at first index of array and compare it with the upcoming values. If any smallest value exists, swap the smallest with the first index, else move to the next second index and repeat the process

void selectionSort(int arr[], int size)
{
    for(int i = 0; i<size; i++)
    {
        int smallIndex = i;
        for(int j = i+1; j<size; j++)
        {
            if(arr[j] < arr[smallIndex])
            {
                smallIndex = j;
            }
        }
        if(arr[i] > arr[smallIndex])
        {
            swap(arr[i], arr[smallIndex]);
        }
    }
}

///BUBBLE SORT
//Compare adjacent elements in the array and swap if current is smaller than the next. Repeat the process same amount of times as the size of the array, but use one less iteration from last every next time
void bubbleSort(int arr[], int size)
{
    for(int i = 0; i<size ; i++)
    {
        int flag = 0;
        for(int j = 0; j<size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}

///MERGE SORT
//First split the array into two halves. Sort both the halves individually by calling mergeSort on both split arrays. Then merge the split arrays into one.
void mergeArrays(int x[],int y[],int arr[], int s, int e)
{

    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;

    while(i<=mid && j<=e)
    {
        if(x[i] < y[j])
        {
            arr[k] = x[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = y[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        arr[k] = x[i];
        k++;
        i++;
    }
    while(j<=e)
    {
        arr[k] = y[i];
        k++;
        j++;
    }

}

void mergeSort(int arr[], int s, int e)
{
    if(s>=e)
    {
        return;
    }

    int mid = (s + e)/2;
    int x[100], y[100];
    for(int i = 0; i<=mid; i++)
    {
        x[i] = arr[i];
    }
    for(int i = mid +1; i<=e; i++)
    {
        y[i] = arr[i];
    }
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    mergeArrays(x,y,arr,s,e);
}

///QUICKSORT
//First take the last element of the array and swap it with center element and sort the left and right parts of the array separated by center. Call the recursive quickSort function in both halves.
int partition(int arr[], int s ,int e)
{
    int i = s;
    int j = e;
    int pivot = arr[e];
    int countSmaller = s;
    for(int k = s; k<e; k++)
    {
        if(arr[k] < pivot) countSmaller++;
    }
    int pivotIndex = countSmaller;

    swap(arr[pivotIndex], arr[j]);
    while(i<pivotIndex && j>pivotIndex)
    {
        if(arr[i] > arr[pivotIndex] && arr[j] < arr[pivotIndex])
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        if(arr[j] > arr[pivotIndex])
        {
            j--;
        }
        if(arr[i] < arr[pivotIndex])
        {
            i++;
        }
    }
    return pivotIndex;

}

void quickSort(int arr[], int s, int e)
{
    if(s>=e)
    {
        return ;
    }
    int p = partition(arr, s , e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main()
{
    int size;
    cout<<"Enter size of the array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the values in the array"<<endl;
    for(int i = 0; i<size; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Array before sorting: "<<endl;
    for(int i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"Array after sorting: "<<endl;
    //selectionSort(arr, size);
    //bubbleSort(arr, size);
    //mergeSort(arr, 0, size-1);
    quickSort(arr, 0, size-1);
    for(int i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
