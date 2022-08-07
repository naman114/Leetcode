/*
TC: O(N)
SC: O(N)

ASCII
a = 97, z = 122
A = 65, Z = 90
*/
class Solution {
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
public:
    int solve(int n, char prev, unordered_map<char, vector<char>> &ump){
        if(n == 0) return 1;
        
        if(dp[n][prev] != -1) return dp[n][prev];
        
        int ans = 0;
        
        for(char c: ump[prev]){
            ans = (ans%mod + solve(n - 1, c, ump)%mod)%mod;
        }
        
        return dp[n][prev] = ans;
    }
    int countVowelPermutation(int n) {
        dp.resize(n, vector<int>(123, -1));
        
        unordered_map<char, vector<char>> ump;
        ump['a'] = {'e'};
        ump['e'] = {'a', 'i'};
        ump['i'] = {'a', 'e', 'o', 'u'};
        ump['o'] = {'i', 'u'};
        ump['u'] = {'a'};
        
        int ans = 0;
        
        for(auto p: ump)
            ans = (ans%mod + solve(n - 1, p.first, ump)%mod)%mod;
        
        return ans;
    }
};