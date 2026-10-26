class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.empty()){
                st.push(nums[i]);
            }
            else if(nums[i]>=st.top()){
                st.push(nums[i]);
            }
            else{

                while(nums[i]<st.top() && (n-i+st.size()-1)>=k){
                    st.pop();
                    if(st.empty()){
                        break;
                    }
                }
                st.push(nums[i]);
            }
        }
        vector<int> v;
        while(!st.empty()){
            
            v.push_back(st.top());
           
            st.pop();
        }
        reverse(v.begin(),v.end());

        vector<int> v1;
        int i=0;
        while(i<k){
            v1.push_back(v[i]);
            i+=1;
        }
        return v1;
    }
};