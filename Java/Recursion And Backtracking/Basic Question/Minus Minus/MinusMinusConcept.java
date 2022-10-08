public class MinusMinusConcept {
    public static void main(String[] args) {

    }

    static void fun(int n){
        if(n==0){
            return;
        }
        System.out.println(n);
        fun(--n);//5 4 3 2 1
//        fun(n--); // 5 5 5 5 5 5 5 ....infinitely
    }
}
