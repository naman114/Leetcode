class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        for(int i = 0; i < (int) nums.size(); ++i){
            if(ump.count(target - nums[i]))
                return {i, ump[target - nums[i]]};
            ump[nums[i]] = i;
        } // TC: O(N) SC: O(N)
        return {-1, -1};
    }
};