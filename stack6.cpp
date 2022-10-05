#include<iostream>
using namespace std;
 //double parenthesis matching program...
//  complete program....
class stack
{
    public :
    int top;
    char *arr;
    int size;
};
int isFull(stack *st)
{
    if (st->top==st->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}
int isEmpty(stack *st)
{
    if (st->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
void push(stack *st,char val)
{
    if (isFull(st))
    {
        cout<<"stack is overflow !! can't push operation proccessed ....";  
        return ;
    }
    st->top++;
    st->arr[st->top]=val;
    
}
char pop (stack * st)
{
    if (isEmpty(st))
    {
        cout<<"Stack is underflow !! can't pop operation proccessed...";
        return -1;
    }
    char val=st->arr[st->top];
    st->top--;
    return val;
    
}

int match(char exp,char val)
{
    if (exp=='('&&val==')'||exp=='['&&val==']'||exp=='{'&&val=='}')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int parenthesis(char *exp)
{
    stack * st=new stack();
    st->size=100;
    st->arr=new char [st->size];
    st->top=-1; //create a stack
    char popped_ch;
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        {
            push(st,exp[i]);
        }
        else if (exp[i]==')'||exp[i]=='}'||exp[i]==']')
        {
            if (isEmpty(st))
            {
                return 0;
                
            }

            popped_ch=pop(st);
            
            if (!match(popped_ch,exp[i]))
            {
                return 0;
            }
            
            
        }
        
        
    }
    
    if (isEmpty(st))
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
    char exp[]="4+2{3+f}+{g+(o+34)}}";
    if (parenthesis(exp))
    {
        cout<<"parenthesis is matched..."<<endl;
    }
    else
    {
        cout<<"parenthesis is not matched..."<<endl;
    }
    
    
    
    return 0;
}