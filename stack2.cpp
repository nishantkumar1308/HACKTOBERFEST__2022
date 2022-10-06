#include<iostream>
// stack implimentaion via pointer to easy questions
using namespace std;
class stack
{
    public:
    int top;
    int * arr;
    int size;
    
};
int isEmpty(stack * ptr)
{
    if (ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int isFull(stack * ptr)
{
    if (ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    stack *s=new stack();
    // stack q;
    // s=&q;
    s->size=5;
    s->top=-1;
    s->arr=new int [s->size];
    s->arr[0]=22;
    s->top++;
    s->arr[1]=2;
    s->top++;
    s->arr[2]=2;
    s->top++;
    s->arr[3]=2;
    s->top++;
    
    if (isEmpty(s))
    {
        cout<<"Stack is Empty";
    }
    if (isFull(s))
    {
        cout<<"Stack is Full";
    }
    delete s;
    return 0;
}