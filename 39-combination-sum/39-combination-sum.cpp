class Solution {
public:
    vector<vector<int>> solve(vector<int>& nums, int target, int start){
        vector<vector<int>> ans;
        if(target < 0) return ans;
        
        if(target == 0){
            ans.push_back({});
            return ans;
        }
        
        for(int i = start; i < nums.size(); ++i){
            vector<vector<int>> res = solve(nums, target - nums[i], i);
            
            for(auto v: res){
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }
        
        return ans;
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        return solve(nums, target, 0);
    }
};