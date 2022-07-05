class RangeFreqQuery {
    unordered_map<int, vector<int>> ump;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); ++i) ump[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        if(!ump.count(value)) return 0;
        
        vector<int>::iterator it1, it2;
        
        it1 = lower_bound(ump[value].begin(), ump[value].end(), left);       
        it2 = upper_bound(ump[value].begin(), ump[value].end(), right);
        
        return it2 - it1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */