public class Knapsack {

    public void knapsack(int p[], int w[], int C, int f[][])
    {
        int n = p.length - 1;
        int yMax = Math.min(w[n] - 1, C);
        for (int y = 0; y <= yMax; y++)
            f[n][y] = 0;
        for (int y = w[n]; y <= C; y++)
            f[n][y] = p[n];

        for (int i = n - 1; i > 1; i--)
        {
            yMax = Math.min(w[i] - 1, C);
            for (int y = 0; y <= yMax; y++)
                f[i][y] = f[i + 1][y];
            for (int y = w[i]; y <= C; y++)
                f[i][y] = Math.max(f[i + 1][y], f[i + 1][y - w[i]] + p[i]);
        }

        f[1][C] = f[2][C];
        if (C >= w[1])
            f[1][C] = Math.max(f[1][C], f[2][C-w[1]] + p[1]);
    }

    public void traceback(int [][] f, int [] w, int C, int [] x)
    {
        int n = w.length - 1;

        for (int i = 1; i < n; i++)
            if (f[i][C] == f[i+1][C])
                x[i] = 0;
            else
            {
                x[i] = 1;
                C -= w[i];
            }
        x[n] = (f[n][C] > 0)? 1 : 0;
    }

    public static void main(String [] args)
    {
        Knapsack k = new Knapsack();
        int n = 3;
        int c = 6;
        int [] p = {0,1,2,5};
        int [] w = {0,2,3,4};
        int [] x = new int [n + 1];
        int [][] f = new int [n + 1][c + 1];

        k.knapsack(p, w, c, f);

        System.out.println("Optimal Profit: " + f[1][c]);
        k.traceback(f, w, c, x);
        for (int i = 1; i <= n; i++)
            System.out.print(x[i] + " ");
        System.out.println();
    }

}
