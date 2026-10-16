class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> v(n,0);
        set<char> s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        for(int i=0;i<words.size();i++){
             int m=words[i].size();
           
             if(s.find(words[i][0])!=s.end() && s.find(words[i][m-1])!=s.end()){
               
                 if(i==0){
                    v[i]=1;
                 }
                 else{
                    v[i]=v[i-1]+1;
                 }
             }
             else{
             
                if(i>0){
                v[i]+=v[i-1];}
             }
             
        }

       
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==0){
                ans.push_back(v[queries[i][1]]);
            }
            else{
                ans.push_back(v[queries[i][1]]-v[queries[i][0]-1]);
            }
        }

        return ans;
    }
};