class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
         int n=nums.size();
        vector<int> l(n,-1);
        vector<int> r(n,-1);
        stack<int> s;
        long long sum=nums[0];              // CHANGE 1: int -> long long (prefix sum can reach ~1e12)
        vector<long long> psum;             // CHANGE 1: vector<int> -> vector<long long>
        psum.push_back(sum);
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            psum.push_back(sum);
        }
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(i);
            }
            else if(nums[i]>=nums[s.top()]){
                l[i]=s.top();
                s.push(i);
            }
            else{
                while(nums[i]<nums[s.top()]){
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                if(!s.empty()){
                    l[i]=s.top();
                }
                s.push(i);
            }
        }

        while(!s.empty()){
            s.pop();
        }

        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                s.push(i);
            }
            else if(nums[i]>nums[s.top()]){
                r[i]=s.top();
                s.push(i);
            }
            else{
                 while(nums[i]<=nums[s.top()]){
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                if(!s.empty()){
                    r[i]=s.top();
                }
                s.push(i);
            }
        }

        // CHANGE 2: removed all the cout debug printing of l, r and psum

        long long ans=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            long long sum=0;
            if(l[i]==-1 && r[i]==-1){
                sum=psum[n-1];              // CHANGE 4: was psum[i]. No smaller element on either side, so the range is the whole array
            }
            else if(l[i]!=-1 && r[i]==-1){
                sum=psum[n-1]-psum[l[i]];
            }
            else if(l[i]==-1 && r[i]!=-1){
                sum=psum[r[i]-1];
            }
            else if(l[i]!=-1 && r[i]!=-1){
                sum=psum[r[i]-1]-psum[l[i]];
            }
            long long val=sum*nums[i];
            ans=max(ans,val);
            // CHANGE 3: removed ans%=mod from here, because you must compare true values
        }

        return ans%mod; 
    }
};