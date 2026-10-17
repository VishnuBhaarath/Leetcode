class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> umap;
        for(int i=0;i<arr.size();i++){
            int r = ((arr[i] % k) + k) % k;
            umap[r]+=1;
        }
        for(auto x:umap){
          
            if(x.first==0){
                if(x.second%2!=0){
                    return false;
                }
            }
            else{
           
                int val=umap[k-x.first];
                cout<<val;
                if(val!=x.second){
                    return false;
                }
                
            }
          
        }
        return true;
    }
};