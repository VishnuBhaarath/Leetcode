class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> umap;
        map<string,int> umap2;
        for(int i=0;i<words.size();i++){
            if(words[i][0]!=words[i][1])
            {
            umap[words[i]]+=1;
            }
            else{
                umap2[words[i]]+=1;
            }
        }
        map<string,int> umap1;
        int ans=0;
        for(auto x:umap){
            if(umap1[x.first]==0){
                string temp=x.first;
               
                reverse(temp.begin(),temp.end());
                if(umap[temp]!=0){
                    int val=min(x.second,umap[temp]);
                    ans+=(4*val);
                }
                umap1[temp]+=1;
            }
        }
       
        int t=0;
        for(auto x:umap2){
            if(x.second%2==0){
                ans+=(2*x.second);
            }
            else{
                ans+=(2*(x.second-1));
                t=1;
            }
        }
        if(t==1){
            ans+=2;
        }
        return ans;
    }
};