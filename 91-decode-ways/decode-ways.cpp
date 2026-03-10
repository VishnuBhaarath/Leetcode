class Solution {
public:
   int ans=0;
   int check(vector<char>& arr, int i, int j){
     if(arr[i]=='0'){
        return -1;
     }
     string st="";
    
     int val=arr[i];
     for(int k=i;k<j;k++){
        st+=arr[k];
       
     }
     if(stoi(st)>26){
        return -1;
     }
 
     return 1;

   }
   void func(vector<char>& arr, int k,int i){
      if(i==arr.size()){
       
        ans+=1;
       
        return;
      }
      int n=arr.size();
      int val1=-1;
      for(int j=i+1;j<min(n+1,i+k+1);j++){
          
         int val=check(arr,i,j);
         if(val==-1){
            return ;
         }

          func(arr,k,j);
      }
   }

    int numDecodings(string s) {
        int n=s.size();
        vector<char> arr;
        for(int i=0;i<s.size();i++){
            arr.push_back(s[i]);
        }
         
         vector<int> dp(n+1,0);
         dp[n-1]=1;
         if(n==1){
            if(arr[0]=='0'){
                
                return 0;
            }
         }
     
         if(arr[n-1]=='0'){
            dp[n-1]=0;
         }
         int ans=0;
         for(int i=n-2;i>=0;i--){
            if(arr[i]!='0'){
                string st="";
                int ans=0;
            for(int j=i;j<min(n,i+2);j++){
                 st+=arr[j];
                 if(stoi(st)>26){
                    break;
                 }
                 int val=1;
                 if(j+1<n){
                     val=max(val,dp[j+1]);
                     if(dp[j+1]==0){
                        val=0;
                     }
                 }
                 ans+=val;
            } 
            dp[i]=ans; 
            }  
         }
        for(int i=0;i<dp.size();i++){
            cout<<dp[i];
            cout<<" ";
        }
        cout<<"\n";
        //func(arr,2,0);
return dp[0];
    }
};