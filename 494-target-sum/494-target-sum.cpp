class Solution {
public:
    int solve(vector<int>& nums, int target){
        int n = nums.size();
        int dp[n + 1][target + 1];
        
        vector<int> prefZero(n);
        prefZero[0] = (nums[0] == 0);
        
        for(int i = 1; i < n; ++i) prefZero[i] = prefZero[i - 1] + (nums[i] == 0);
        
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= target; ++j){
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                
                else if(j == 0)
                    dp[i][j] = pow(2, prefZero[i - 1]);
                
                else if(i == 0)
                    dp[i][j] = 0;
                
                else if(j - nums[i - 1] >= 0)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[n][target];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
        s1 + s2 = sum
        s1 - s2 = target
        
        2*s1 = sum + target
        */
        
        int sum = 0;
        for(int num: nums) sum += num;
        
        if((sum + target) & 1) return 0;
        if((sum + target < 0)) return 0;
        target = (sum+target)/2;
        
        return solve(nums, target);
    }
};