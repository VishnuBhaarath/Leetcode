class Solution {
public:
vector<int> findNSE(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> findNGE(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> findPSE(vector<int> &arr){
       stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            while (!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    vector<int> findPGE(vector<int> &arr){
       stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            while (!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNGE(arr);
        vector<int> pse = findPGE(arr);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            sum = sum + (long long)arr[i] * left * right;
        }
        return sum;
    }
     long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            sum = sum + (long long)arr[i] * left * right;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long ans1 = sumSubarrayMaxs(nums);
        long long ans2 = sumSubarrayMins(nums);
        return ans1 - ans2;
    }
};