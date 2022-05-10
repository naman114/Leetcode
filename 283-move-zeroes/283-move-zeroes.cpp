class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0; // idx to place a non zero element
        int cnt = 0; // cnt of zeros
        for(int i = 0; i < (int)nums.size(); ++i){
            if(nums[i] != 0)
                nums[idx++] = nums[i];
            else
                cnt++;
        }
        
        idx = nums.size() - 1;
        while(cnt--){
            nums[idx--] = 0;
        }
    }
};