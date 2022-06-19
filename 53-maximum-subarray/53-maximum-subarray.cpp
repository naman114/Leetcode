/*
TC: O(N)
SC: O(1)

Three step process:
1. Add the current number to sum (container)
2. Take the max with the global max
   At this point, container is either positive or negative
   We might think that a negative sum is of no use to us, so we should directly make it zero
   But we have to take max in both cases because if we only take max when sum is positive, 
   then we will not get the correct answer when array is [-2]
3. If the container sum is negative, we should make it zero because a negative sum will only
   reduce the sum when the next number is added to it. 
   So, we only carry the container when it has a non-negative sum, else we empty it

DP Recurrence Relation
dp[i] = A[i] + (dp[i - 1] < 0 ? 0 : dp[i - 1]) 
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mx = INT_MIN;
        
        for(int num: nums){
            sum += num;
            mx = max(mx, sum);
            
            if(sum < 0)
                sum = 0;
        }
        
        return mx;
    }
};