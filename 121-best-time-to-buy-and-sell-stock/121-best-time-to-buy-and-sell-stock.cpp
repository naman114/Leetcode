class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = INT_MAX;
        int max_profit = 0;
        
        for(int price: prices){
            min_so_far = min(min_so_far, price); // lowest buying price so far
            max_profit = max(max_profit, price - min_so_far); // take max of profits earned by theoretically selling everyday
        }
        
        return max_profit;
    }
};

/*

V2: We are are selling everyday here based on the lowest price so far

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

*/

/*
V1: We need global best profit. This method gives the 'last' local best profit 
WA on [2,4,1]

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

*/