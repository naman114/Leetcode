// TC: O(N)
// SC: O(1)

// V2
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; ++i) sum += nums[i];
        
        int sumL = 0;
        for(int i = 0; i < n; ++i){
            if(sumL == sum - sumL - nums[i])
                return i;          
            sumL += nums[i];
        }
        
        return -1;
    }
};

/* V1: With right sum
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int sumL = 0;
        int sumR = 0;
        for(int i = 0; i < n; ++i) sumR += nums[i];
        
        for(int i = 0; i < n; ++i){
            sumL += nums[i];
            
            if(sumL == sumR)
                return i;
            
            sumR -= nums[i];
        }
        
        return -1;
    }
};
*/