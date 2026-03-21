class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26,-1);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']=i;
        }
        int st=0;
        int end=v[s[0]-'a'];
       
         vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(i==end){
                
                int sz=end-st+1;
                ans.push_back(sz);
                if((i+1)<s.size()){
                st=i+1;
                end=v[s[i+1]-'a'];}
                else{
return ans;
                }
              
               
            }
            else{
                end=max(end,v[s[i]-'a']);
            }
        }

      
                ans.push_back(end-st+1);
              
       
        return ans;
    }
};