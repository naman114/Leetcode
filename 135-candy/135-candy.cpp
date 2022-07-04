class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> ans(n, 1);
        
        vector<vector<int>> nums;
        for(int i = 0; i < n; ++i) nums.push_back({r[i], i});
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; ++i){
            if(nums[i][1] == 0){
                if(r.size() > 1 && r[0] > r[1]) ans[0] = ans[1] + 1;
            }
            
            else if(nums[i][1] == n - 1){
                if(r.size() > 1 && r[n - 1] > r[n - 2]) ans[n - 1] = ans[n - 2] + 1;
            }
            
            else{
                int left = r[nums[i][1]] > r[nums[i][1] - 1];
                int right = r[nums[i][1]] > r[nums[i][1] + 1]; 
                if(left && right) ans[nums[i][1]] = max(ans[nums[i][1] - 1], ans[nums[i][1] + 1]) + 1;
                else if(left) ans[nums[i][1]] = ans[nums[i][1] - 1] + 1;
                else if(right) ans[nums[i][1]] = ans[nums[i][1] + 1] + 1;
            }
        }
        
        int sum = 0;
        
        for(int num: ans){
            cout<<num<<' ';
            sum += num;
        }
        
        return sum;
        
    }
};

/*
[1,0,2]
[1,2,2]
[10]
[0]
[1,2,87,87,87,2,1]
[1,6,10,8,7,3,2]
[1,2,3]
*/