//Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

//Approach--
//iterate through the list and while iterating push each node reference to the unordered hashmap 
//along with the node reference increment its frequency so that when we get the frequency as 2 we will return the node
//unordered hashmap takes O(1) time to search the element so its quite efficient way 

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

Node *detectCycle(Node *head) 
{
    Node * temp = head;
    unordered_map<Node *, int> map;
    
    while(temp)
    {
        map[temp]++;
        if (map[temp]==2)
        {
            return temp;
        }
        temp = temp->next;
    }
    return temp;
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
    n5->next = n3;  //1->2->5->7->6--   here cycle is formed at 5   
                    //      ^_______|                  
    
    //value at which cycle is starting is 5
    Node* ans = detectCycle(n1);
    cout<<ans->data; 

    return 0;
}