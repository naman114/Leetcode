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