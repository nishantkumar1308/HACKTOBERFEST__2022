// Given head, the head of a linked list, determine if the linked list has a cycle in it.

//Approach--
//Idea is to take two pointers one slow pointers and one fast pointers
//if linked list has no cycle in it both pointers are never going to meet again.
//i.e fast pointer will reach its end and function will return false
//if linked list has a cycle then they are ought to meet again at some point
//when slow == fast then we can say that there is a cycle in the linked list.

#include<iostream>
using namespace std;

class Node
{
	public:
        int data;
        Node* next;
};

Node* newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

bool hasCycle(Node *head) 
{
        Node* slow =head;
        Node* fast =head;
        
        while(fast && fast->next && fast->next->next)
        {
            slow = slow ->next;
            fast = fast ->next -> next;
            if (slow == fast ) return true;
        }
        return false;
}
int main()
{
    Node* n1 = newNode(1);
    Node* n2 = newNode(2);
    Node* n3 = newNode(5);
    Node* n4 = newNode(7);
    Node* n5 = newNode(6);

    n1->next = n2;  //1->2->NULL
    n2->next = n3;  //1->2->5->NULL
    n3->next = n4;  //1->2->5->7->NULL
    n4->next = n5;  //1->2->5->7->6->NULL
    n5->next = n3;  //1->2->5->7->6--   //here cycle is  formed
                    //      ^_______|                  
    if(hasCycle(n1))
    {
        cout<<"Linked List has a cycle in it."<<endl;
    } 
    else
    {
        cout<<"Cycle Not detected."<<endl;
    }
    return 0;
}