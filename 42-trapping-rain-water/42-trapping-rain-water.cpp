class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> lm(n), rm(n);
        
        lm[0] = 0;
        for(int i = 1; i < h.size(); ++i){
            if(h[lm[i - 1]] > h[i])
                lm[i] = lm[i - 1];
            else
                lm[i] = i;
        }
        
        rm[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; --i){
            if(h[rm[i + 1]] > h[i])
                rm[i] = rm[i + 1];
            else
                rm[i] = i;
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; ++i){
            if(lm[i] == i || rm[i] == i)
                continue;
            
            ans += min(h[lm[i]], h[rm[i]]) - h[i];
        }
        
        return ans;
    }
};