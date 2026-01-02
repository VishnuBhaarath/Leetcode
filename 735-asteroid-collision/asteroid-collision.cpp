class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i=0;i<asteroids.size();i++){
            if(s.empty()){
                s.push(asteroids[i]);
            }
            else if(asteroids[i]<0){
                 if(s.top()<0){
                    s.push(asteroids[i]);
                 }
                 else{
                     while(s.top()>0){
                         if(s.top()>abs(asteroids[i])){
                             break;
                         }
                         else if(s.top()==abs(asteroids[i])){
                            s.pop();
                            break;
                         }
                         else{
                             s.pop();
                             if(s.empty()){
                                s.push(asteroids[i]);
                                break;
                             }
                             if(s.top()<0){
                                s.push(asteroids[i]);
                                break;
                             }
                         }
                     }
                 }
            }
            else if(asteroids[i]>0){
                 s.push(asteroids[i]);
            }
        }
        vector<int> ans(s.size(),0);
        int j=s.size()-1;
        while(!s.empty()){
            ans[j]=s.top();
            s.pop();
            j-=1;
        }
        return ans;
    }
};