//Given the head of a singly linked list, return the middle node of the linked list.

//Approach--
//Idea is to take two pointers one fast and one slow
//when slow pointer will pass one node fast pointer crosses two nodes
//initially both poiters are at head
//we can say that speed of fast pointer is twice as slow pointer 
//so when fast pointer reaches end we can say that slow pointer will reach midway thats nothing but the middle element

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

Node* middleNode(Node* head) {
    Node * slow = head;
    Node * fast = head;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<slow->data;
    return slow;
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
    
    printlist(n1);  //1->2->5->7->6->NULL
    //middle element will get printed
    Node* ans = middleNode(n1);
    cout<<ans->data; 

    return 0;
}