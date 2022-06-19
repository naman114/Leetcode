class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mx = INT_MIN;
        
        for(int num: nums){
            sum += num;
            mx = max(mx, sum);
            
            if(sum < 0)
                sum = 0;
        }
        
        return mx;
    }
};