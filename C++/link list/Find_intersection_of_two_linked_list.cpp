//Given the heads of two singly linked-lists headA and headB, 
//return the node at which the two lists intersect. 
//If the two linked lists have no intersection at all, return null.

//Approach--
/*Approach1- find length of both ll's move larger ones head by difference
           so that now both lengths are same now move two pointers simultaneously 
           and check if reference node is  same or not.                      

Approach2-Optimize same logic by moving both pointers from start when any of two reaches 
          null move let  say p1 reaches null first put p1 on l2 and move again 
          till p2 reaches NULL move p2 on l1 now you will notice both of them have same length 
          now move simultaneously and check.*/

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

Node *getIntersectionNode(Node *headA, Node *headB) {
    Node* a=headB;
    Node* b=headA;
    
    while( a != b )
    {
        if(a) a= a->next;
        else a=headB;
        
        if(b) b= b->next;
        else b= headA;
    }
    return a;
}

int main()
{
    Node* n1 = newNode(4);
    Node* n2 = newNode(1);
    Node* n3 = newNode(8);
    Node* n4 = newNode(4);
    Node* n5 = newNode(5);

    n1->next = n2;  //1->2->NULL
    n2->next = n3;  //1->2->5->NULL
    n3->next = n4;  //1->2->5->7->NULL
    n4->next = n5;  //1->2->5->7->6->NULL

    Node* l1 = newNode(11);
    Node* l2 = newNode(22);
    Node* l3 = newNode(55);
    Node* l4 = newNode(77);
    
    l1->next = l2;  //11->22->NULL
    l2->next = l3;  //11->22->55->NULL
    l3->next = l4;  //11->22->55->77->NULL
    l4->next = n3;  //11->22->55->77->5->7->6->NULL

    printlist(l1);  //11->22->55->77->8->4->5->NULL
    printlist(n1);  //4->1->8->4->5->NULL
    
    //value at which two lists are intersecting
    Node* ans = getIntersectionNode(n1, l1);
    cout<<"Both the linked lists are intersecting at node of value: "<<ans->data; 

    return 0;
}