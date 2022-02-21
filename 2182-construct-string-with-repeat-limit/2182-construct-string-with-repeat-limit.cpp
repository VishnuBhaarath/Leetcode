class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int> umap;
     
        for(int i=0;i<s.size();i++){
            umap[s[i]]+=1;
        }
        priority_queue<pair<char,int>> pq;
        for(auto x:umap){
            pq.push(make_pair(x.first,x.second));
        }
        string ans="";
        while(!pq.empty()){
            pair<char,int>p=pq.top();
        
            if(p.second<=repeatLimit){
                string s(p.second,p.first);
              
                ans+=s;
                pq.pop();
            }
            else{
                string s(repeatLimit,p.first);
              
                ans+=s;
                pq.pop();
                if(pq.empty()){
                    return ans;
                }
                pair<char,int>p1=pq.top();
                ans+=p1.first;
                pq.pop();
                pq.push(make_pair(p.first,p.second-repeatLimit));
               if(p1.second-1!=0){ 
                pq.push(make_pair(p1.first,p1.second-1));}
            }
           
        }
        return ans;
    }
};