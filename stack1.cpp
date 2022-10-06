#include<iostream>
// stack easy implementation
using namespace std;
class stack
{
    public:
        int top;
        int data;
        int size;
        int * arr;
        
};

int isEmpty(stack  s)
{
    if (s.top==-1)
    {
        return 1;
    }
    return 0;
    
}
int isFull(stack s)
{
    if (s.top==s.size-1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    stack s;
    
    s.size=7;
    s.arr=new int[s.size];
    s.top=-1;
    s.arr[0]=33;
    s.top++;
    s.arr[1]=34;
    s.top++;
    s.arr[2]=35;
    s.top++;
    s.arr[3]=36;
    s.top++;
    s.arr[4]=37;
    s.top++;
    if (isEmpty(s))
    {
        cout<<"Stack is Underflow"<<endl;

    }
    else
    {
        cout<<"Stack is Not Empty"<<endl;
    }   
    if (isFull(s))
    {
        cout<<"Stack is overflow"<<endl;
    }
    else
    {
        cout<<"stack is not full";
    }
    return 0;
}