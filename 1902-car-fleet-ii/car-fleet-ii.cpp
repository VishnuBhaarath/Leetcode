class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
         int n = cars.size();
        vector<double> ans(n, -1.0);     // -1 means "never collides"
        stack<int> st;                   // candidate target cars ahead, nearest on top

        for (int i = n - 1; i >= 0; i--) {
            double pos   = cars[i][0];
            double speed = cars[i][1];

            // Remove targets that car i cannot actually hit
            while (!st.empty()) {
                int j = st.top();
                double posAhead   = cars[j][0];
                double speedAhead = cars[j][1];

                // Rule 1: i is not faster, so it can never catch j
                bool cannotCatch = (speed <= speedAhead);

                // Rule 2: j merges into another car before i reaches it
                bool alreadyMerged = false;
                if (!cannotCatch) {
                    double timeToReach = (posAhead - pos) / (speed - speedAhead);
                    bool jMergesLater = (ans[j] != -1);
                    alreadyMerged = jMergesLater && timeToReach >= ans[j];
                }

                if (cannotCatch || alreadyMerged) {
                    st.pop();            // j is useless for i and for all cars behind i
                } else {
                    break;               // j is a valid target
                }
            }

            // Whatever is on top now is the car i collides with
            if (!st.empty()) {
                int j = st.top();
                ans[i] = (cars[j][0] - pos) / (speed - cars[j][1]);
            }

            st.push(i);                  // always push, even if ans[i] == -1
        }
        return ans;
    }
};