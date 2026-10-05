class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> v;
       
    
        for(int i=0;i<ranges.size();i++){
            int l=i-ranges[i];
            int r=i+ranges[i];
            l=max(l,0);
            r=min(r,n);
            v.push_back({l,r});
            
           
        
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i][0];
            cout<<" ";
            cout<<v[i][1];
            cout<<"\n";
        }
        if(v[0][0]>0){
            return -1;
        }
        int l=0;
        int r=v[0][1];
        int cnt=1;
        if(r>=n){
            return 1;
        }
        cout<<l;
        cout<<" ";
        cout<<r;
        cout<<"\n";
        int j=1;
        while(1){
            int idx=-1;
            int val=r;
            for(int i=j;i<v.size();i++){
                if(v[i][0]==l){
                    r=max(r,v[i][1]);
                    val=r;
                    if(val>=n){
                        return cnt;
                    }
                }
                else if(v[i][0]<=r){
                    if(v[i][1]>val){
                        val=v[i][1];
                        idx=i;
                    }
                }
                else{
                    break;
                }
            }
          
            if(idx==-1){
                return -1;
            }
            if(v[idx][0]>l){
                l=v[idx][0];
                cnt+=1;
            }
           
            
            if(val>=n){
                return cnt;
            }
            r=val;
            j=idx+1;
        }
       

        return cnt;
    }
};