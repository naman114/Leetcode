class NumArray {
    vector<int> seg;
    int arrLen;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arrLen = n;
        seg.resize(4*n + 1);
        build(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        updateArr(0, 0, arrLen - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, arrLen - 1, left, right);
    }
    
    void build(int idx, int low, int high, vector<int> &nums){
        if(low == high){
            seg[idx] = nums[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2*idx + 1, low, mid, nums);
        build(2*idx + 2, mid + 1, high, nums);
        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    }
    
    void updateArr(int idx, int low, int high, int i, int val) {
        if(low == high){
            seg[idx] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if(i <= mid)
            updateArr(2*idx + 1, low, mid, i, val);
        else
            updateArr(2*idx + 2, mid + 1, high, i, val);
        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    }
    
    int query(int idx, int low, int high, int l, int r) {
        // NO
        // l r low high , low high l r
        if(low > r || high < l) return 0;
        
        // CO
        // l low high r 
        if(low >= l && high <= r) return seg[idx];
        
        // PO
        int mid = (low + high) >> 1;
        int lc = query(2*idx + 1, low, mid, l, r);
        int rc = query(2*idx + 2, mid + 1, high, l, r);
        
        return lc + rc;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */