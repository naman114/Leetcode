class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n == 1)
            return {{1}};
        if(n == 2)
            return {{1}, {1,1}};
        
        vector<vector<int>> ans = {{1}, {1,1}};
        
        for(int cnt = 0; cnt < n - 2; ++cnt){
            vector<int> last = ans.back();
            int i = 0, j = 1;
            
            vector<int> temp = {last[i]};
            while(j < last.size())
                temp.push_back(last[i++] + last[j++]);
            
            temp.push_back(last.back());
            ans.push_back(temp);
        }
        
        return ans;
    }
};