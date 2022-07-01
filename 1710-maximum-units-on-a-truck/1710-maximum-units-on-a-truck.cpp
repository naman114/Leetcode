class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    
     int maximumUnits(vector<vector<int>>& items, int wt) {
         sort(items.begin(), items.end(), compare);
         int ans = 0;
         
         for(int i = 0; i < items.size(); ++i){
             if(wt <= 0) break;
             if(wt - items[i][0] >= 0){
                 ans += items[i][0] * items[i][1];
                 wt -= items[i][0];
             }
             else{
                 ans += wt * items[i][1];
                 wt = 0;
             }
         }
         
         return ans;
    }
    
// 0-1 Knapsack variation
// But the constraints are too big
/*
    int maximumUnits(vector<vector<int>>& items, int wt) {
        int n = items.size();
        vector<vector<int>> dp(n + 1, vector<int>(wt + 1));
        
        // dp[i][j] means max value upto i items and j knapsack size
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= wt; ++j){
                for(int k = 1; k <= items[i - 1][0]; ++k){
                    if(j - k >= 0)
                        dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i - 1][j - k] + k*items[i - 1][1]});
                    else{
                        dp[i][j] = dp[i - 1][j];
                        break;
                    }
                }
            }
        }
        
        return dp[n][wt];
    }
*/
};