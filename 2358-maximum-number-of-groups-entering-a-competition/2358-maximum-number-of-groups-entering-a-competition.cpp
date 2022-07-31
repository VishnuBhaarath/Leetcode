class Solution {
public:
    int maximumGroups(vector<int>& grades) {
      
        int i=0;
        int cnt=1;
        int j=2;
        int prev=grades[i];
        while(j<grades.size()){
           
            cnt+=1;
            int k=j-i;
           
            if((j+k+1)>=grades.size()){
                return cnt;
            }
            int temp=j;
            i=j;
            j=temp+k+1;
            
        }
       
        return cnt;
    }
};