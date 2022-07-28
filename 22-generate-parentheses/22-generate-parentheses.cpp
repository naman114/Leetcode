class Solution {
public:
    vector<string> solve(string ans, int osf, int csf, int n){
        vector<string> res;
        
        if(ans.length() == 2*n){
            if(osf == csf)
                res.push_back(ans);
            return res;
        }
        
        vector<string> open = solve(ans + '(', osf + 1, csf, n);
        
        for(string s: open) res.push_back(s);
        
        // Ensures that the parantheses are in order
        // Without this condition, it will put them in any order i.e. ()())( would be printed as well
        if(osf > csf){
            vector<string> closed = solve(ans + ')', osf, csf + 1, n);
            for(string s: closed) res.push_back(s);
        }
        
        return res;
    }
    vector<string> generateParenthesis(int n) {
        return solve("", 0, 0, n);
    }
};