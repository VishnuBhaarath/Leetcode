class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> v(n,1);
        for(int i=1;i<ratings.size();i++){
             if(ratings[i]>ratings[i-1]){
                v[i]=v[i-1]+1;
             }
        }
       
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                if(v[i-1]<=v[i]){
                    v[i-1]=1+v[i];
                }
                if((i-2)>=0){
                    if(ratings[i-2]>ratings[i-1]){
                        if(v[i-2]<=v[i-1]){
                            v[i-2]=v[i-1]+1;
                        }
                    }
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