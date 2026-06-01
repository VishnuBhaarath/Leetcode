class NumArray {
public:
    vector<int> v;
    int n;

    int build(int i, int j, vector<int>& nums, int idx) {
        if (i == j)
            return v[idx] = nums[i];
        int mid = (i + j) / 2;                              // fix: use (i+j)/2
        return v[idx] = build(i, mid, nums, 2*idx+1) 
                      + build(mid+1, j, nums, 2*idx+2);
    }

    // O(log n) point update
    void updateHelper(int i, int j, int pos, int val, int idx) {
        if (i == j) {
            v[idx] = val;
            return;
        }
        int mid = (i + j) / 2;
        if (pos <= mid)
            updateHelper(i, mid, pos, val, 2*idx+1);
        else
            updateHelper(mid+1, j, pos, val, 2*idx+2);
        v[idx] = v[2*idx+1] + v[2*idx+2];                  // pull up
    }

    // O(log n) range sum query
    int query(int i, int j, int l, int r, int idx) {
        if (r < i || j < l)  return 0;                      // completely outside
        if (l <= i && j <= r) return v[idx];                 // completely inside
        int mid = (i + j) / 2;
        return query(i, mid, l, r, 2*idx+1)
             + query(mid+1, j, l, r, 2*idx+2);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        v.resize(4 * n, 0);
        build(0, n-1, nums, 0);
    }
    
    void update(int index, int val) {
        updateHelper(0, n-1, index, val, 0);                 // O(log n), no rebuild
    }
    
    int sumRange(int left, int right) {
        return query(0, n-1, left, right, 0);
    }
};