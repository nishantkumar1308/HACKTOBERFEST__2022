public class reverseANumber {

    static  int sum =0;
    static void method1(int n ){
        if(n==0){
            return;
        }
        int rem = n%10;
        sum = sum*10 + rem;
        method1(n/10);
    }

    static int method2(int n){

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

    public static void main(String[] args) {
            method1(1234);
        System.out.println("Using 1st method");
        System.out.println(sum);
        System.out.println("using 2ed Method");
        System.out.println(method2(1234));
    }
}
