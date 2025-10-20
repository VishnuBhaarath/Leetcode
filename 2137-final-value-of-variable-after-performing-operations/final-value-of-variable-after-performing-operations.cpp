class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val=0;
        for(int i=0;i<operations.size();i++){
             string st=operations[i];
             if(st[0]=='-' || st[1]=='-'){
                val-=1;
             }
             else{
                val+=1;
             }
        }
        return val;
    }
};