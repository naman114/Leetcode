/*
1. TC: O(N^2), SC: O(1) when for every idx you check for the max on the left and right

2. Prefix arrays
TC: O(N)
SC: O(N)
*/
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> lm(n), rm(n);
        
        lm[0] = h[0];
        for(int i = 1; i < h.size(); ++i) lm[i] = max(lm[i - 1], h[i]);
        
        rm[n - 1] = h[n - 1];
        for(int i = n - 2; i >= 0; --i) rm[i] = max(rm[i + 1], h[i]);
        
        int ans = 0;
        
        for(int i = 0; i < n; ++i) ans += min(lm[i], rm[i]) - h[i];
        
        return ans;
    }
};