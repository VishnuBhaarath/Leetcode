class Solution {
public:
    string ans="";
    map<string,int> umap;
    void func(int i,int n,string st){
        if(ans.size()!=0){
            return;
        }
         if(i==n){
           
            if(umap[st]==0){
                ans=st;
                return;
            }
           
            return;
         }
         st+='0';
         func(i+1,n,st);
         st.pop_back();
         st+='1';
         func(i+1,n,st);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
        }
        int n=nums.size();
        func(0,n,"");
        return ans;

    }
};