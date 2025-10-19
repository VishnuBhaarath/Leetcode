class Solution {
public:
    int ans=0;
    void merge(vector<int>& nums,int l, int m, int r){
     
       
        vector<int> temp;
        int idx1=l;
        int idx2=m+1;
        vector<long long int> left;
        vector<long long int> right;
        for(int i=l;i<=m;i++){
            left.push_back((long long)(nums[i]));
    
        }
        for(int i=m+1;i<=r;i++){
            right.push_back((long long)(nums[i]));
        }
       
        for(int i=0;i<left.size();i++){
            long long int num=(long long)(left[i]);
            int l1=0;
            int r1=right.size()-1;
            int cnt=-1;
            while(l1<=r1){
              
                int m1=l1+(r1-l1)/2;
               
                
             if((long long)(num) >(long long)((long long)(2)*(long long)(right[m1]))){
                    cnt=max(cnt,(m1+1));
                    l1=m1+1;

                }
                else if((long long)(num) >(long long)(right[m1])){
                   
                    r1=m1-1;

                }
                else if((long long)(num) <=(long long)(right[m1])){
                   
                    r1=m1-1;
                }
            }
            if(cnt!=-1){
                ans+=cnt;
            }
           
        }
        

        while(idx1<=m && idx2<=r){
            if(nums[idx1]<nums[idx2]){
                temp.push_back(nums[idx1]);
                idx1+=1;
            }
            else{
                temp.push_back(nums[idx2]);
                idx2+=1;
            }
        }
        while(idx1<=m){
            temp.push_back(nums[idx1]);
            idx1+=1;
        }
        while(idx2<=r){
            temp.push_back(nums[idx2]);
            idx2+=1;
        }
        int j=0;
        for(int i=l;i<=r;i++){
            nums[i]=temp[j];
            j+=1;
        }
    }
    void mergesort(vector<int>& nums,int l,int r){
        if(l>=r){
            return;
        }
        int m=l+(r-l)/2;
        mergesort(nums,l,m);
        mergesort(nums,m+1,r);
        merge(nums,l,m,r);
        return;

    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        
        return ans;
    }
};