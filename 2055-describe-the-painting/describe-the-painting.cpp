class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<long long> v(100001,0);
        int l=INT_MAX;
        int r=INT_MIN;
        vector<long long> v2(100001,0);
        for(int i=0;i<segments.size();i++){
            v[segments[i][0]]+=segments[i][2];
            v[segments[i][1]]-=segments[i][2];
            l=min(l,segments[i][0]);
            r=max(r,segments[i][1]);
            v2[segments[i][0]]=1;
            v2[segments[i][1]]=1;
        }
        long long int idx=-1;
        long long int cnt=0;
        vector<vector<long long>> ans;
        for(int i=l;i<=r;i++){
            if(idx==-1){
                idx=i;
                cnt+=v[i];
            }
            else if(v2[i]!=0 && cnt!=0){
                if(idx!=-1){
                  
                    ans.push_back({idx,i,cnt});
                    
                }
                cnt+=v[i];
                idx=i;
            }
            else if(cnt==0){
                cnt+=v[i];
                idx=i;
            }
        }
        return ans;
    }
};