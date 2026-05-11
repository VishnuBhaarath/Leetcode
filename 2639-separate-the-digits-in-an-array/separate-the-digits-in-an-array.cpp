class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
             int val=nums[i];
             string st=to_string(val);
             for(int j=0;j<st.size();j++){
                ans.push_back(st[j]-'0');
             }
        }

        return ans;
    }
};