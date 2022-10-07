Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.

// code
// C++ program for flattening a Linked List
#include <bits/stdc++.h>
using namespace std;

// Link list node
class Node {
public:
	int data;
	Node *right, *down;
};

Node* head = NULL;

Node* merge(Node* a, Node* b)
{

	
	if (a == NULL)
		return b;

	if (b == NULL)
		return a;

	// Compare the data members of the two linked
	// lists and put the larger one in the result
	Node* result;

	if (a->data < b->data) {
		result = a;
		result->down = merge(a->down, b);
	}

	else {
		result = b;
		result->down = merge(a, b->down);
	}
	result->right = NULL;
	return result;
}

Node* flatten(Node* root)
{


	if (root == NULL || root->right == NULL)
		return root;

	root->right = flatten(root->right);

	root = merge(root, root->right);


	return root;
}

Node* push(Node* head_ref, int data)
{

	
	Node* new_node = new Node();

	new_node->data = data;
	new_node->right = NULL;

	
	new_node->down = head_ref;


	head_ref = new_node;

	return head_ref;
}

void printList()
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->down;
	}
	cout << endl;
}

// Driver's code
int main()
{
	head = push(head, 30);
	head = push(head, 8);
	head = push(head, 7);
	head = push(head, 5);

	head->right = push(head->right, 20);
	head->right = push(head->right, 10);

	head->right->right = push(head->right->right, 50);
	head->right->right = push(head->right->right, 22);
	head->right->right = push(head->right->right, 19);

	head->right->right->right
		= push(head->right->right->right, 45);
	head->right->right->right
		= push(head->right->right->right, 40);
	head->right->right->right
		= push(head->right->right->right, 35);
	head->right->right->right
		= push(head->right->right->right, 20);

	// Function call
	head = flatten(head);

	printList();
	return 0;
}

