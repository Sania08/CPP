#include <iostream>
#include <math.h>
using namespace std; 

// UTILITY FUNCTIONS
// Function to print an array
// void printArray(int A[], int size)
// {
//     for (auto i = 0; i < size; i++)
//         cout << A[i] << " ";
// }

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Find the minimum element in the unsorted array 
// and swap it with the element in the beginning
void SelectionSort(int arr[],int arr_size)
{
    for(int i=0;i<arr_size;i++)
    {
        for(int j=i+1;j<arr_size;j++)
        {
            if(arr[j]<arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printArray(arr, arr_size);
}

// Repeatedly Swap two adjacent elements if they are in wrong order
void BubbleSort(int arr[], int arr_size)
{
    for(int i=0;i<arr_size;i++)
    {
        for(int j=0;j<arr_size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }       
        
    }
    printArray(arr, arr_size);
}

// Insert an element from unsorted array 
// to its correct position in sorted array
void InsertionSort(int arr[],int arr_size)
{
    for(int i=1;i<arr_size;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
    }
    printArray(arr, arr_size);
}

void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const n1 = mid - left + 1;
    auto const n2 = right - mid;
 
    // Create temp arrays
    auto *a = new int[n1],
         *b = new int[n2];
 
    // Copy data to temp arrays a[] and b[]
    for (auto i = 0; i < n1; i++)
        a[i] = array[left + i];
    for (auto j = 0; j < n2; j++)
        b[j] = array[mid + 1 + j];
 
    auto i= 0; 
    auto j= 0; 
    int k= left; 
 
    // Merge the temp arrays back into array[left..right]
    while (i < n1 && j < n2)
    {
        if (a[i]<= b[j])
        {
            array[k]= a[i];
            i++;
        }
        else {
            array[k]= b[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (i < n1)
    {
        array[k]= a[i];
        i++;
        k++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (j < n2)
    {
        array[k]= b[j];
        j++;
        k++;
    }
    delete[] a;
    delete[] b;
}
 
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void swaper(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[],int l,int r)
{
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<=r;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swaper(arr,i,j);
        }
    }
    swaper(arr,i+1,r);
    return i;
}
void QuickSort(int arr[], int const l, int const r)
{
    if(l<r)
    {
        int pivot=partition(arr,l,r);
        QuickSort(arr,l,pivot-1);
        QuickSort(arr,pivot+1,r);

    }
}

void countSort(int arr[], int n)
{
    //find max element of the array
    int *nptr=&n;
    auto max=INT_MIN;
    int *maxptr=&max;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>*maxptr)
        {
            *maxptr=arr[i];
        }
    }
    cout<<max<<endl;
    int count[max]={0};

    printArray(count,max); //fking hardcoders
    for(int i=0;i<n;i++)
    {
        count[arr[i]]=count[arr[i]]+1;
    }
    printArray(count,max+1);
    for(int i=1;i<n;i++)
    {
        count[i]=count[i-1]+count[i];
    }
    printArray(count,max);
    cout<<n-1<<endl;
    cout<<count[arr[n-1]]<<endl;
    int sortedarray[n];
    for(int i=n-1;i>=0;i--)
    {
        count[arr[i]]=count[arr[i]]-1;
        sortedarray[count[arr[i]]]=arr[i];
    }
    printArray(sortedarray,n);



}
// Q1: Given an array of size n. The task is to find repeating element in the array of integers
// i.e the element that occurs more than once and element that occurs more than once and whose index of occurence is smallest
void question1(int arr[], int arr_size)
{
    const int N= 10000 ;
    int minidx=INT_MAX;
    int idx[N];
    for(int i=0;i<N;i++)
    {
        idx[i]=-1;
    }
    for(int i=0;i<arr_size;i++)
    {
        if (idx[arr[i]]==-1)    
        {
            idx[arr[i]]=i;
        }
        else
        {
            if(minidx>idx[arr[i]])
            {
                minidx=idx[arr[i]];
            }
        }
    }
    if(minidx=INT_MAX)
    {
        cout<<"No repeating element"<<endl;
    }
    else
    {
        cout<<"Repeating element is "<<arr[minidx]<<" and its index is "<<minidx<<endl;
    }

}

// Given an unsorted array A of size n of non-negative integers, 
// find a continuous sub-array which adds to a given number S.

void question2(int A[], int n, int S)
{
    int st=-1,en=-1,i=0,j=0;
    int currSum=0;
    while(j<n)
    {
        cout<<"j="<<j<<endl;
        currSum=currSum+A[j];
        
        while(currSum>S)
        {
            currSum=currSum-A[i];
            i++;
            cout<<"i="<<i<<endl;

        }
        if(currSum==S)
        {
            st=i;
            en=j;
            break;
        }
        j++;
    }

    cout<<"start is:"<<st<<" end is:"<<en<<endl;

}

// You are given an array arr[] of n integers including 0. 
// The task is to find the smallest positive number missing from the array.
void question3(int arr[], int arr_size)
{
    const int N=10000;
    int idx[N];
    for(int i=0;i<N;i++)
    {
        idx[i]=-1;
    }
    for(int j=0;j<arr_size;j++)
    {
        idx[arr[j]]=0;
    }
    for(int k=1;k<N;k++)
    {
        if(idx[k]==-1)
        {
            cout<<"Smallest positive number missing from the array is:"<<k<<endl;
            break;
        }
    }

}

void dnfSort(int arr[], int n)
{
    int start=0, end=n-1,mid=start,temp;
    while(mid!=end)
    {
        if(arr[mid]==0)
        {
            temp=arr[mid];
            arr[mid]=arr[start];
            arr[start]=temp;
            start++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else if(arr[mid]==2)
        {
            temp=arr[mid];
            arr[mid]=arr[end];
            arr[end]=temp;
            end--;
        }
    }
    printArray(arr,n);
}
int main ()
{
    int array[12] = {4,4,7,8,4,9,2,8,9,2,1,2};
    int const N=sizeof(array)/sizeof(array[0]);
    int array123[]={1,0,2,1,0,1,2,1,2};
    int const N123=sizeof(array123)/sizeof(array123[0]);
    // SelectionSort(array,6);
    // BubbleSort(array,6);
    // InsertionSort(array,6);
    // question1(array,7);
    // question2(array,4,5);
    //question3(array,7);
    // mergeSort(array,0,5);
    // QuickSort(array,0,5);
    // cout<<"sorted array is:"<<endl;
    //countSort(array,N);
    dnfSort(array123,N123);
}