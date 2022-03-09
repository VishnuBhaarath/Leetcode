class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<long long int,vector<long long int>> umap;
       
        for(int i=0;i<nums.size();i++){
            
            string st=to_string(nums[i]);
          
            string temp1="";
            for(int j=0;j<st.size();j++){
               if(mapping[st[j]-'0']==0){
                 if(temp1.size()!=0){  
                 temp1+=to_string(mapping[st[j]-'0']);}
               }
                else{
                    temp1+=to_string(mapping[st[j]-'0']);
                }
            }
            if(temp1.size()==0){
                umap[0].push_back(nums[i]);
            }
            else{
            umap[stoll(temp1)].push_back(nums[i]);}
           
        }
        vector<int> ans;
        for(auto x:umap){
            vector<long long int> v=x.second;
            for(int i=0;i<v.size();i++){
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};