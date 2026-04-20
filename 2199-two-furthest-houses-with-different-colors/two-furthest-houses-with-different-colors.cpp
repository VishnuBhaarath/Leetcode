class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        int n=colors.size();
        int i=0;
        int j=n-1;
        while(colors[i]==colors[j]){
            j-=1;
            if(j==0){
                break;
            }
        }
        int dist=max(j, (n-1-j));
        i=0;
        j=n-1;
         ans=max(ans,dist);
        while(colors[i]==colors[j]){
            i+=1;
            if(i==n-1){
                break;
            }
        }
        int dist1=max(j-i,i);
       
        ans=max(ans,dist1);
        return ans;
    }
};