import java.util.*;

public class Kruskal {

    public class Edge {
        public int u;
        public int v;
        public int w;
        public Edge(int u, int v, int w)
        {
            this.u = u;
            this.v = v;
            this.w = w;
        }
        public int getU(){
            return u;
        }
        public int getV(){
            return v;
        }
        public int getW(){
            return w;
        }
    }

    public class EdgeComparator implements Comparator<Edge>
    {
        public int compare(Edge e1, Edge e2)
        {
            if(e1.w > e2.w)
                return 1;
            else if (e1.w < e2.w)
                return -1;
            return 0;
        }
    }

    PriorityQueue<Edge> minHeap;

    public int n;
    public int cost[][];
    public int parent[];
    public int mincost;
    int t[][];
    public Kruskal() {
        n = 7;
        cost = new int[][]{
                {Integer.MAX_VALUE,28,Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE,10,Integer.MAX_VALUE},
                {28,Integer.MAX_VALUE,16,Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE,14},
                {Integer.MAX_VALUE,16,Integer.MAX_VALUE,12,Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE},
                {Integer.MAX_VALUE,Integer.MAX_VALUE,12,Integer.MAX_VALUE,22,Integer.MAX_VALUE,18},
                {Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE,22,Integer.MAX_VALUE,25,24},
                {10,Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE,25,Integer.MAX_VALUE,Integer.MAX_VALUE},
                {Integer.MAX_VALUE,14,Integer.MAX_VALUE,18,24,Integer.MAX_VALUE,Integer.MAX_VALUE}
        };
        parent = new int[n];
        t = new int[n][2];
    }

    public void kruskalMST()
    {
        CreateMinHaep();
        //while(!minHeap.isEmpty())
        //{
        //    Edge heap = minHeap.poll();
        //    System.out.println(heap.getU()+","+heap.getV()+","+heap.getW());
        //}
        for(int m=0;m<n;m++)
            parent[m] = -1;
        int i = 0;
        mincost = 0;
        while((i<n-1) && !minHeap.isEmpty())
        {
            Edge e = minHeap.poll();
            int u = e.getU();
            int v = e.getV();
            int j = find(u);
            int k = find(v);
            if(j!=k) {
                i = i + 1;
                t[i][0] = u;
                t[i][1] = v;
                mincost = mincost + cost[u][v];
                union(j,k);
            }
            e = minHeap.poll();
        }
        if(i!=n-1)
            System.out.println("No Spanning Tree");
        else
        {
            System.out.println("Edges:");
            for(int m=1;m<n;m++)
                System.out.println(t[m][0]+" "+t[m][1]);
            System.out.println("Min Cost: "+ mincost);
        }
    }

    public void CreateMinHaep()
    {
        int nEdges = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(cost[i][j]!=Integer.MAX_VALUE)
                    nEdges = nEdges + 1;

        minHeap = new PriorityQueue<Edge>(nEdges, new EdgeComparator());
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(cost[i][j]!=Integer.MAX_VALUE) {
                    Edge e = new Edge(i,j,cost[i][j]);
                    minHeap.add(e);
                }
    }

    public int find(int i)
    {
        while(parent[i]>0)
            i = parent[i];
        return i;
    }

    public void union(int i, int j)
    {
        parent[j] = i;
    }

    public static void main(String args[])
    {
        Kruskal kmst = new Kruskal();
        kmst.kruskalMST();
    }
}
