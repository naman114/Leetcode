/*
1. TC: O(N^2), SC: O(1) when for every idx you check for the max on the left and right

2. Prefix max and suffix max arrays
TC: O(N)
SC: O(N)

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

*/

/*
3. 2 Pointers (Most optimal)
TC: O(N)
SC: O(1) 
*/

class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        
        int l = 0, r = n - 1;
        int LMaxHeight = 0, RMaxHeight = 0;
        int ans = 0;
        
        while(l <= r){
            if(h[l] <= h[r]){
                if(h[l] >= LMaxHeight) LMaxHeight = h[l];
                else ans += LMaxHeight - h[l];
                l++;
            }
            else{
                if(h[r] >= RMaxHeight) RMaxHeight = h[r];
                else ans += RMaxHeight - h[r];
                r--;
            }
        }
        
        return ans;
    }
};