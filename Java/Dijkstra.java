public class Dijkstra {

    int dist[];
    int S[];
    int n;
    int cost[][];

    public Dijkstra()
    {
        n = 6;
        cost = new int[][]{
                {0, 50, 45, 10, Integer.MAX_VALUE, Integer.MAX_VALUE},
                {Integer.MAX_VALUE, 0, 10, 15, Integer.MAX_VALUE, Integer.MAX_VALUE},
                {Integer.MAX_VALUE, Integer.MAX_VALUE, 0, Integer.MAX_VALUE, 30, Integer.MAX_VALUE},
                {20, Integer.MAX_VALUE, Integer.MAX_VALUE, 0, 15, Integer.MAX_VALUE},
                {Integer.MAX_VALUE, 20, 35, Integer.MAX_VALUE, 0, Integer.MAX_VALUE},
                {Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, 3, 0},
        };
        dist = new int[n];
        S = new int[n];
    }

    public void shortestPaths(int v)
    {
        for(int i=0;i<n;i++)
        {
            S[i] = 0;
            dist[i] = cost[v][i];
        }
        S[v] = 1;
        dist[v] = 0;
        for(int i=1;i<n-1;i++)
        {
            int u = minDist();
            S[u] = 1;
            for(int w=0;w<n;w++)
            {
                if(cost[u][w]!=0 && cost[u][w]!=Integer.MAX_VALUE && S[w]==0)
                {
                    if (dist[w] > dist[u] + cost[u][w])
                        dist[w]= dist[u] + cost[u][w];
                }
            }
        }
    }

    public int minDist()
    {
        int min = Integer.MAX_VALUE;
        int u = -1;
        for(int i=0;i<n;i++)
            if(dist[i]<min && S[i]!=1) {
                min = dist[i];
                u = i;
            }
        return u;
    }

    public void displayDist()
    {
        for(int i=0;i<n;i++)
            System.out.print(dist[i]+"\t");
        System.out.println();
    }

    public static void main(String args[])
    {
        Dijkstra d = new Dijkstra();
        d.shortestPaths(0);
        d.displayDist();
    }
}
