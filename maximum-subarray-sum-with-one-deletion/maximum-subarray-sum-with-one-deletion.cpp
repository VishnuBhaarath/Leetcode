class Solution {
public:
    int maximumSum(vector<int>& arr) {
        
        vector<int> forward;
        int n=arr.size();
        if(n==1){
            return arr[0];
        }
        vector<int> backward;
        int currsum=arr[0];
        forward.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(currsum+arr[i]<arr[i]){
                currsum=arr[i];
                forward.push_back(currsum);
            }
            else{
                currsum+=arr[i];
                forward.push_back(currsum);
            }
        }
        currsum=arr[n-1];
        backward.push_back(currsum);
        for(int i=n-2;i>=0;i--){
            if(currsum+arr[i]<arr[i]){
                currsum=arr[i];
                backward.push_back(currsum);
            }
            else{
                currsum+=arr[i];
                backward.push_back(currsum);
            }
        }
       
        reverse(backward.begin(),backward.end());
        
        int maxsum=backward[1];
        for(int i=1;i<forward.size();i++){
            int currsum=forward[i-1];
            if((i+1)<forward.size()){
                currsum+=backward[i+1];
            }
            maxsum=max(maxsum,currsum);
        }
       
      currsum=arr[0];
        for(int i=1;i<arr.size();i++){
            currsum=max(arr[i],currsum+arr[i]);
            
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
    }
};