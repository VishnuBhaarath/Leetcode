class Solution {
public:
    int check(vector<long long int> v){
       
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
            
                if((v[i]&v[j])!=0){
                     return -1;
                   
                }
            }
        }
     
        return v.size();
       
    }
    int longestNiceSubarray(vector<int>& nums) {
        long long int ans=1;
        for(int i=0;i<nums.size();i++){
            vector<long long int> v;
            v.push_back(nums[i]);
            for(int j=i+1;j<nums.size();j++){
                v.push_back(nums[j]);
                long long int val=check(v);
             
                ans=max(ans,val);
                if(val==-1){
                    break;
                }
                if(ans==30){
                    return ans;
                }
                if(v.size()==30){
                    break;
                }
            }
            
        }
    
        int num=1090;
        num=num&16384;
        num=num&33;
        num=num&217313281;
        cout<<num;
        cout<<"\n";

        return ans;
    }
};