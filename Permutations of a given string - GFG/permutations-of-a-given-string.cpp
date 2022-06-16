// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	  vector<string> ans;
	  map<string,int> umap1;
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(),S.end());
		   for(int i=0;i<S.size();i++){
            map<int,int> umap;
            umap[i]+=1;
            string temp="";
            temp+=S[i];
            backtrack(umap,temp,S,i);
           
        }
         return ans;
		}
	 void backtrack(map<int,int> umap,string temp,string S,int i){
       
         
        if(temp.size()==S.size()){
            if(umap1[temp]==0){
            ans.push_back(temp);
                umap1[temp]+=1;
            }
            return;
        }
  
        for(int j=0;j<S.size();j++){
            if(umap[j]==0){
                temp+=S[j];
                
                umap[j]=1;
                backtrack(umap,temp,S,j);
               
                umap[j]=0;
             
                temp.pop_back();
            }
        }
       
    }
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends