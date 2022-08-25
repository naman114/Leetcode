class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char, int> ump;
        
        for(char c: m){
            ump[c]++;
        }
        
        for(char c: r){
            if(ump[c] == 0) return false;
            ump[c]--;
        }
        
        return true;
    }
};