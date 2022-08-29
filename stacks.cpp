#include<iostream>
#include<stack>
#include<math.h>
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
void insertAtBottom(stack<int> &st,int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    int topele=st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
}
void reverse(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }
    //Hold all the items in function call stack
    // until we reach the end of the stack
    int ele=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);
}
int prefix_evaluator(string s)
{
    stack<int> st;

    for(int i=s.size()-1;i>=0;i--)
    {
        //if the element of the string is an operand
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');

        }
        //if the element of the string is an operator
        else
        {
            int operand1=st.top();
            st.pop();
            int operand2=st.top();
            st.pop();
            switch(s[i])
            {
                case '+':
                    st.push(operand1+operand2);
                    break;
                
                case '-':
                    st.push(operand1-operand2);
                    break;

                case '*':
                    st.push(operand1*operand2);
                    break;

                case '/':
                    st.push(operand1/operand2);
                    break;
                case '^':
                    st.push(pow(operand1,operand2));
                    break;
                default:
                    break;                
            }            
        }
    }
    return st.top();
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
    string s="Hi how are you ?";
    reverseSentence(s);
    stack <int> st;
    int arr[]={1,2,3,4,5,6,7};
    for(int i=0;i<7;i++)
    {
        st.push(arr[i]);
    }
    reverse(st);
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
    cout<<"enter the prefix evaluation"<<endl;
    string prefix;
    // cin>>prefix;
    cout<<"the ans is:" <<prefix_evaluator("-+7*45+20")<<endl;



}
