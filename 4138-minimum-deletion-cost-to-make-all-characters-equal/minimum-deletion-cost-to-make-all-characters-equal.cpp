class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long int> v(26,0);
     
        long long int sum=0;
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']+=cost[i];
            sum+=cost[i];
           
        }
        long long int val=-1;
        for(int i=0;i<v.size();i++){
            
            if(v[i]!=0){
                if(val==-1){
                    val=sum-v[i];
                }
                val=min(val,(sum-v[i]));
            }
        }
        return val;
        
    }
};