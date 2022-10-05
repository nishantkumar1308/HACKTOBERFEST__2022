#include<iostream>
using namespace std;
//parenthesis matching program...
class stack
{
    public :
    char *arr;
    int top;
    int size;
};
int isFull(stack *st)
{
    if (st->top==st->size-1)
    {
        return 1;
    }
    return 0;
    
}
int isEmpty(stack *st)
{
    if (st->top==-1)
    {
        return 1;
    }
    return 0;
}
void push(stack * st,char val)
{
    if (isFull(st))
    {
        cout<<"Stack is overflow can't push into stack !!"<<endl;
        return;
    }
    else
    {
        st->top++;
        st->arr[st->top]=val;


    }
    
}
char pop (stack *st)
{
    if (isEmpty(st))
    {
        cout<<"Stack is underflow can't pop operation processed..."<<endl;
        return -1;
    }
    char val=st->arr[st->top];
    st->top--;
    return val;
}
int parenthesis_match(char *exp)
{
    stack *sp=new stack();
    sp->size=100;
    sp->top=-1;
    sp->arr=new char [sp->size];
    for (int  i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i]=='(')
        {
            push(sp,exp[i]);
        }
        if (exp[i]==')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            
            pop(sp);
        }
        
        
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}
int main()
{
    
    char  exp[] = "()434+(((93+k)+)o)";
    if (parenthesis_match(exp))
    {
        cout<<"The parenthesis is Matching "<<endl;
    }
    else
    {
        cout<<"The parenthesis is Not Matching "<<endl;

    }
    
    return 0;
}