class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int table[n][n];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        for(int k=0;k<n;k++){
            for(int i=0,j=k;j<n;i++,j++){
                int x=0;
                int y=0;
                int z=0;
                if((i+2<=j)){
                    x=table[i+2][j];
                }
                if((i+1<=j-1)){
                    y=table[i+1][j-1];
                }
                if(i<=j-2){
                    z=table[i][j-2];
                }
                table[i][j]=max(nums[i]+min(x,y),nums[j]+min(y,z));
            }
        }
        int diff=sum-table[0][n-1];
        if(diff>table[0][n-1]){
        return false;}
        return true;
    }
};