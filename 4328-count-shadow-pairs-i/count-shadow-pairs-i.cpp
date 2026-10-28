class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        stack<pair<int,int>> st;
        int n=nums.size();
        long long int cnt=0;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({nums[i],1});
            }
            else if(st.top().first<nums[i]){
                cnt+=st.size();
                st.push({nums[i],1});
            }
            else if(st.top().first==nums[i]){
                cnt+=(st.size()-st.top().second);
                st.push({nums[i],st.top().second+1});
            }
            else{
                while(st.top().first>nums[i]){
                    st.pop();
                    if(st.empty()){
                        break;
                    }
                }
                if(!st.empty()){
                    if(st.top().first<nums[i]){
                        cnt+=st.size();
                        st.push({nums[i],1});
                    }
                    else if(st.top().first==nums[i]){
                        cnt+=(st.size()-st.top().second);
                        st.push({nums[i],st.top().second+1});
                    }
                }
                else{
                st.push({nums[i],1});}
            }

        }

        return cnt;
    }
};