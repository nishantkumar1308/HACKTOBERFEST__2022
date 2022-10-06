/* 
Given two linked lists, insert nodes of second list into first list at alternate positions
 of first list. For example, if first list is 5->7->17->13->11 and second is 
 12->10->2->4->6, the first list should become 5->12->7->10->17->2->13->4->11->6 and 
 second list should become empty. The nodes of second list should only be inserted when 
 there are positions available. For example, if the first list is 1->2->3 and second list
  is 4->5->6->7->8, then first list should become 1->4->2->5->3->6 and second list to 
  7->8.

Use of extra space is not allowed (Not allowed to create additional nodes), i.e., 
insertion must be done in-place. Expected time complexity is O(n) where n is number of 
nodes in first list. 

*/

class LinkedList
{
    Node head;  // head of list
  
    /* Linked list Node*/
    class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }
  
    /* Inserts a new Node at front of the list. */
    void push(int new_data)
    {
        /* 1 & 2: Allocate the Node &
                  Put in the data*/
        Node new_node = new Node(new_data);
  
        /* 3. Make next of new Node as head */
        new_node.next = head;
  
        /* 4. Move the head to point to new Node */
        head = new_node;
    }
  
    // Main function that inserts nodes of linked list q into p at
    // alternate positions. Since head of first list never changes
    // and head of second list/ may change, we need single pointer
    // for first list and double pointer for second list.
    void merge(LinkedList q)
    {
        Node p_curr = head, q_curr = q.head;
        Node p_next, q_next;
  
        // While there are available positions in p;
        while (p_curr != null && q_curr != null) {
  
            // Save next pointers
            p_next = p_curr.next;
            q_next = q_curr.next;
  
            // make q_curr as next of p_curr
            q_curr.next = p_next; // change next pointer of q_curr
            p_curr.next = q_curr; // change next pointer of p_curr
  
            // update current pointers for next iteration
            p_curr = p_next;
            q_curr = q_next;
        }
        q.head = q_curr;
    }
  
    /* Function to print linked list */
    void printList()
    {
        Node temp = head;
        while (temp != null)
        {
           System.out.print(temp.data+" ");
           temp = temp.next;
        }
        System.out.println();
    }
  
    public static void main(String args[])
    {
        LinkedList llist1 = new LinkedList();
        LinkedList llist2 = new LinkedList();
        llist1.push(3);
        llist1.push(2);
        llist1.push(1);
  
        System.out.println("First Linked List:");
        llist1.printList();
  
        llist2.push(8);
        llist2.push(7);
        llist2.push(6);
        llist2.push(5);
        llist2.push(4);
  
        System.out.println("Second Linked List:");
  
        llist1.merge(llist2);
  
        System.out.println("Modified first linked list:");
        llist1.printList();
  
        System.out.println("Modified second linked list:");
        llist2.printList();
    }
} 