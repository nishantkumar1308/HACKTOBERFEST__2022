public class steps {
    public static void main(String[] args) {
        System.out.println(steps(13));
    }

    static int steps(int n){
        return helper(n,0);
    }

    private static int helper(int n , int countStep){
        if(n==0){
            return countStep;
        }

        if (n%2==0){
            return helper(n/2,countStep+1);
        }
        return helper(n-1,countStep+1);
    }
}
