class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> v (n,1);
        
        for(int i=1;i<ratings.size();i++){
         
            if(ratings[i]<=ratings[i-1]){
                v[i]=1;
                if(ratings[i]<ratings[i-1]){
                if(v[i-1]==1){
                    v[i-1]=2;
                }}
            }
            else{
                v[i]=v[i-1]+1;
            }
        }
       
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                if(v[i]<=v[i+1]){
                    v[i]=v[i+1]+1;
                }
            }
        
        }

        int sum=0;
        for(int i=0;i<v.size();i++){
         
            sum+=v[i];
        }
   
        return sum;
    }
};