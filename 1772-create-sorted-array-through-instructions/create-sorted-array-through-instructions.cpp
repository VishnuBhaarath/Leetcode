class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] += val;
            return;
        }
        
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        
        int mid = start + (end - start) / 2;
        int leftSum = query(2 * node, start, mid, l, r);
        int rightSum = query(2 * node + 1, mid + 1, end, l, r);
        return leftSum + rightSum;
    }
    
public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }
    
    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
    
    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        if (n == 0) return 0;
        
        // Find the maximum value to determine segment tree size
        int maxVal = *max_element(instructions.begin(), instructions.end());
        
        // Create segment tree with size maxVal+1 to handle 1-indexed values
        SegmentTree segTree(maxVal + 1);
        
        long long cost = 0;
        int mod = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            int num = instructions[i];
            
            // Count elements strictly less than num (values 1 to num-1)
            int smaller = (num > 1) ? segTree.query(1, num - 1) : 0;
            
            // Count elements strictly greater than num (values num+1 to maxVal)
            int greater = (num < maxVal) ? segTree.query(num + 1, maxVal) : 0;
            
            // Add the minimum cost
            cost += min(smaller, greater);
            cost %= mod;
            
            // Update the segment tree with current element
            segTree.update(num, 1);
        }
        
        return cost;
    }
};