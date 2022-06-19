class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps = {1, 2};
        vector<int> dp(n + 1);
        dp[0] = 1;
        
        for(int i = 1; i <= n; ++i){
            for(int step: steps){
                if(i - step >= 0){
                    dp[i] += dp[i - step];
                }        
            }
        }
        
        return dp[n];
    }
};