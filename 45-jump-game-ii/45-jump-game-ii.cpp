// TC: O(N^2)
// SC: O(N)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX); // dp[i] means min moves to reach last idx
        dp[n - 1] = 0;
        
        for(int i = n - 2; i >= 0; --i){
            int mn = INT_MAX;
            for(int j = 1; j <= nums[i] && i + j < n; ++j){
                mn = min(mn, dp[i + j]);
            }
            // if we can reach the end
            if(mn != INT_MAX)
                dp[i] = 1 + mn;
        }
        
        return dp[0]; // since a solution always exists
    }
};