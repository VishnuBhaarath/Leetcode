class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        map<int,int> umap;
        sort(special.begin(),special.end());
       
        int ans=0;
        int i=0;
        int cnt=special[0]-bottom;
        ans=max(ans,cnt);
        while((i+1)<special.size()){
     
            

            int val=special[i+1]-special[i]-1;
            
            cnt=special[i+1]-special[i];
            
            ans=max(ans,val);
          
            
            i+=1;
        }
        cnt=top-special[special.size()-1];
        ans=max(ans,cnt);
        return ans;

    }
};