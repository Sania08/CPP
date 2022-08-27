#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Q1:convert all lower case letters of a string to upper case
string toUpper(string s) 
{
    for(int i=0;i<s.size();i++)
    {
        if (s[i]>='a' && s[i]<='z')
        {
            s[i]=s[i]-32;

        }
    }
    return s;
}

string toUpper_using_inbuilt_function(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

//Q2: Form the maximum number from numeric string/ given digits
int maxNum(string s)
{
    sort(s.begin(),s.end(),greater<int>());
    int x=stoi(s);
    return x;
}
//Q3: Given a string, output the character which occurs maximum times along with its frequency
void frequency_counter(string s)
{
    int count[26]={0};
    for(int i=0;i<s.size();i++)
    {
        count[s[i]-'a']++;
    }
    int max=0;
    int index=0;
    for(int i=0;i<26;i++)
    {
        if(count[i]>max)
        {
            max=count[i];
            index=i;
        }
    }
    cout<<"The character which occurs maximum times is "<<(char)(index+'a')<<" and its frequency is "<<max<<endl;
}

int main()
{
    // string s="HelloWorld";
    // cout<<toUpper(s)<<endl;
    //  string str="8347";
    //  cout<<maxNum(str)<<endl;
     string str="helloworld";
     frequency_counter(str);
    

}