/*
Recurrence Relation
dp[i] = dp[i - 1] + dp[i - 2]
i == 0 return 1;
i < 0 return 0;
*/
class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        
        return solve(n, dp);
    }
};

/*
Permutations
TC: O(N)
SC: O(N)

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

*/