class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0; // dp[i] means number of set bits in i
        
        for(int i = 1; i <= n; ++i)
            dp[i] = dp[i>>1] + (i&1);
            
        return dp;
    }
};

/*
TC: O(NlogN)
SC: O(N)

class Solution {
public:
    int count(int n){
        int cnt = 0;
        while(n){
            cnt += n&1;
            n >>= 1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for(int i = 0; i <= n; ++i){
            ans[i] = count(i);
        }
        return ans;
    }
};
*/