public class Pallindrome {



    static int rev(int n){

//        Sometime u need external variables and function
        int digits = (int)(Math.log10(n))+1;
        return helper(n,digits);
    }

    private static int helper(int n, int digits) {
        if(n%10== n ){
            // For only one-digit number
            return n;

        }
        int rem = n %10;
        return (int) (rem * Math.pow(10,digits-1) + helper(n/10,digits-1));
    }

    static boolean pallin(int n){
        return n == rev(n);
    }

    public static void main(String[] args) {


        System.out.println(pallin(1234321));
    }
}
