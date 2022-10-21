public class OnetoN {
    // Space complexity: O(n)
    // Time Complexity: O(n)
    public static void main(String[] args) {

        function(5);// Print 1 2 3 4 5
    }

    static void function(int n){
        if (n==0) {
            return;

        }
        function(n-1);
        System.out.print(n+" ");
    }
}
