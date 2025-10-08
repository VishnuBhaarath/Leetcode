class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int l=0;
            int r=potions.size()-1;
            int idx=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                 unsigned long long val = (unsigned long long)(spells[i]) * (unsigned long long)(potions[mid]);
                 if(val<success){
                    l=mid+1;
                 }
                 else if(val>=success){
                    idx=mid;
                    r=mid-1;
                 }
             }
             if(idx==-1){
                ans.push_back(0);
             }
             else{
                 long long int cnt= potions.size()-idx;
                  
                    ans.push_back(cnt);
             }
        }

        return ans;
    }
};