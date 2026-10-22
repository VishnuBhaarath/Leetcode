class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> s;
        int n=students.size();
        int cnt=0;
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(students[i]==1){
                cnt+=1;
            }
            if(sandwiches[i]==1){
                cnt1+=1;
            }
            s.push(i);
        }
        int cnt2=n-cnt;
        int cnt3=n-cnt1;
        int j=0;
      //  vector<int> v(n,0);
        while(!s.empty()){
            int tp=s.front();
            s.pop();
            if(students[tp]==sandwiches[j]){
                if(sandwiches[j]==1){
                    cnt1-=1;
                    cnt-=1;
                }
                else{
                    cnt2-=1;
                    cnt3-=1;
                }
                j+=1;
            }
            else{
                if(students[tp]==1){
                    if(cnt2==0){
                        s.push(tp);
                        break;
                    }
                }
                if(students[tp]==0){
                   
                    if(cnt==0){
                        s.push(tp);
                        break;
                    }
                }
                s.push(tp);
               
            }
        }
        return s.size();
    }
};