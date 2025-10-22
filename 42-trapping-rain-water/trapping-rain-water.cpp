class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();

        int i=0;
        int j=n-1;
        int leftmax=arr[i];
        int rightmax=arr[j];
        int ans=0;
        i+=1;
        j-=1;
      
        while(i<=j){
           if(leftmax<=rightmax){
               if(arr[i]<leftmax){
                ans+=(leftmax-arr[i]);
               }

               leftmax=max(leftmax,arr[i]);
                i+=1;
           }
           else {
              if(arr[j]<rightmax){
                ans+=(rightmax-arr[j]);
              }
            
              rightmax=max(rightmax,arr[j]); 
               j-=1;
           }
          
            
        }
    return ans;

        
    }
};