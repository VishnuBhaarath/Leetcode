class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        s.push(asteroids[0]);

        for(int i=1;i<asteroids.size();i++){
            if(s.empty()){
                s.push(asteroids[i]);
            }
            else if((asteroids[i]>0 && s.top()>0) || (asteroids[i]<0 && s.top()<0) || (s.top()<0 && asteroids[i]>0)){
                s.push(asteroids[i]);
            }
            else{
                while(1){
                    int tp=s.top();
                    s.pop();
                    int t=0;
                    if(tp>0 && asteroids[i]<0){
                        if(abs(asteroids[i]) < abs(tp)){
                            s.push(tp);
                            break;
                        }
                        else if(abs(asteroids[i]) == abs(tp)){
                           
                                break;
                            
                        }
                        else if(abs(asteroids[i]) > abs(tp)){
                            if(s.empty()){
                                s.push(asteroids[i]);
                                    break;
                                
                            }
                        }
                    }
                    else{
                        s.push(tp);
                        s.push(asteroids[i]);
                        break;
                    }
                }
                
            }
    }
  
    vector<int> v(s.size(),-1);
    int m=s.size();
    while(!s.empty()){
        v[m-1]=s.top();
        s.pop();
        m-=1;
    }
    return v;
    }
};