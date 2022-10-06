#include<iostream>
#include<string.h>


using namespace std;
// infix to postfix expersion using stack convert... [imple.. with array]

class stack
{
    public:
        int top;
        char *arr;
        int size;
};

int isFull(stack * st)
{
    if (st->size-1==st->top)
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
    return 0;
}

void push(stack * st, char exp)
{
    if (isFull(st))
    {
        cout<<"stack is overflow... can't push element"<<endl;
        return ;
    }

    st->top++;
    st->arr[st->top]=exp;

}
char pop(stack * st)
{
    if (isEmpty(st))
    {
        cout<<"stack is underflow...";
        return -1;
        
    }
    else
    {
        char val=st->arr[st->top];
        st->top--;
        return val;
    }
    
}
int isOperator(char ch)
{
    if (ch=='*'||ch=='+'||ch=='-'||ch=='/'||ch=='^'||ch=='(')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int precedence(char ch)
{
    if (ch=='(')
    {
        return 4;
    }
    if (ch=='^')
    {
        return 3;
    }
    if (ch=='/'||ch=='*')
    {
        return 2;
    }
    if (ch=='+'||ch=='-')
    {
        return 1;
    }
    return 0;
    
}
char stacktop(stack *st )
{
    char val=st->arr[st->top];
    return val;
}

char * infixtopostfix(char* exp)
{
    
    int j=0;
    stack *st = new stack();
    st->size=100;
    st->arr=new char [st->size];
    st->top=-1;
    char * postfix = new char [strlen(exp)+1];
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if (!(isOperator(exp[i])))
        {
            postfix[j]=exp[i];
            j++;
        }
        else
        {
            if (precedence(exp[i])>precedence(stacktop(st)))
            {
                push(st,exp[i]);
            }
            else{
                postfix[j]=pop(st);
                j++;
            }
            
        }
    }
    while (!isEmpty(st))
    {
        postfix[j]=pop(st);
        j++;
    }
    
    delete st;
     postfix[j]='\0';
    return postfix;
}

int main()
{
    char infix[100];
    cout<<"Enter Infix Expression : "<<endl;
    cin>>infix;

    cout<<"The postfix expersion is : "<<infixtopostfix(infix)<<endl;
    return 0;
}