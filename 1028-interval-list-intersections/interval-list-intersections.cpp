class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> answer;
        int f = 0;
        int s = 0;
        int n = firstList.size();
        int m = secondList.size();

        while(f < n && s < m){
            if(firstList[f][0] > secondList[s][1]){
                s++;
                continue;
            }else if(secondList[s][0] > firstList[f][1]){
                f++;
                continue;
            }

            int minElement = max(firstList[f][0], secondList[s][0]);
            int maxElement = min(firstList[f][1], secondList[s][1]);


            if(maxElement >= firstList[f][1]){
                f++;
            }else{
                firstList[f][0] = maxElement;
            }

            if(maxElement >= secondList[s][1]){
                s++;
            }else{
                secondList[s][0] = maxElement;
            }
            if(maxElement >= minElement){
                answer.push_back({minElement, maxElement});
            }
        }

        return answer;
    }
};