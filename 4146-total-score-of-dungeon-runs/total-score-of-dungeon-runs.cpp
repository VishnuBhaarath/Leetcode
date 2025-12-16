class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        long long sum=0;
        long long score=0;
        vector<int> presum;
        presum.push_back(damage[0]);
        for(int i=1;i<damage.size();i++){
            presum.push_back(presum[presum.size()-1]+damage[i]);
        }
        for(int i=0;i<presum.size();i++){
            cout<<presum[i];
            cout<<" ";
        }
        sum=hp;
        for(int i=0;i<damage.size();i++){
            sum-=damage[i];
            if(sum>=requirement[i]){
               score+=(i+1);
            }
            else{
                int l=0;
                int r=i-1;
                int idx=-1;
                while(l<=r){
                    int m=l+(r-l)/2;
                    if(sum+presum[m] < requirement[i]){
                        l=m+1;
                    }
                    else{
                        idx=m;
                        r=m-1;
                    }

                }
                if(idx==-1){
                    continue;
                }
                else{
                    int sz=(i-(idx+1))+1;
                    score+=sz;
                }

            }
            
        }
        return score;
    }
};