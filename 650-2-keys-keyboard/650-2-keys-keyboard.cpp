class Solution {
    int ans;
public:
    bool minOps(int curStrLen, int prevCopyLen, int ops, int n){
        if(curStrLen > n) return false;
        
        if(curStrLen == n){
            ans = min(ans, ops);
            return true;
        }
        
        // copy and paste
        if(minOps(2*curStrLen, curStrLen, ops + 2, n)) return true;
            
        // paste previous
        if(minOps(curStrLen + prevCopyLen, prevCopyLen, ops + 1, n)) return true;
        
        return false;
    }
    int minSteps(int n) {
        ans = INT_MAX;
        int curStrLen = 1;
        int prevCopyLen = 0;
        int ops = 0;
        
        minOps(curStrLen, prevCopyLen, ops, n);
        
        return ans;
    }
};