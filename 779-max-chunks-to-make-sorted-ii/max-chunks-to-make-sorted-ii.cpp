class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(nums[i]);
            }
            else if(nums[i]>=st.top()){
                st.push(nums[i]);
            }
            else{
                int tp=st.top();
                st.pop();
                if(!st.empty()){
                    while(nums[i]<st.top()){
                        st.pop();
                        if(st.empty()){
                            break;
                        }
                    }
                }
                st.push(tp);
                
            }
        }
        int ans=st.size();
      

        return ans;
        
    }
};