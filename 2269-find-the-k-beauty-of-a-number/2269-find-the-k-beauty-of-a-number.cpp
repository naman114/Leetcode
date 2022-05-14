class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string n = to_string(num);
        int len = n.length();
        
        int ans = 0;
        for(int i = 0; i <= len - k; ++i){
            int div = stoi(n.substr(i, k));
            if(div != 0 && num % div == 0) ans++;
        }
        
        return ans;
    }
};