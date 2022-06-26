class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        col=len(grid[0])
        row=len(grid)
       
        ###initialize the last col:
        i=0
      
        while(i<row):
            j=0
            while(j<col):
                if i>0:
                    if j>0:
                        grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
                    else:
                        grid[i][j]+=grid[i-1][j]
                else:
                    if(j>0):
                        grid[i][j]+=grid[i][j-1]
                        
                j+=1
            i+=1    
                  
        return grid[row-1][col-1]