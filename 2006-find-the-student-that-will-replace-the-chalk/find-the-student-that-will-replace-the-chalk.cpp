class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        long long int r=k%sum;
      
        for(int i=0;i<chalk.size();i++){
           
            if(chalk[i] > r){
                
                return i;
            }
            r-=chalk[i];
        }
    return -1;
    }
};