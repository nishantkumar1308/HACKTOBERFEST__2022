public class NQueens {

    int n;
    int x[];
    int solutions;
    public NQueens(int n)
    {
        this.n = n;
        x = new int[n];
        solutions = 0;
    }

    public void queens(int k, int n)
    {
        for(int i=0;i<n;i++)
        {
            if(place(k,i))
            {
                x[k] = i;
                if(k==n-1) {
                    displayX();
                    solutions++;
                }
                else
                    queens(k+1,n);
            }
        }
    }

    public boolean place(int k, int i)
    {
        for(int j=0;j<k;j++)
            if((x[j]==i) || (Math.abs(x[j]-i)==Math.abs(j-k)))
                return false;
        return true;
    }

    public void displayX()
    {
        for(int i=0;i<n;i++)
            System.out.print(x[i]+"\t");
        System.out.println();
    }

    public static void main(String args[])
    {
        int n = 4;
        for(int i=1;i<=n;i++) {
            NQueens q = new NQueens(n);
            q.queens(0, n);
            System.out.println("Solutions for "+n+": " + q.solutions);
        }
    }
}
