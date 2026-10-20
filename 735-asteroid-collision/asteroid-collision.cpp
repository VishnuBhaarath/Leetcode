class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            if(s.empty()){
                s.push(asteroids[i]);
            }
            else if ((s.top() > 0 && asteroids[i] > 0) ||
         (s.top() < 0 && asteroids[i] < 0) ||
         (s.top() < 0 && asteroids[i] > 0))
         {
                s.push(asteroids[i]);
            }
            else{
                int t=0;
             
                while(!s.empty()){
                    int tp=s.top();
                    s.pop();
                 
                    if(tp>0 && asteroids[i]<0){
                        if(abs(tp)==abs(asteroids[i])){
                            t=1;
                            break;
                        }
                        else if(abs(tp)>abs(asteroids[i])){
                            s.push(tp);
                            t=1;
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                    else{
                        s.push(tp);
                        break;
                    }
                   
                }
              
                if(t==0){
                    s.push(asteroids[i]);
                }
               
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};