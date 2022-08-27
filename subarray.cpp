#include <iostream>
using namespace std;


void printSubArray(int arr[], int arrsize)
{
    for (int i=0;i<arrsize; i++)
    {
        for(int j=arrsize-1;j>=i;j--)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}
void maxSumSubArray(int arr[], int arrsize)
{
    int maxSum=INT_MIN;
    for (int i=0;i<arrsize; i++)
    {
        for(int j=arrsize-1;j>=i;j--)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum=sum+arr[k];
            }
            if(sum>maxSum)
            {
                maxSum=sum;
            }
        }
    }
    cout<<"Max sum is "<<maxSum<<endl;

}
int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // printSubArray(arr, 9);
    maxSumSubArray(arr, 9);

}