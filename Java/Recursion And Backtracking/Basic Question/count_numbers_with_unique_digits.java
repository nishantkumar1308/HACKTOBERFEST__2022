class Solution {
    public int countNumbersWithUniqueDigits(int n) {
         return recursion(n,0,new boolean[10]);
    }
    int recursion(int n,int curr,boolean[] vis)
    {
        if(curr == n)
            return 1;
        int res = 1;
        for(int i=(curr == 0 ? 1 : 0);i<=9;i++)
        {
            if(vis[i])
                continue;
            vis[i] = true;
            res+=recursion(n,curr+1,vis);
            vis[i] = false;
        }
        return res;
    }
}
