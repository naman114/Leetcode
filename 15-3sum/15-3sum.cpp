// TC: O(N^2)
// SC: O(no of triplets)
class Solution {
public:
    vector<vector<int>> twoSum(vector<int> &nums, int target, int start){
        int lo = start, high = nums.size() - 1;
        vector<vector<int>> ans;
        
        while(lo < high){
            int sum = nums[lo] + nums[high];
            if(sum == target){
                ans.push_back({nums[lo], nums[high]});
                
                // Reason for the while loops below: [-2,0,0,2,2]
                while(lo < high && nums[lo] == nums[lo + 1]) lo++;
                while(lo < high && nums[high] == nums[high - 1]) high--;
                
                lo++;
                high--;
            }
            else if(sum < target)
                lo++;
            else
                high--;
        }
        
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i < nums.size(); ++i){
            vector<vector<int>> res = twoSum(nums, -nums[i], i + 1);
            if(res.size()){
                for(auto v: res)
                    ans.push_back({nums[i], v[0], v[1]});
            }
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        }
        
        return ans;
    }
};