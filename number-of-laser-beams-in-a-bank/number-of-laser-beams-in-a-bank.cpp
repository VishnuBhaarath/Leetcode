class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        map<int,int> umap;
        int cnt=0;
        int ans=0;
        int prev=0;
        for(int i=0;i<bank.size();i++){
            string s=bank[i];
            int curr=0;
            for(int j=0;j<s.size();j++){
               if(s[j]=='1'){
                   curr+=1;
               }
            
            }
            if(prev!=0){
                if(curr!=0){
                    ans+=(prev*curr);
                    prev=curr;
                }
            }
            else{
                prev=curr;
            }
        }
        return ans;
    }
};