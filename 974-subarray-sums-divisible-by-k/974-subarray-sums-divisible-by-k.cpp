class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        ump[0]++;
        
        int pSum = 0;
        int ans = 0;
        
        for(int num: nums){
            pSum += num;
            
            int rem = pSum % k;
            
            if(rem < 0) rem += k;
            
            if(ump.find(rem) != ump.end()) ans += ump[rem];
            
            ump[rem]++;
        }
        
        return ans;
    }
};