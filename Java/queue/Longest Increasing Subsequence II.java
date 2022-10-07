class Solution {

    int N = 100001;
    int[] seg = new int[2*N];
    
    void update(int pos, int val){  // update max
        pos += N;
        seg[pos] = val;
 
        while (pos > 1) {
            pos >>= 1;
            seg[pos] = Math.max(seg[2*pos], seg[2*pos+1]);
        }
    }
 
    int query(int lo, int hi){ // query max [lo, hi)
        lo += N;
        hi += N;
        int res = 0;
 
        while (lo < hi) {
            if ((lo & 1)==1) {
                res = Math.max(res, seg[lo++]);
            }
            if ((hi & 1)==1) {
                res = Math.max(res, seg[--hi]);
            }
            lo >>= 1;
            hi >>= 1;
        }
        return res;
    }
    
    public int lengthOfLIS(int[] A, int k) {
        int ans = 0;
        for (int i = 0; i < A.length; ++i){
            int l = Math.max(0, A[i]-k);
            int r = A[i];
            int res = query(l, r) + 1; // best res for the current element
            ans = Math.max(res, ans);
            update(A[i], res); // and update it here
        }
        return ans;
    }
}
