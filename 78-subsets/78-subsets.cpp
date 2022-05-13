// TC: O(2^N)
// SC: nC0 + nC1 + .. + nCn = O(2^N)

class Solution {
public:
    vector<vector<int>> solve(vector<int>& nums, int idx) {
        vector<vector<int>> ans;
        
        if(idx == nums.size()){
            ans.push_back({});
            return ans;
        }

        // Give me the subsets of the remaining array
        vector<vector<int>> inc = solve(nums, idx + 1);
        for(auto v: inc){
            // exclude nums[idx]
            ans.push_back(v);
            // include nums[idx]
            v.push_back(nums[idx]);
            ans.push_back(v);
        }
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return solve(nums, 0);
    }
};