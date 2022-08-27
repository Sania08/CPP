#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
void vectorsBasic()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30); //adds elements to the end of the vector
    v.push_back(60);
    v.push_back(49);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    sort(v.begin(),v.end()); //sorts the vector
    v.pop_back(); //removes the last element of the vector
    vector<int>::iterator it;  // iterator it is a pointer
    for(it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    vector<int> v2 (3,45); //outputs vector of size 3 with all elemnts as 45

    for(auto element:v2)
    {
        cout<<element<<" ";
    }
    swap(v,v2); // swaps the vectors v and v2
    for(auto element:v)
    {
        cout<<element<<" ";
    }
    cout<<endl;
    for(auto element:v2)
    {
        cout<<element<<" ";
    }
    
}
void pairBasic()
{
    pair <int,char> p;
    p.first=3;
    p.second='h';
    cout<<p.first<<","<<p.second;
}
bool myCompare(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first<p2.first;
}
//replace the elements with the index that it will have after sorting the array
void question(int arr[], int size)
{
    vector<pair<int,int>> v;
    for(int i=0;i<size;i++)
    {
        pair <int,int> p;
        p.first=arr[i];
        p.second=i;
        v.push_back(p);
    }
    sort(v.begin(),v.end(),myCompare);
    for(int i=0;i<v.size();i++)
    {
        arr[v[i].second]=i;
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<arr[i]<<" ";
    } 
}

int main()
{
    int array[]={10,16,7,14,5,3,2,9};
    //vectorsBasic();
    
    // pairBasic();
    question(array,8);
}