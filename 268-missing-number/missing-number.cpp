class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int val=n;
        int temp=-1;
        for(int i=0;i<nums.size();i++){
             if(abs(nums[i])==n){

             }
             else{
                    nums[abs(nums[i])]=-1*nums[abs(nums[i])];
                    if(nums[abs(nums[i])]==0){
                        temp=abs(nums[i]);
                    }
                    cout<<abs(nums[i]);
                    cout<<" ";
                    cout<< nums[abs(nums[i])];
                    cout<<"\n";
                   
             }
        }
        cout<<"\n";
        for(int i=0;i<n;i++){
            cout<<nums[i];
            cout<<" ";
            if(nums[i]>=0){
                if(i!=temp){
                    val=i;
                }
               
            }
            
        }


        return val;
    }
};