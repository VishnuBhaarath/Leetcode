class Solution {
public:
    int candy(vector<int>& ratings) {
        int cnt=0;
        int n=ratings.size();
        vector<int> v (n,1);
        
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
               if(v[i]<=v[i-1]){
                v[i]=v[i-1]+1;
                
               }
            }
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                if(v[i-1]<=v[i]){
                    v[i-1]=v[i]+1;
                 
                }
            }
        }
        for(int i=0;i<v.size();i++){
            cnt+=v[i];
        }
        cout<<"\n";
        return cnt;
    }
};