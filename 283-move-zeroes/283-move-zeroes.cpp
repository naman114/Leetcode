// TC: O(N)
// SC: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0; // idx to place a non zero element
        for(int i = 0; i < (int)nums.size(); ++i){
            if(nums[i] != 0)
                nums[idx++] = nums[i];
        }
        
        while(idx < (int)nums.size()){
            nums[idx++] = 0;
        }
    }
};