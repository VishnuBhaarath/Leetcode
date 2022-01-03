class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
       long long int val=mass;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>val){
                return false;
            }
            val+=asteroids[i];
        }
        return true;
    }
};