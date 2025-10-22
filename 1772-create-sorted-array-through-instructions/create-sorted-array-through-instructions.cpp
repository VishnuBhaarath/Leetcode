class Solution {
public:
    void merge(vector<pair<int, pair<int, int>>> &v,int l,int m, int r){
  
        vector<pair<int, pair<int, int>>> left;
        vector<pair<int, pair<int, int>>> right;
      
        for(int i=l;i<=m;i++){
            left.push_back(v[i]);
        }
        for(int i=m+1;i<=r;i++){
            right.push_back(v[i]);
        }
    
      

        for(int i=0;i<right.size();i++){
            int num=right[i].first;
            int l1=0;
            int r1=left.size()-1;
            int idx1=-1;
            while(l1<=r1){
                int m1=l1+(r1-l1)/2;

                if(left[m1].first < num){
                    idx1=m1;
                    l1=m1+1;
                }
                else{
                     r1=m1-1;
                }
            }
            if(idx1!=-1){
                right[i].second.second+=(idx1+1);
            }
            l1=0;
            r1=left.size()-1;
            idx1=-1;
             while(l1<=r1){
                int m1=l1+(r1-l1)/2;

                if(left[m1].first > num){
                    idx1=m1;
                    r1=m1-1;
                }
                else{
                     l1=m1+1;
                }
            }
            if(idx1!=-1){
                right[i].second.first+=(left.size()-idx1);
            }
        }

      //   vector<pair<int, pair<int, int>>> temp;
         int idx1=0;
         int idx2=0;
         while(idx1<left.size() && idx2<right.size()){
            if(left[idx1].first < right[idx2].first){
              //  temp.push_back(left[idx1]);
                 v[l]=left[idx1];
                idx1+=1;
                l+=1;
            }
            else{
              //  temp.push_back(right[idx2]);
                v[l]=right[idx2];
                l+=1;
                idx2+=1;
            }
         }
         while(idx1<left.size()){
           //  temp.push_back(left[idx1]);
             v[l]=left[idx1];
             l+=1;
                idx1+=1;
         }
         while(idx2<right.size()){
          //  temp.push_back(right[idx2]);
            v[l]=right[idx2];
            l+=1;
            idx2+=1;
         }
       
     


    }

    void mergesort(vector<pair<int, pair<int, int>>> &v,int l, int r){
        if(l>=r){
            return;
        }

        int m=l+(r-l)/2;
        mergesort(v,l,m);
        mergesort(v,m+1,r);
        merge(v,l,m,r);
        return;
    }
    int createSortedArray(vector<int>& instructions) {
        vector<pair<int, pair<int, int>>> v;
        for(int i=0;i<instructions.size();i++){
            v.push_back({instructions[i],{0,0}});
        }
        int n=instructions.size();
        mergesort(v,0,n-1);
        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<v.size();i++){
            
            ans+=min(v[i].second.first,v[i].second.second);
            ans%=mod;
       
        }
        
        return ans;
    }
};