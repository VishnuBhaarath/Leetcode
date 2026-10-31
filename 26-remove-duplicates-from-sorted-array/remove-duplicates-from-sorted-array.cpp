class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> umap;
        int i=0;
        int j=0;
        int n=nums.size();
        int cnt=0;
        while(j<n){
            if(umap[nums[j]]==0){
                 umap[nums[j]]+=1;
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                i+=1;
                cnt+=1;
              //  j+=1;
            }
            else{
               
            }

           
             j+=1;


        }
        
        return cnt;
    }
};