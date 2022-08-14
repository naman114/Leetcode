/*
Monotonic Queue
https://medium.com/algorithms-and-leetcode/monotonic-queue-explained-with-leetcode-problems-7db7c530c1d6
TC: O(N)
SC: O(N)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        deque<int> dq;
        
        int start = 0, end = 0;
//         for(int i = start; i <= end; ++i){
//             while(!dq.empty() && dq.back() < nums[i])
//                 dq.pop_back();
            
//             dq.push_back(nums[i]);
//         }
//         ans.push_back(dq.front());
        
        while(end < nums.size()){    
            while(!dq.empty() && dq.back() < nums[end])
                dq.pop_back();
            
            dq.push_back(nums[end]);
            
            if(end - start + 1 == k){
                ans.push_back(dq.front());
                
                if(nums[start] == dq.front())
                    dq.pop_front();
                
                start++;
            }
            
            end++;
        }
        
        return ans;
    }
};