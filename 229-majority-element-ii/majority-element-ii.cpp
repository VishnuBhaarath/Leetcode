class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=0;
        int num2=0;
        int cnt1=0;
        int cnt2=0;

        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=num2){
                cnt1=1;
                num1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=num1){
                cnt2=1;
                num2=nums[i];
            }
            else if(num1==nums[i]){
                cnt1+=1;
            }
            else if(num2==nums[i]){
                cnt2+=1;
            }
            else{
                cnt1-=1;
                cnt2-=1;
            }
        }
        cnt1=cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1){
                cnt1+=1;
            }
            else if(nums[i]==num2){
                cnt2+=1;
            }
        }
        int n=nums.size()/3;
        vector<int> v;
        if(cnt1>n){
          v.push_back(num1);
        }
        if(cnt2>n){
            v.push_back(num2);
        }
       return v;
    }
};