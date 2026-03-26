class Solution {
public:
    bool isPalindrome(string &s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void fun(string &s, int n, int idx, vector<string> &diary, vector<vector<string>> &res){
        if(idx == n){
            res.push_back(diary);
            return;
        }

        for(int j = idx; j < n; j++){
            // check substring s[idx...j]
            if(isPalindrome(s, idx, j)){
                diary.push_back(s.substr(idx, j - idx + 1)); // take substring
                fun(s, n, j + 1, diary, res);               // move ahead
                diary.pop_back();                           // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        int idx = 0;

        vector<string> diary;                 // ❌ fixed
        vector<vector<string>> res;

        fun(s, n, idx, diary, res);           // ❌ fixed
        return res;
    }
};