class RangeFreqQuery {
    vector<vector<int>> v;
public:
    RangeFreqQuery(vector<int>& arr) {
        v.resize(100001);
        for(int i = 0; i < arr.size(); ++i) v[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        vector<int>::iterator it1, it2;
        
        it1 = lower_bound(v[value].begin(), v[value].end(), left);       
        it2 = upper_bound(v[value].begin(), v[value].end(), right);
        
        return it2 - it1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */