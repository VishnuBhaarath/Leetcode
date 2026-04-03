class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        unordered_map<int,int> umap;
         unordered_map<int,char> umap1;
        vector<int> v=positions;
        for(int i=0;i<positions.size();i++){
             umap[positions[i]]=healths[i];
             umap1[positions[i]]=directions[i];
            
        }
        sort(positions.begin(),positions.end());
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<positions.size();i++){
             if(umap1[positions[i]]=='R'){
                st.push(positions[i]);
             }
             else{
                int t=0;
                while(!st.empty()){
                      
                     int tp=st.top();
                     st.pop();
                     if(umap1[tp]=='R'){
                         if(umap[tp]> umap[positions[i]]){
                             umap[tp]=umap[tp]-1;
                             umap[positions[i]]=-1;
                             st.push(tp);
                             t=1;
                             break;
                         }
                         else if(umap[tp]== umap[positions[i]]){
                             umap[tp]=-1;
                             umap[positions[i]]=-1;
                             t=1;
                             break;
                         }
                         else {
                             umap[positions[i]]=umap[positions[i]]-1;
                             umap[tp]=-1;
                         }
                     }
                     else{
                        st.push(tp);
                        st.push(positions[i]);
                        t=1;
                        break;
                     }
                }
                if(t==0){
                    st.push(positions[i]);
                }
             }
              
        }
        
         for(int i=0;i<v.size();i++){
            if(umap[v[i]]!=-1){
                ans.push_back(umap[v[i]]);
            }
         }

        return ans;
       

    }
};