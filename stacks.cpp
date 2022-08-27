#include<iostream>
#include<stack>
using namespace std;
#define n 100
// class stack
// {
//     int* arr;
//     int top;
//     public:
//     stack()
//     {
//         arr=new int[n];
//         top=-1;
//     }
//     void push(int x)
//     {
//         if(top==n-1)
//         {
//             cout<<"stack overflow"<<endl;
//             return;
//         }
//         top++;
//         arr[top]=x;
//     }
//     void pop()
//     {
//         if(top==-1)
//         {
//             cout<<"no element to pop"<<endl;
//             return;
//         }
//         top-- ;
//     }
//     int Top()
//     {
//         if(top==-1)
//         {
//             cout<<"no elements in the stack"<<endl;
//             return -1;
//         }
//         return arr[top];    
//     }
//     bool empty()
//     {
//         return top==-1;
//     }
// };
void reverseSentence(string s)
{
    stack<string> st;
    for(int i=0;i<s.length();i++)
    {
        string word="";
        while(s[i]!=' ' && i<s.length())
        {
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

}
int main()
{
    // stack st;
    // int arr[]={1,2,3,4,5,6,7};
    // for(int i=0;i<7;i++)
    // {
    //     st.push(arr[i]);
    // }
    // cout<<"topmost element is"<<st.Top()<<endl;
    // cout<<st.empty()<<endl;  
    // for(int i=0;i<7;i++)
    // {
    //     st.pop();
    // }
    // cout<<"topmost element is"<<st.Top()<<endl;  
    // cout<<st.empty()<<endl;  
    // st.pop();
//comment out the previously written custom class before this
    string s="Manan likes sania";
    reverseSentence(s);
}
