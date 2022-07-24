/*
TC: O(rows + cols) - worst case when elem is at bottom left
SC: O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int tar) {
        int rows = m.size();
        int cols = m[0].size();
        
        int i = 0, j = cols - 1;
        
        while(i < rows && j >= 0){
            if(tar == m[i][j]) return true;
            else if(tar < m[i][j]) j--;
            else i++;
        }
        
        return false;
    }
};