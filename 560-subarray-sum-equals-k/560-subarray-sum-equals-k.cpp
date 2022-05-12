// TC: O(N)
// SC: O(N)

// Idea: sum[i..j] = sum[0..j] - sum[0..i-1]
// We want sum[i..j] = k
// so sum[0..j] - k = sum[0..i-1]

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump; // stores frequency of each prefix sum
        ump[0] = 1; // empty subarray
        
        int pSum = 0;
        int cnt = 0;
        for(int num: nums){
            pSum += num;
            
            if(ump.find(pSum - k) != ump.end())
                cnt += ump[pSum - k];
            
            ump[pSum]++;
        }
        
        return cnt;
    }
};


/*
V1: Similar to number of palindromic substrings
// TC: O(N^2)
// SC: O(N^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        // mat[i][j] represents sum of nums[i..j]
        
        int ans = 0;
        for(int i =  n - 1; i >= 0; --i){
            for(int j =  n - 1; j >= 0; --j){
                if(i > j)
                    mat[i][j] = 0;
                else{
                    if(i == j)
                        mat[i][j] = nums[i];
                    else
                        mat[i][j] = nums[i] + mat[i + 1][j - 1] + nums[j];                    
                    
                    ans += (mat[i][j] == k);
                }
            }
        }
        
        return ans;
    }
};
*/