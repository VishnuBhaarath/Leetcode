class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> s;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(s.empty()){
                if(nums[i]!=0){
                s.push(nums[i]);}
            }
            else if(nums[i]>s.top()){
                s.push(nums[i]);
            }
           
            else{
                while(nums[i]<s.top()){
                    s.pop();
                    cnt+=1;
                    if(s.empty()){
                        break;
                    }
                }
                if(!s.empty()){
                while(nums[i]==s.top()){
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                }
                if(nums[i]!=0){
                s.push(nums[i]);}
            }
        }

     return cnt+s.size();   
    }
};