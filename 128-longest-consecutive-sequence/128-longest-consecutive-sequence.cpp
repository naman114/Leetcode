class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> ump; // whether key is a valid starting point
        for(int num: nums) ump[num] = 1;
        
        for(int num: nums){
            if(ump.count(num - 1))
                ump[num] = 0;
        }
        
        unordered_map<int, int>::iterator it;
        int ans = 0; // 0 because of empty array
        
        for(it = ump.begin(); it != ump.end(); ++it){
            if(it->second){
                int start = it->first;
                while(ump.count(start + 1)){
                    start++;
                }
                
                ans = max(ans, start - it->first + 1);
            }
        }
        
        return ans;
    }
};