class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
         int n=nums.size();
        int m=(n/3);
        priority_queue<int> pq1;
        priority_queue<int,vector<int>,greater<int>> pq;
        long long int sum=0;
        int j=0;
        vector<long long> v;     // was vector<int>
        vector<long long> v1;    // was vector<int>
        for(int i=0;i<m;i++){
            sum+=nums[i];
            pq1.push(nums[i]);
            j=i;
        }
        v.push_back(sum);

        long long int sum1=0;
        int k=0;
        for(int i=n-1;i>=(n-(m));i--){
            sum1+=nums[i];
            pq.push(nums[i]);
            k=i;
        }
        v1.push_back(sum1);

        j+=1;
        k-=1;

        while(j<(2*m)){
            sum+=nums[j];
            pq1.push(nums[j]);
            int tp=pq1.top();
            pq1.pop();
            sum-=tp;
            j+=1;
            v.push_back(sum);
        }

        while(k>=(n-2*m)){
            sum1+=nums[k];
            pq.push(nums[k]);
            int tp=pq.top();
           
            pq.pop();
            sum1-=tp;
            k-=1;
            v1.push_back(sum1);
        }
        reverse(v1.begin(),v1.end());
        long long int ans=LLONG_MAX;   // was INT_MAX
        for(int i=0;i<v.size();i++){
            if(v[i]-v1[i]<ans){
            ans=v[i]-v1[i];
            }
      
        }

        return ans;
    }
};