class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int l=points[0][0];
        int r=points[0][1];
        int val=0;
        for(int i=1;i<points.size();i++){
            int temp1=abs(points[i][0]-l);
            int temp2=abs(points[i][1]-r);
            int temp=min(temp1,temp2);
            val+=temp;
            val+=abs(temp-temp2)+abs(temp-temp1);
            
            l=points[i][0];
            r=points[i][1];
        }
        return val;
    }
};