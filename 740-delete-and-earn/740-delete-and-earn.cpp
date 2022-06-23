// TC: O(N)
// SC: O(N)
class Solution {
    vector<int> dp;
public:
//     int solve(vector<int> &freq, int idx){
//         int ans = 0;
//         int n = freq.size();
        
//         if(idx >= n) return 0;
        
//         if(dp[idx] != -1) return dp[idx];
        
//         for(int i = idx; i < n; ++i)
//             ans = max({ans, solve(freq, i + 1), freq[i]*i + solve(freq, i + 2)});   
        
//         return dp[idx] = ans;
//     }
    int deleteAndEarn(vector<int>& nums) {
        dp.resize(20001, -1);
        vector<int> freq(20001);
        
        for(int num: nums) freq[num]++;
        
        int inc = 0;
        int exc = 0;
        
        for(int i = 0; i <= 20000; ++i){
            int ni = freq[i]*i + exc;
            int ne = max(inc, exc); // Imp
            
            inc = ni;
            exc = ne;
        }
        
        return max(inc, exc);
    }
};

// class Solution {
//     unordered_set<int> forb;
// public:
//     int solve(vector<int> &nums){
//         int ans = 0;
//         int n = nums.size(); 
                
//         for(int i = 0; i < n; ++i){
//             if(!forb.count(nums[i])){
//                 forb.insert(nums[i] + 1);
//                 forb.insert(nums[i] - 1);
//                 forb.insert(nums[i]);
//                 ans = max(ans, nums[i] + solve(nums));
//                 forb.erase(nums[i] + 1);
//                 forb.erase(nums[i] - 1);
//                 forb.erase(nums[i]);
//             }
//         }
        
//         return ans;
//     }
//     int deleteAndEarn(vector<int>& nums) {
//         forb.clear();
//         return solve(nums);
//     }
// };