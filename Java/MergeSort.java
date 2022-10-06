public class MergeSort {

    public void mergesort(int A[], int left, int right) {
        if(left < right) {
            int mid = (left + right) / 2;
            mergesort(A, left, mid);
            mergesort(A, mid+1, right);
            merge(A, left, mid, right);
        }
    }

    public void merge(int A[], int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int k = left;
        int B[] = new int[right+1];
        while(i <= mid && j <=right) {
            if(A[i] < A[j]) {
                B[k] = A[i];
                i = i + 1;
            }
            else {
                B[k] = A[j];
                j = j + 1;
            }
            k = k + 1;
        }
        while(i<=mid) {
            B[k] = A[i];
            i = i + 1;
            k = k + 1;
        }
        while(j<=right) {
            B[k] = A[j];
            j = j + 1;
            k = k + 1;
        }
        for(int x=left;x<right+1;x++)
            A[x] = B[x];
    }

    public void display(int A[], int n) {
        for(int i=0;i<n;i++)
            System.out.print(A[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        MergeSort s = new MergeSort();
        int n = 1000;
        //int A[] = {3, 5, 8, 9, 6, 2};
        int A[] = new int[n];
        for(int i=0;i<n;i++)
            A[i] = (int)(Math.random()*1000);
        System.out.print("Original Array: ");
        s.display(A, n);
        long start = System.currentTimeMillis();
        s.mergesort(A, 0, A.length-1);
        long end = System.currentTimeMillis();
        System.out.print("Sorted Array: ");
        s.display(A, n);
        System.out.println("Elapse Time: "+(end - start)+" ms");
    }

}
