class Solution {
    unordered_set<string> us;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        us.clear();
        
        for(string st: wordDict) us.insert(st);
        
        vector<int> dp(n + 1);
        dp[n] = 1;
        
        for(int i = n - 1; i >= 0; --i){
            
            string cur_string = "";
            
            for(int j = i; j < n; ++j){
                cur_string += s[j];
                
                if(us.count(cur_string)){
                    if(dp[j + 1]){dp[i] = 1; break;}
                }   
            }
    
        }
        
        
        return dp[0];
    }
};

/*
Top Down

class Solution {
    unordered_set<string> us;
    vector<int> dp;
public:
    bool solve(string &s, int start){
        int n = s.length();
        
        if(start == n) return true;
        
        if(dp[start] != -1) return dp[start];
        
        string cur_string = "";
        for(int i = start; i < n; ++i){
            cur_string += s[i];
            
            if(us.count(cur_string)){
                if(solve(s, i + 1)) return dp[start] = true;
            }
        }
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        us.clear();
        dp.resize(n, -1);
        
        for(string st: wordDict) us.insert(st);
        
        return solve(s, 0);
    }
};

*/