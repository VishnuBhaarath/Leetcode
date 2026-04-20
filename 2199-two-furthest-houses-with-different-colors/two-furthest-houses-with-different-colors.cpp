class Solution {
public:
    int maxDistance(vector<int>& colors) {
         int ans=0;
         for(int i=0;i<colors.size();i++){
            for(int j=i+1;j<colors.size();j++){
                 if(colors[i]!=colors[j]){
                    int dist=abs(j-i);
                    ans=max(ans,dist);
                 }
            }
         }
         return ans;
    }
};