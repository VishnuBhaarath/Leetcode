class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int ans=1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int h1=-1;
        int w1=-1;
        if(hBars.size() == n){
            //h1=n+2;

        }
        if(vBars.size()==m){
           //  w1=m+2;
        }
        if(h1==w1){
           // ans=h1*w1;
        }
        cout<<h1;
        cout<<" ";
        cout<<w1;
        cout<<" ";
        cout<<ans;
        cout<<"\n";
        int h=1;

        for(int i=0;i<hBars.size();i++){
             if(i==0){
                h+=1;
             }
             else if(hBars[i]==hBars[i-1]+1){
                h+=1;
             }
             else{
                h=2;
             }
              int w=1;
             for(int j=0;j<vBars.size();j++){
                if(j==0){
                    w+=1;
                }
                else if(vBars[j]==vBars[j-1]+1){
                    w+=1;
                }
                else{
                    w=2;
                }
                if(w==h){
                    cout<<w;
                    cout<<" ";
                    cout<<h;
                    cout<<"\n";
                    int area=w*h;
                    ans=max(ans,area);
                }
                if(h1==-1){
                    if(w==h1){
                        int area=w*h1;
                        ans=max(ans,area);
                    }
                }
             }
        }
          return ans;
    }
};