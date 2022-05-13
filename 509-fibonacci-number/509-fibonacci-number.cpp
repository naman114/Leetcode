// TC: O(N)
// SC: O(1)
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        
        int a = 0, b = 1;
        int c;
        
        for(int i = 1; i <= n - 1; ++i){
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
    }
};

/*
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
*/