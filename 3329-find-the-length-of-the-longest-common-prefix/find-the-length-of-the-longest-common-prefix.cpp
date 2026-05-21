class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        set<string> us;
        for(int i=0;i<arr1.size();i++){
             string st1=to_string(arr1[i]);
             string temp="";
           
             for(int j=0;j<st1.size();j++){
                temp+=st1[j];
                us.insert(temp);
             }
        }
       
      
            for(int j=0;j<arr2.size();j++){
              
                string s2=to_string(arr2[j]);
                int k=0;
                int n=s2.size();
                
                int cnt=0;
                string temp="";
                while(k<n){
                     temp+=s2[k];
                     if(us.find(temp)!=us.end()){
                        int sz=temp.size();
                        ans=max(ans,sz);
                     }
                     else{
                        break;
                     }
                    
                     k+=1;
                }
                ans=max(ans,cnt);
            }
        
        return ans;
    }
};