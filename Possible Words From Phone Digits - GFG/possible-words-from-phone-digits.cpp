// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> ans;
    int t=0;
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<vector<char>> s={{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        
        string temp="";
        backtrack(s,temp,0,a,N);
        
        return ans;
    }
    void backtrack(vector<vector<char>> s, string temp,int j,int a[],int N){
        
        if(j==N){
          
           if(temp.size()==N){
            ans.push_back(temp);}
           
            return;
        }
       
        
            for(int k=0;k<s[a[j]-2].size();k++){
            
                temp+=s[a[j]-2][k];
                
                backtrack(s,temp,j+1,a,N);
                temp.pop_back();
               
            }
           
        
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends