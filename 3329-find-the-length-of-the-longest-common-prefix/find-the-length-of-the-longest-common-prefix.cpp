class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        unordered_set<string> s;
        for(int i=0;i<arr1.size();i++){
            string st=to_string(arr1[i]);
            string temp="";
            for(int j=0;j<st.size();j++){
                temp+=st[j];
                s.insert(temp);
            }
        }
//int ans=0;
        for(int j=0;j<arr2.size();j++){
            string st=to_string(arr2[j]);
            string temp="";
            for(int j=0;j<st.size();j++){
                temp+=st[j];
                if(s.count(temp)!=0){
                    ans=max(ans,(int)temp.size());
                }
            }
        }
        return ans;
    }
};