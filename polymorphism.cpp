#include <iostream>
using namespace std;


//Function Overloading: when there are different functions which have same name but different number/type of arguements
class Overloading
{
    public:
    void func()
    {
        cout<<"function with no arguements"<<endl;
    }
    void func(int x)
    {
        cout<<"function with int arguement: "<<x<<endl;
    }
    void func(string a)
    {
        cout<<"function with string arguement: "<<a<<endl;
    }

};
class complex
{
    private:
        int real,imag;
    public:
        complex(int r, int i) //constructor
        {
            real=r;
            imag=i;
        }
        complex()
        {
            cout<<"default constructor"<<endl;
        }
    complex operator + (complex const &obj)
    {
        complex res;
        res.imag=imag+obj.imag;
        res.real=real+obj.real;
        return res;            
    }
    void display()
    {
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
};
class base
{
    public:
    virtual void print()
    {
        cout<<"this is the base class's print function"<<endl;

    }
    void display()
    {
        cout<<"this is the base class's display function"<<endl;
        
    }
};
class derived:public base
{
    public:
    void print()
    {
        cout<<"this is the derived class's print function"<<endl;

    }
    void display()
    {
        cout<<"this is the derived class's display function"<<endl;
        
    }    
};

int main()
{
    Overloading b;
    b.func();
    b.func(4);
    b.func("sania");
    complex c1(12,7);
    complex c2(6,7);
    complex c3=c1+c2;
    c3.display();
    base *baseptr;
    derived d;
    baseptr=&d;
    baseptr -> print();
    baseptr -> display();
    return 0;
}