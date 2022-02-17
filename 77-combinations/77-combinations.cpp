class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
    vector<int>num;
        for(int i=1; i<=n; i++){
            num.push_back(i);
        }
        
        vector<vector<int>>result;
        vector<int>answer;
        form_combinations(num,0,answer,result,k);
        return result;
    }
   void form_combinations( vector<int>num, int i,vector<int>&answer, vector<vector<int>>&result, int k){
        if(k==0){
            result.push_back(answer);
            return;
        }
        
        if(i==num.size()){
            return;
        }
        
        if(num.size()-i < k){ // TLE solved using this
            return;
        }
        
        answer.push_back(num[i]);
        form_combinations(num,i+1,answer,result,k-1);
        answer.pop_back();
        form_combinations(num,i+1,answer,result,k);
        return;
    }
};