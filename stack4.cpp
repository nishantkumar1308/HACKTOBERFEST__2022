// Stack operation while implementating using Linked list
#include<iostream>
using namespace std;
class stack
{
    public:
        int data;
        stack * next= NULL;
};
int peek(int pos,stack* top)
{
    int i=0;
    stack *ptr=top;
    while (i<pos && ptr!=NULL)
    {
        ptr=ptr->next;
        i++;
    }
    if (ptr!=NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
    
    
}
int isFull(stack * top)
{
    stack * n=new stack();
    if(n==NULL)
    {
        return 1;
    }
    else
    {
    
        return 0;
    }
}
int isEmpty(stack * top)
{
    
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
stack* push(int data,stack *top)
{
    stack *ptr=new stack();
    if(isFull(top))
    {
        cout<<"Stack is Overflow "<<endl;
        return NULL;
        
    }
    else
    {
    ptr->data=data;
    ptr->next=top; 
    top=ptr;
    cout<<"One Element push successfully "<<endl;
    return top;
    }
}
stack* pop (stack * top)
{
    if (isEmpty(top))
    {
        cout<<"Stack is underflow"<<endl;
        return NULL;
    }
    else
    {
        stack * ptr = top;
        top=top->next;
        delete ptr;
        cout<<"one element pop successfully"<<endl;
        return top;
            
    }
    

}
int topmost(stack * top)
{
    return top->data;
}
int topbottom(stack * top)
{
    stack *ptr;
    ptr=top;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    return ptr->data;
    
}
void printlist(stack * top)
{
    stack * ptr=top;
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

}
int menu()
{
    int ch ;
    cout<<"1.Push "<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.Peek"<<endl;
    cout<<"4.Top Element"<<endl;
    cout<<"5.Top Bottom Element"<<endl;
    cout<<"6.Display it"<<endl;
    cout<<"7.isFull"<<endl;
    cout<<"8.isEmpty"<<endl;
    cout<<"9.Exit"<<endl;
    cout<<"Enter your own choice : ";
    cin>>ch;
    return ch;

}
int main()
{
    stack *top = NULL;
    int ele;
    // top=push(60,top);
    // top=push(550,top);
    // cout<<"Before : ";
    // printlist(top);
    // top=pop(top);
    // cout<<"After : ";
    // printlist(top);
    // cout<<endl<<"The Top most Element is : "<<topmost(top);
    // cout<<endl<<"The Top most Bottom Element is : "<<topbottom(top);
    while(1)
    {
        switch(menu())
        {
            case 1: 
                cout<<"Enter Element : ";
                cin>>ele;
                top=push(ele,top);
                break;
            case 2:
                top=pop(top);
                break;
            case 3:
                cout<<"Enter which one postion you peek ?"<<endl;
                int pos;
                cin>>pos;
                cout<<"The Element of postion "<<pos<<" is "<<peek(pos,top)<<endl;
                break;
            case 9:
                cout<<"Thanks for using this software :/ "<<endl;
            exit(0);
            break;
            case 6 :
                printlist(top);
                break;
            case 4:
                cout<<"The top most element is : "<<topmost(top)<<endl;
                break;
            case 5:
                cout<<"The most top of bottom element is : "<<topbottom(top)<<endl;
                break;
            case 7:
                if (isFull(top))
                {
                    cout<<"Stack is overflow !!"<<endl;
                }
                else
                {
                    cout<<"Stack is Not full !! "<<endl;
                }
                break;
            case 8:
                if(isEmpty(top))
                {
                    cout<<"Stack is underflow !!"<<endl;
                }
                else{
                    cout<<"Stack is not Empty "<<endl;
                }
                break;
            default :
                cout<<"Invalid Error Try Again :/"<<endl;
                break;


        }
    }
    delete top;
    return 0;
}