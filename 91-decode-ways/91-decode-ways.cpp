class Solution {
    vector<int> dp;
public:
    int solve(string &s, int idx){
        if(idx > s.length() || s[idx] == '0') return 0;
        // It is now guranteed that the digit we are at is non zero
        
        if(idx == s.length()) return 1;
        
        if(dp[idx] != -1) return dp[idx];
        
        int ans = 0;
        
        // The digit we are at has to be '1' to '9'
        ans += solve(s, idx + 1);
        
        // We must check if the 2 digit number getting formed from this idx is valid
        if(idx + 1 < s.length()){
            int num = stoi(s.substr(idx, 2));
            
            if(num >= 10 && num <= 26) ans += solve(s, idx + 2);
        }
        
        return dp[idx] = ans;
    }
    int numDecodings(string s) {
        dp.resize(s.length(), -1);
        return solve(s, 0);
    }
};