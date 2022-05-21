class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int idx=nums[0];
        if(idx>=n-1){
            return 1;
        }
        int steps=1;
        int idx1=-1;
        for(int i=1;i<nums.size();i++){
            cout<<idx;
            cout<<" ";
            cout<<nums[i];
            cout<<"   ";
            if(i<idx){
                idx1=max(idx1,(i+nums[i]));
                cout<<idx1;
                cout<<" ";
                cout<<steps;
                cout<<" ";
                if(idx1>=(n-1)){
                    return steps+1;
                }
                
            }
            else if(i==idx){
                idx1=max(idx1,(i+nums[i]));
                if(idx1>=(n-1)){
                    return steps+1;
                }
                idx=idx1;
                steps+=1;
            }
            else{
                idx=idx1;
                steps+=1;
            }
            cout<<"\n";
        }
        return steps;
    }
};