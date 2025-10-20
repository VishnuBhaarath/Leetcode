class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n=firstList.size();
        int m=secondList.size();
        int i=0;
        int j=0;
        vector<vector<int>> ans;
        while(i<n && j<m){
            int x1=firstList[i][0];
            int y1=firstList[i][1];

            int x2=secondList[j][0];
            int y2=secondList[j][1];
            vector<int> v;
            if(x1<x2){
                if(y1>=y2){
                    v.push_back(x2);
                    v.push_back(y2);
                    ans.push_back(v);
                    
                }
                else{
                    if(x2<=y1){
                     
                        v.push_back(x2);
                         v.push_back(y1);
                         ans.push_back(v);

                    }
                    
                }
            }
            else{
                if(y2>=y1){
                   
                    v.push_back(x1);
                    v.push_back(y1);
                    ans.push_back(v);

                }
                else{
                  if(x1<=y2){
                     
                     v.push_back(x1);
                     v.push_back(y2);
                     ans.push_back(v);
                  }
                }

            }

            if(y1>y2){
                j+=1;
            }
            else{
                i+=1;
            }
        }
        return ans;
    }
};