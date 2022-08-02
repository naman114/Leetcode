/*
Kth largest: min heap and insert greater
Kth smallest: max heap and insert smaller

TC: O(N^2 log(K))
SC: O(K)
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int rows = m.size();
        int cols = m[0].size();
        
        priority_queue<int> pq;
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                
                if(pq.size() < k) pq.push(m[i][j]);
                
                else if(m[i][j] < pq.top()){
                    pq.pop();
                    pq.push(m[i][j]);
                }
            }
        }
        
        return pq.top();
    }
};