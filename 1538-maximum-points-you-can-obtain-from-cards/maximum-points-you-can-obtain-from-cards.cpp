class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> presum;
        presum.push_back(cardPoints[0]);
        for(int i=1;i<cardPoints.size();i++){
            presum.push_back(presum[presum.size()-1]+cardPoints[i]);
        }
        int n=cardPoints.size();

        int ans=presum[n-1];
        if((n-1-k)>=0){
            ans=presum[n-1]-presum[n-1-k];
        }
        for(int i=0;i<k;i++){
            int sum1=presum[i];
            int sum2=presum[n-1]-presum[n-(k-i)];
            
            ans=max(ans,(sum1+sum2));

        }

        return ans;
    }
};