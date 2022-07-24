class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<long long> uq;
        
        for(long long num: nums) uq.insert(num);
        
        vector<long long> bits;
        
        for(long long num: uq) bits.push_back(__builtin_popcount(num));
        
        sort(bits.begin(), bits.end());
        
        long long ans = 0;
        
        for(int x: bits){
            auto it = lower_bound(bits.begin(), bits.end(), k-x);
            ans += (bits.end() - it);
        }
        
        return ans;
    }
};