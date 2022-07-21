class Solution {
public:
    int lcs(string a, string b){
        int n1 = a.length();
        int n2 = b.length();
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        
        for(int i = 1; i <= n1; ++i){
            for(int j = 1; j <= n2; ++j){
                if(a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        
        return dp[n1][n2];
    }
    
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        return lcs(s, rev);
    }
};