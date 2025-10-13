class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j, int color,int color1){
        if(i<0 || i>=image.size()){
            return;
        }
        if(j<0 ||j>=image[0].size()){
            return;
        }
        if(image[i][j]!=color1){
            return;
        }
      
        int temp=image[i][j];
        image[i][j]=color;
        dfs(image,i+1,j,color,temp);
        dfs(image,i,j+1,color,temp);
        dfs(image,i-1,j,color,temp);
        dfs(image,i,j-1,color,temp);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc]){
            return image;
        }
        dfs(image,sr,sc,color,image[sr][sc]);

        return image;


    }
};