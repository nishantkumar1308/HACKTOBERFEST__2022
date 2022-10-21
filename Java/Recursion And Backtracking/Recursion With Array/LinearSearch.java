
import  java.util.*;
public class LinearSearch {
    public static  void main(String[] args) {
        int arr[]={1,2,3,4,5,6};
        int target = 3;

        System.out.println(LS(arr, target, arr[0]));
    }
    static int LS(int arr[],int target,int index){
        if(index == arr.length){
            return -1;
        }
       if( arr[index] == target ){
            return index;
        }

        return LS(arr, target, index+1);

    }
}
