class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int i=0;
        int j=n-1;
        int sum=0;
        int ans=0;
    
        while(i<k){
           sum+=cardPoints[j];
           j-=1;
           i+=1;
           ans=max(ans,sum);
        }
        i=0;
        j+=1;
       
        while(i<k){
            sum+=cardPoints[i];
            sum-=cardPoints[j];
            i+=1;
            j+=1;
            ans=max(ans,sum);
        }
        return ans;
    }
};