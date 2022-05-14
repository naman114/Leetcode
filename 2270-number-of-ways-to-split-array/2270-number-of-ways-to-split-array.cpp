class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(int num: nums) sum += num;
        
        int ans = 0;
        long long psum = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            psum += nums[i];
            if(psum >= sum - psum) ans++;
        }
        return ans;
    }
};