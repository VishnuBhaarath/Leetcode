class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
       sort(nums.begin(),nums.end());
       sort(numsDivide.begin(),numsDivide.end());
       vector<int> v;
       map<int,int> umap;
       for(int i=0;i<nums.size();i++){
           if(umap[nums[i]]==0){
               umap[nums[i]]+=1;
               v.push_back(nums[i]);
           }
           else{
               umap[nums[i]]+=1;
           }
       } 
       int hcf=numsDivide[0];
       for(int i=1;i<numsDivide.size();i++){
           hcf=__gcd(hcf,numsDivide[i]);
         
       } 
       
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if((hcf%v[i])==0){
                return cnt;
            }
            cnt+=umap[v[i]];
        }
       return -1;
    }
};