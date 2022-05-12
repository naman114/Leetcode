// TC: O(N)
// SC: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minJump = 0;
        
        for(int i = nums.size() - 2; i >= 0; --i){
            minJump++;
            
            if(nums[i] >= minJump)
                minJump = 0;
        }
        
        if(minJump == 0)
            return true;
        
        return false;
    }
};

/*
// TC: O(N)
// SC: O(N)
class Solution {
public:
    bool solve(vector<int> &nums, int idx, vector<int> &dp){
        if(idx == nums.size() - 1) return true;
        
        if(dp[idx] != -1) return dp[idx];
        
        for(int i = 1; i <= nums[idx] && idx + i < nums.size(); ++i){
            if(solve(nums, idx + i, dp))
                return dp[idx] = 1;
        }
        
        return dp[idx] = 0;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        
        return solve(nums, 0, dp);
    }
};
*/