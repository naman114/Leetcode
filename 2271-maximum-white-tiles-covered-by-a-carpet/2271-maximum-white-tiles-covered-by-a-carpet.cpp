class Solution {
public:
//     [[1,5],[10,11],[12,18],[20,25],[30,32]]
// 10
    int solve(vector<int> &nums, int start, int startidx, int end, vector<long long> &blank){
        auto it1 = lower_bound(nums.begin(), nums.end(), end);
        
        int pl;
        if(startidx == 0)
            pl = 0;
        else
            pl = blank[startidx];
        
        if(it1 == nums.end()){
            int sub = blank.back() - pl;
            return nums.back() - start + 1 - sub;
        }
        
        auto it2 = it1;
        it2--;
        
        if(*it1 == end || blank[it1 - nums.begin()] == blank[it2 - nums.begin()]){
            int sub = blank[it1 - nums.begin()] - pl;
            return end - start + 1 - sub;
        }
    
        
        it1--;
        int sub = blank[it1 - nums.begin()] - pl;
        return (*it1) - start + 1 - sub;
    }
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        vector<int> nums;
        
        vector<long long> blank;
        
        for(int i = 0; i < tiles.size(); ++i){
            if((nums.size() > 0 && nums.back() == tiles[i][0]) || tiles[i][0] == tiles[i][1]){
                nums.push_back(tiles[i][1]);
                
                if(i == 0)
                    blank.push_back(0);
                else
                    blank.push_back(blank.back() + tiles[i][0] - tiles[i - 1][1] - 1);
            }
            else{
                nums.push_back(tiles[i][0]);
                nums.push_back(tiles[i][1]);
                
                if(i == 0){
                    blank.push_back(0);
                    blank.push_back(0);
                }
                else{
                    int b = blank.back();
                    blank.push_back(b + tiles[i][0] - tiles[i - 1][1] - 1);
                    blank.push_back(b + tiles[i][0] - tiles[i - 1][1] - 1);
                }
            }
        }
        
        assert(blank.size() == nums.size());
        
        // for(int i = 0; i < blank.size(); ++i) cout<<blank[i]<<endl;
        
        int ans = 1;
        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            int res = solve(nums, num, i, num + carpetLen - 1, blank);
            // cout<<res<<endl;
            ans = max(ans, res);
        }
        cout<<endl;
        return ans;
    }
};