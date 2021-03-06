//TC: O(N)
//SC: O(1)

// One pass

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        int pL = 1, pR = 1;
        
        for(int i = 0; i < n; ++i){
            // For the first element, pL is 1 i.e. nothing
            ans[i] *= pL;
            pL *= nums[i];
            ans[n - i - 1] *= pR;
            pR *= nums[n - i - 1];
        }
        
        return ans;
    }
};

/*

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        
        int pL = 1;
        
        for(int i = 0; i < nums.size() - 1; ++i){
            pL *= nums[i];
            ans[i + 1] *= pL;
        }
        
        int pR = 1;
        
        for(int i = nums.size() - 1; i >= 1; --i){
            pR *= nums[i];
            ans[i - 1] *= pR;
        }
        
        return ans;
    }
};

*/

/*
// TC: O(N)
// SC: O(N)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefL = nums, prefR = nums;
        
        
        for(int i = 1; i < nums.size() - 1; ++i){
            prefL[i] *= prefL[i - 1];
        }
        
        for(int i = nums.size() - 2; i >= 1; --i){
            prefR[i] *= prefR[i + 1];
        }
        
        vector<int> ans(nums.size(), 1);
        
        for(int i = 0; i < nums.size(); ++i){
            if(i >= 1)
                ans[i] *= prefL[i - 1];
            if(i < nums.size() - 1)
                ans[i] *= prefR[i + 1];
        }
        
        return ans;
    }
};
*/