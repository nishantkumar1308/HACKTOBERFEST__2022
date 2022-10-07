class Solution {
    public int findTheWinner(int n, int k) {
        Node firstNode = new Node(1);
        Node prevNode = firstNode;
        for(int i=2; i<=n; i++) {
            Node currentNode = new Node(i);
            currentNode.prev = prevNode;
            prevNode.next = currentNode;
            prevNode = currentNode;
        }
        firstNode.prev = prevNode;
        prevNode.next = firstNode;
        
        
        Node currentNode = prevNode;
        for(int i=0; i<n; i++) {
            for(int j=0; j<k; j++) {
                currentNode = currentNode.next;
            }
            currentNode.kill();
        }
        return currentNode.next.num;
    }
}

class Node{
    final int num;
    Node next = null;
    Node prev = null;
    
    public Node(int num) {
        this.num = num;
    }
    
    public void kill(){
        prev.next = next;
        next.prev = prev;
    }
}
