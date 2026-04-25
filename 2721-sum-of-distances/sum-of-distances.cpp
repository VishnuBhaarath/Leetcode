class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<long long int,long long int> umap;
        map<long long int,long long int> umap1;
        map<long long int,long long int> umap2;
        int n=nums.size();
        vector<long long> v(n,0);
        for(int i=0;i<nums.size();i++){
            if(umap1[nums[i]]!=0){
                int cnt=umap1[nums[i]];
                int idx=umap[nums[i]];
                umap2[nums[i]]+=(i-idx)*cnt;
                v[i]=umap2[nums[i]];
            }

            umap[nums[i]]=i;
            umap1[nums[i]]+=1;
        }
        vector<long long> ans(n,0);
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            cout<<" ";
        }

         map<long long int,long long int> umap3;
        map<long long int,long long int> umap4;
        map<long long int,long long int> umap5;
        
        vector<long long> v1(n,0);
         cout<<"\n";
 for(int i=n-1;i>=0;i--){
            if(umap4[nums[i]]!=0){
                int cnt=umap4[nums[i]];
                int idx=umap3[nums[i]];
                umap5[nums[i]]+=(idx-i)*cnt;
                v1[i]=umap5[nums[i]];
            }

            umap3[nums[i]]=i;
            umap4[nums[i]]+=1;
        }
         
         for(int i=0;i<n;i++){
            cout<<v1[i];
            cout<<" ";
        }
        cout<<"\n";
        //vector<long long > ans(n,0);
       for(int i=0;i<n;i++){
        ans[i]=v[i]+v1[i];
       }

        return ans;
    }
};