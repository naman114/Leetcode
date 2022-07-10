/*
TC: O(N*sum)
SC: O(N*sum)
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) sum += num;
        
        if(sum & 1) return false;
        
        int target = sum / 2;
        int n = nums.size();
        
        bool dp[n + 1][target + 1];
        
        for(int idx = 0; idx <= n; ++idx){
            for(int wt = 0; wt <= target; ++wt){
                if(wt == 0)
                    dp[idx][wt] = true;
                
                else if(idx == 0)
                    dp[idx][wt] = false;
                
                else if(wt - nums[idx - 1] >= 0)
                    dp[idx][wt] = dp[idx - 1][wt - nums[idx - 1]] || dp[idx - 1][wt];
                
                else
                    dp[idx][wt] = dp[idx - 1][wt];
            }
        }
        
        return dp[n][target];
    }
};