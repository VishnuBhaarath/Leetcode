class Solution {

     vector<long long> bestSumEndingAt(const vector<int>& h) {
        int n = h.size();
        vector<long long> best(n);

        stack<int> st;          // indices with non-decreasing heights
        st.push(-1);            // sentinel: "nothing to the left"
        long long total = 0;    // sum of all blocks currently on the stack

        for (int i = 0; i < n; i++) {

            // Taller towers on the left get clamped down to h[i],
            // so remove the block each one was contributing
            while (st.top() != -1 && h[st.top()] > h[i]) {
                int j = st.top();
                st.pop();
                int below = st.top();
                long long blockLength = j - below;
                total -= blockLength * h[j];
            }

            // Now positions (below+1 .. i) all have height h[i]
            int below = st.top();
            long long blockLength = i - below;
            total += blockLength * h[i];

            st.push(i);
            best[i] = total;
        }
        return best;
    }
    
public:

    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();

        // left side: peak at i, looking at towers 0..i
        vector<long long> left = bestSumEndingAt(heights);

        // right side: reverse the array, reuse the same function, reverse back
        vector<int> reversed(heights.rbegin(), heights.rend());
        vector<long long> right = bestSumEndingAt(reversed);
        reverse(right.begin(), right.end());

        long long answer = 0;
        for (int i = 0; i < n; i++) {
            // tower i is counted in both left[i] and right[i], so subtract once
            answer = max(answer, left[i] + right[i] - heights[i]);
        }
        return answer;
        


       
    }
};