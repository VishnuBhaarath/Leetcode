class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int l=0;
        int r=n-1;
        while(l<r){
            for(int i=0;i<(r-l);i++){
                int tpleft=matrix[l][i+l];

                int tpright=matrix[l+i][n-1-l];

                int btright=matrix[r][r-i];

                int btleft=matrix[r-i][l];

                cout<<tpleft;
                cout<<" ";
                cout<<tpright;
                cout<<" ";
                cout<<btright;
                cout<<" ";
                cout<<btleft;
                cout<<"\n";

               matrix[l+i][n-1-l]=tpleft;
                matrix[r][r-i]=tpright;
                matrix[r-i][l]=btright;
               matrix[l][i+l]=btleft;

              
            }
            l+=1;
            r-=1;
            cout<<l;
            cout<<" ";
            cout<<r;
            cout<<"\n";
        }
    }
};