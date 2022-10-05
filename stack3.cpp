#include<iostream>
// Stack operation while implementating using array
using namespace std;
class stack
{
    public:
    int size;
    int *arr;
    int top;
};
int isFull(stack *ptr)
{
    if (ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(stack *ptr)
{
    if (ptr->top==-1)
    {
        return 1;
    }
    return 0;
}
void push(stack *ptr,int val)
{
    if (isFull(ptr))
    {
        cout<<"Stack is Overflow !! can't push element "<<val<<endl;
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top]=val;
    cout<<"Element Push Successfully"<<endl;
    
}
int pop(stack *ptr)
{
    if(isEmpty(ptr))
    {
        cout<<"Stack is Underflow !! can't pop"<<endl;
        return -1;
    }
   
        int tempval=ptr->arr[ptr->top];
        ptr->top--;
        cout<<"pop Successfully"<<endl;
        return tempval;
    
}
void disp(stack * ptr)
{
    for (int i = 0; i <=ptr->top; i++)
    {
        cout<<ptr->arr[i]<<" ";
    }
    
}
int peek(stack *st,int pos)
{
    int arrindex=st->top-pos+1;
    if (arrindex<0)
    {
        cout<<"Invalid postion";
        return -1;
    }
    else
    {
        return st->arr[arrindex];
    }
    
}
int top(stack *st)
{
    return st->arr[st->top];
}
int topbottom(stack *st)
{
    return st->arr[0];
}

int menu()
{
    cout<<"***********Menu*************"<<endl;
    cout<<"1. push"<<endl;
    cout<<"2. pop"<<endl;
    cout<<"3. display"<<endl;
    cout<<"4. Peek"<<endl;
    cout<<"5. find top"<<endl;
    cout<<"6. find top of bottom"<<endl;
    cout<<"7. Exit"<<endl;
    int ch;
    cout<<"Enter your own choice : ";
    cin>>ch;
    return ch;
}
int main()
{
    stack *st= new stack();
    st->size=10;
    st->top=-1;
    st->arr=new int[st->size];
    int val;
    int temp;
    int pos;
    cout<<"Stack is creating successfully "<<endl;
    while (1)
    {
        switch (menu())
        {
        case 1:
            cout<<"Enter Elemnent : ";
            cin>>val;
            push(st,val);
            break;
        
        case 2:
            
            pop(st);
            break;
        
        case 3 :
            disp(st);
            break;
        case 5 :
            cout<<"The top most element in stack is : "<<top(st);
            break;
        case 6 :
            cout<<"The bottom most element in stack is : "<<topbottom(st);
            break;
        case 4 :
        cout<<"Enter postion";
        cin>>pos;
            temp=peek(st,pos);
            cout<<"The Element/Value of at postion "<<pos<< " is "<<temp<<endl;
            break;
        
        case 7 :
        cout<<"Thank you ! for using my application...";
            exit(0);
            break;
        
        default:
        cout<<"Opps!! Invalid Choice ";
            break;
        }
        
    }
    
    // push(st,20);
    // push(st,20);
    // pop(st);
    // push(st,20);
    // push(st,55);
    // push(st,20);
    // push(st,26);
    // push(st,80);
    // push(st,20);
    // push(st,20);
    // push(st,20);
    // push(st,90);
    // disp(st);
    
    return 0;
}