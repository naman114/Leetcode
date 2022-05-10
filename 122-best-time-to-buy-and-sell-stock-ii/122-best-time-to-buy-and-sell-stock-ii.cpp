class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0], sell = 0;
        
        for(int i = 1; i < (int) prices.size(); ++i){
            int temp_buy = max(sell - prices[i], buy);
            int temp_sell = max(buy + prices[i], sell);
            
            buy = temp_buy;
            sell = temp_sell;
        }
        
        return sell;
    }
};