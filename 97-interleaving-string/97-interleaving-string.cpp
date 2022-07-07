class Solution {
    int dp[101][101][201];
public:
    bool solve(string &s1, int idx1, string &s2, int idx2, string &s3, int idx3){
        int len[3] = {(int)s1.length(), (int)s2.length(), (int)s3.length()};
        
        if(dp[idx1][idx2][idx3] != -1) return dp[idx1][idx2][idx3];
        
        if(idx3 == len[2] && idx2 == len[1] && idx1 == len[0]) return dp[idx1][idx2][idx3] = true;
        
        if(idx1 == len[0] && idx2 == len[1]) return dp[idx1][idx2][idx3] = false;
     
        if(idx1 == len[0]){
            if(s2[idx2] != s3[idx3]) return dp[idx1][idx2][idx3] = false;
            if(solve(s1, idx1, s2, idx2 + 1, s3, idx3 + 1)) return dp[idx1][idx2][idx3] = true;
            return dp[idx1][idx2][idx3] = false;
        }
        
        if(idx2 == len[1]){
            if(s1[idx1] != s3[idx3]) return dp[idx1][idx2][idx3] = false;
            if(solve(s1, idx1 + 1, s2, idx2, s3, idx3 + 1)) return dp[idx1][idx2][idx3] = true;
            return dp[idx1][idx2][idx3] = false;
        }
        
        if(s1[idx1] != s3[idx3] && s2[idx2] != s3[idx3]) return dp[idx1][idx2][idx3] = false;
        
        if(s1[idx1] == s3[idx3] && s2[idx2] == s3[idx3]){
            if(solve(s1, idx1 + 1, s2, idx2, s3, idx3 + 1) || solve(s1, idx1, s2, idx2 + 1, s3, idx3 + 1))
                return dp[idx1][idx2][idx3] = true;
        }
        
        if(s1[idx1] == s3[idx3]){
            if(solve(s1, idx1 + 1, s2, idx2, s3, idx3 + 1))
                return dp[idx1][idx2][idx3] = true;
        }
        
        if(s2[idx2] == s3[idx3]){
            if(solve(s1, idx1, s2, idx2 + 1, s3, idx3 + 1))
                return dp[idx1][idx2][idx3] = true;
        }
        
        return dp[idx1][idx2][idx3] = false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof dp);
        return solve(s1, 0, s2, 0, s3, 0);
    }
};