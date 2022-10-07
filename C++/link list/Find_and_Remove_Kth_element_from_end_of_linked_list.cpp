//Given the head of a linked list, remove the nth node from the end of the list and return its head.

//Approach--
//We can use two pointers here to find solution in more optimized way
//What if when our last pointer reaches end and other pointer reaches the element we want to delete idea is same
//initially we move second pointer by the n ( we want to delete nth last element).
//now we have difference of n in between two nodes
//Now we will move both pointers simultaneously till second pointer reaches NULL
//delete the element on first pointer

#include<bits/stdc++.h>
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

void printlist(Node * node)
{
	while (node != NULL)
	{
		cout << node->data << "->";
		node = node->next;
	}
	cout << "NULL" << endl;
}

Node* removeNthFromEnd(Node* head, int n) 
{
    Node* first = head;
    Node* last = head;
    
    //move last node by n positions
    for( int i = 0 ; i<n ; i++)
    {
        last = last ->next;
    }
    
    //edge last on null 
    if( last == NULL)
    {
        return head->next;
    }
    
    //move both pointers simultan
    while(last->next)
    {
        last = last->next;
        first = first->next;
    }
    
    first->next = first->next->next;
    
    return head;
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
   
    //lets remove third node i.e of value 5
    //before removing the third element
    printlist(n1);                          //1->2->5->7->6->NULL
    n1 = removeNthFromEnd(n1, 3); 
    
    //after removing the third element
    printlist(n1);                          //1->2->7->6->NULL
    return 0;
}