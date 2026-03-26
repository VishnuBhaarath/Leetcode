class Solution {
public:
vector<string> v;
    void func(int n,int m, int open,string s){
         if(n==0 && m==0){
       
            v.push_back(s);
         
            
            return;
         }
         
         if(n>0){
             s+='(';
             func(n-1,m,open+1,s);
             s.pop_back();
         }
         if(m>0 && open>0){
            s+=')';
            func(n,m-1,open-1,s);
            s.pop_back();
         }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        func(n,n,0,s);
        
        return v;
    }
};