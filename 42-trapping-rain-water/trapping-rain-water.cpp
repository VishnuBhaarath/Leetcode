class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> l(n,-1);
        vector<int> r(n,-1);
        int val=-1;
        for(int i=0;i<height.size();i++){
             if(val>=height[i]){
             l[i]=val;}
             else{
                l[i]=-1;
             }
             val=max(val,height[i]);
             
        }

          val=-1;
         for(int i=n-1;i>=0;i--){
             if(val>=height[i]){
             r[i]=val;}
             else{
                r[i]=-1;
             }
             val=max(val,height[i]);
        }
        
        long long ans=0;

       
        for(int i=0;i<l.size();i++){
             if(l[i]!=-1 && r[i]!=-1){
                ans+=min(l[i],r[i]);
                ans-=height[i];
             }
        }

        return ans;


    }
};