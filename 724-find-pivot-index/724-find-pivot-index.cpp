// TC: O(N)
// SC: O(N)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefL = nums, prefR = nums;
        
        int n = nums.size();
        for(int i = 1; i < n; ++i){
            prefL[i] += prefL[i - 1];
            prefR[n - i - 1] += prefR[n - i];
        }
        
        for(int i = 0; i < n; ++i){
            if(prefL[i] == prefR[i])
                return i;
        }
        
        return -1;
    }
};