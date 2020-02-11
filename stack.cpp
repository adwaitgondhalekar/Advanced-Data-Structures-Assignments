#include<iostream>
#define max 50
using namespace std;
template<class T>
class stack
{
    public:
    T s[max];
    int top;

    stack()
    {
        top=-1;
    }



int is_full()
{
    if(top==max-1)
        return 1;
    else
        return 0;
}
int is_empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(T ch)
{
    if(!is_full())
    {
        s[++top]=ch;

    }
    else
    {
        cout<<"stack overflow\n";
    }


}


T pop()
{
    if(!is_empty())
    {
        T r;
        r=s[top];
        top--;
        return r;
    }
    else
        cout<<"empty stack\n";
}
};
