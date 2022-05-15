// TC: O()
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int num: nums){
            ump[num]++;
            if(ump[num] > nums.size()/2)
                return num;
        }
        return -1;
    }
};