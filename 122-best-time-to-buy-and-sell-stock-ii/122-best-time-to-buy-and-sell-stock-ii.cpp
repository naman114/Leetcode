class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy and sell mean profit if you buy or sell that day
        int buy = -prices[0], sell = 0; 
        // On the first day, we have to buy and sell because we don't have previous day's profit history
        // e.g. [1 100]
        // we have to buy else we cannot sell it to get 99 in this case
        // & on day one, profit (if sold) is zero
        
        for(int i = 1; i < (int) prices.size(); ++i){
            // Every day:
            
            // If you are in the buying mood, you can either buy that day by cutting that day's price from your profits on selling the day before or you continue your last purchase
            int temp_buy = max(sell - prices[i], buy);
            // If you are in the selling mood, you can either sell that day by adding that day's price to your profits on buying the day before or you didn't buy any new stock and just maintain your profits after the last sale 
            int temp_sell = max(buy + prices[i], sell);
            
            buy = temp_buy;
            sell = temp_sell;
        }
        
        // On the last day, you sell and that's final
        return sell;
    }
};