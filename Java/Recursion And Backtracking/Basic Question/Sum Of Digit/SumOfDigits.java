public class SumOfDigits {
    public static void main(String[] args) {
        System.out.println("Sum of digit of 123456789 = "+ sumOfDigit(123456789));
    }
    static int  sumOfDigit(int n){
        if(n== 0 ){
            return 0 ;
        }

        return  (n%10)+sumOfDigit(n/10);
    }
}
