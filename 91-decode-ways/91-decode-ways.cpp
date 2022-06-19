/*
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        int a = 1, b = 0;
        
        for(int i = n - 1; i >= 0; --i){
            int temp = 0;
            if(s[i] != '0'){
                temp += a;
            }
            
            if(i + 1 < n){
                int num = stoi(s.substr(i, 2));
            
                if(num >= 10 && num <= 26) temp += b;
            }
            
            b = a;
            a = temp;
        }
        
        return a;
    }
};

/*
Bottom Up
TC: O(N)
SC: O(N)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        vector<int> dp(n + 2);
        dp[n + 1] = 0;
        dp[n] = 1;
        
        
        for(int i = n - 1; i >= 0; --i){
            if(s[i] != '0'){
                dp[i] += dp[i + 1];
            }
            
            if(i + 1 < n){
                int num = stoi(s.substr(i, 2));
            
                if(num >= 10 && num <= 26) dp[i] += dp[i + 2];
            }
        }
        
        return dp[0];
    }
};
*/

/*
Rec + Memo
Top Down
TC: O(N)
SC: O(N)

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
*/