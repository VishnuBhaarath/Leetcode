class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        multiset<int> s;
        vector<int> ans;
        
        int j=1;
        int i=0;
        s.insert(nums[0]);
        while(j<nums.size()){
           
             if((nums[j]-nums[j-1]==1)){
                s.insert(nums[j]);
                if(s.size()==k){
                   auto it=*s.rbegin();
               
                   ans.push_back(it);
                 
                   auto it1=s.find(nums[i]);
                   if(it1!=s.end()){
                   s.erase(it1);}
                   i+=1;

                }

             }
             else{
               
                int l=nums.size()-i;
                if(l<k){
                    return ans;
                }
                int t=0;
                while(t<(j-i)){
               
                    ans.push_back(-1);
                    t+=1;
                    l-=1;
                    if(l<k){
                        return ans;
                    }
                }
                
                cout<<-1;
                cout<<"\n";
                s.clear();
                s.insert(nums[j]);
                i=j;
                 
             }
             j+=1;
            
        }
      //  vector<int> ans;

        return ans;
    }
};