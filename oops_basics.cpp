#include <iostream>

using namespace std;

class Student
{
    public:
    string name;
    int age;
    bool gender;

    //paramterised constructor
    Student(string s,int a , bool g)
    {
        cout<<"parameterised constructor"<<endl;
        name=s;
        age=a;
        gender=g;
    }
    Student()
    {
        cout<<"deafult constructor"<<endl;
    }

    void printInfo()
    {
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;

    }
    ~Student()
    {
        cout<<"destructor"<<endl;
    }
    Student(Student &n)
    {
        cout<<"copy constructor"<<endl;
        name=n.name;
        age=n.age;
        gender=n.gender;
    }
    //Getters are public functions used to get private data members in the class.
    string getName()
    {
        cout<<"getter"<<endl;
        return name;
    }
    //Setters are public functions used to set private data members in the class.
    void setName(string s)
    {
        name=s;
    }
    //Operator Overloading:We can overload operators( == , + , - ,etc), to work on class objects.
    bool operator==(Student &m)
    {
        if(name==m.name && age==m.age && gender==m.gender)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Student a("sania",21,1);
    a.printInfo();
    Student();
    Student c=a;
    c.printInfo();
    cout<<c.getName()<<endl;
    c.setName("shahid");
    c.printInfo();
    cout<<(c==a)<<endl;


}