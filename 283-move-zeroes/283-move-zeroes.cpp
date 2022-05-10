// TC: O(N)
// SC: O(1)

// V2: One pass
// In V1, slow ptr is always pointing to zero
// and since after getting copied to slow, elem at fast
// will either become a zero or some other non zero elem
// we can make it zero right away so that we don't have to 
// come back to set it as zero

// Helpful when [0 0 0 0 1]
// Just swap first and last idx when you reach last idx
// [1 0 0 0 0]
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0; // idx to place a non zero element
        for(int i = 0; i < (int)nums.size(); ++i){
            if(nums[i] != 0)
                swap(nums[idx++],nums[i]);
        }
    }
};

/*
// V1: Populate the start with non zero nums and fill the end with zeros
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
*/