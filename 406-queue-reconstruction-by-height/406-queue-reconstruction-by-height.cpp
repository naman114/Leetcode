class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) return a[0] <= b[0];
        return a[1] <= b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), compare);
        
        int n = p.size();
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            int pos = -1;
            for(int j = 0; j < i; ++j){
                if(p[j][0] >= p[i][0]) cnt++;
                
                if(pos == -1 && cnt > p[i][1]) pos = j;
            }
            
            if(pos != -1){
                // vector<int> to_move = p[i];
                // auto it = p.begin() + pos;
                // p.erase(p.begin() + i);
                // p.insert(p.begin() + pos, to_move);
                
                int idx = i;
                while(idx != pos){
                    swap(p[idx], p[idx - 1]);
                    idx--;
                }
            }
        }
        
        return p;
    }
};