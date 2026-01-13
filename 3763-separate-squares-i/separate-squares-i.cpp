class Solution {
public:
   double helper(double line, vector<vector<int>>& squares){
        double aAbove = 0, aBelow = 0;
        int n = squares.size();
        for(int i = 0; i < n; i++){
            int x = squares[i][0], y = squares[i][1];
            int l = squares[i][2];
            double total = (double) l * l;
            
            if(line <= y){
                aAbove += total;
            } 
            else if(line >= y + l){
                aBelow += total;
            } 
            else{
                 // The line intersects the square.
                double aboveHeight = (y + l) - line;
                double belowHeight = line - y;
                aAbove += l * aboveHeight;
                aBelow += l * belowHeight;
            }
        }
        return aAbove - aBelow;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double l0=0;
        double hi=2*1e9;
        double val=-1;
        while(hi - l0 > 1e-6){
            double m=l0+(hi-l0)/2.0;
            double diff = helper(m, squares);

            if(diff > 0) l0 = m;
            else hi = m;
           
        }
        return hi;
    }
  
};