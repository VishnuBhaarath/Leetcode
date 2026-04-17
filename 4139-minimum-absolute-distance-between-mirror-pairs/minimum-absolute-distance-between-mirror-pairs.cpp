class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> umap;
int ans=-1;
        for(int i=0;i<nums.size();i++){
          
            if(umap[nums[i]]!=0){
                int idx=umap[nums[i]];
                int val=i+1-idx;
                if(ans==-1){
                    ans=val;
                }
                else{
                    ans=min(ans,val);
                                    }

            }

            while(nums[i]%10==0){
                nums[i]=nums[i]/10;
            }
          //  umap[nums[i]]=i+1;
            string st=to_string(nums[i]);
            reverse(st.begin(),st.end());
            int temp1=stoi(st);
            umap[temp1]=i+1;
          
        }
          return ans;
    }

};