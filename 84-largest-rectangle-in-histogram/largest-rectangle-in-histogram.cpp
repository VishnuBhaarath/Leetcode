class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (s.empty()) {
                s.push(i);
            } else {
                if (heights[i] >= heights[s.top()]) {
                    s.push(i);
                } else {
                    while (heights[i] < heights[s.top()]) {
                        int tp = s.top();
                        s.pop();
                        int tp1 = -1;
                        if (!s.empty()) {
                            tp1 = s.top();
                        }

                        int w = (i - tp1 - 1);
                        int h = heights[tp];
                        int area = w * h;
                        ans = max(ans, area);
                      

                        if (s.empty()) {
                            break;
                        }
                    }
                    s.push(i);
                }
            }
        }
        while (!s.empty()) {
            int tp = s.top();
            s.pop();
            int tp1 = -1;
            if (!s.empty()) {
                tp1 = s.top();
            }
            int w = (n - tp1-1);
            int h = heights[tp];
            int area = w * h;
            ans = max(ans, area);
            

            if (s.empty()) {
                break;
            }
        }

        return ans;
    }
};