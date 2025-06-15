class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s.empty()) return 0;
        vector<int> count(128, 0);
        int maxLen=0;
        int left=0,right=0;
        int n=s.size();
       
        while(right<n){
            count[s[right]]++;
            while(count[s[right]]>1){
                count[s[left]]--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};