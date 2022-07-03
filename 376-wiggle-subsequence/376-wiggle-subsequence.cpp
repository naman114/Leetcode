class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int dp[n][2];
        memset(dp, 0, sizeof dp);
        
        dp[0][0] = 1;
        dp[0][1] = 1;
        
        int ans = INT_MIN;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                int d = nums[i] - nums[j];
                
                if(d < 0){
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
                else if(d > 0){
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
            ans = max({ans, dp[i][0], dp[i][1]});
        }
        
        return ans;
    }
};