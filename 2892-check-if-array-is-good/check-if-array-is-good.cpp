class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n+1,0);

        for(int i=0;i<nums.size();i++){
            if(nums[i]>=v.size()){
                return false;
            }
            else{
                v[nums[i]]+=1;
                
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            cout<<" ";
        }
        if(v[0]!=0){
            return false;
        }
        int t=0;
        for(int i=1;i<v.size();i++){
             if(t==0){
                 if(v[i]!=1 && v[i]!=2){
                    return false;
                 }
                 if(v[i]==2){
                    t=1;
                 }
             }
             else{
                 if(v[i]!=0){
                    return false;
                 }
             }
        }
        if(t==0){
            return false;
        }
        return true;
    }
};