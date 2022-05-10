class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = INT_MAX;
        int max_after_lowest = INT_MIN;
        int max_profit = 0;
        
        for(int price: prices){
            if(price < min_so_far){
                min_so_far = price;
                max_after_lowest = INT_MIN;
            }
            else if(price > max_after_lowest)
                max_after_lowest = price;
            
            if(max_after_lowest != INT_MIN && min_so_far != INT_MAX)
                max_profit = max(max_profit, max_after_lowest - min_so_far);
        }
        
        return max_profit;
    }
};

/*

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = INT_MAX;
        int max_after_lowest = INT_MIN;
        
        for(int price: prices){
            if(price < min_so_far){
                min_so_far = price;
                max_after_lowest = INT_MIN;
            }
            else if(price > max_after_lowest)
                max_after_lowest = price;
        }
        
        return max_after_lowest == INT_MIN ? 0 : max_after_lowest - min_so_far;
    }
};

WA on [2,4,1]

*/