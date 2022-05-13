class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int rows = m.size(), cols = m[0].size();
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(i == j) continue;
                else if(i < j)
                    swap(m[i][j], m[j][i]);
            }
        }
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(j < cols / 2)
                    swap(m[i][j], m[i][cols - j - 1]);
            }
        }
    }
};