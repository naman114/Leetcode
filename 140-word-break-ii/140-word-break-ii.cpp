class Solution {
    unordered_set<string> us;
    unordered_map<int, vector<string>> dp;
public:
    vector<string> solve(string &s, int start){
        vector<string> ans;
        int n = s.length();
        
        if(start == n){
            ans.push_back("");
            return ans;
        }
        
        if(dp.count(start)) return dp[start];
        
        string cur_string = "";
        for(int i = start; i < n; ++i){
            cur_string += s[i];
            
            if(us.count(cur_string)){
                vector<string> res = solve(s, i + 1);
                for(string res_string: res){
                    if(res_string == "")
                        ans.push_back(cur_string);
                    else
                        ans.push_back(cur_string + ' ' + res_string);
                }
            }
        }
        
        return dp[start] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        us.clear();
        for(string st: wordDict) us.insert(st);
        
        return solve(s, 0);
    }
};