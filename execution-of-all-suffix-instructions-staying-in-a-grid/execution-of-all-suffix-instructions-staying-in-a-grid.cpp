class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> v;
        for(int i=0;i<s.size();i++){
            int x=startPos[1];
            int y=startPos[0];
            int cnt=0;
           
            for(int j=i;j<s.size();j++){
               
                if(s[j]=='R'){
                    if((x+1)<n){
                        cnt+=1;
                        x+=1;
                    }
                    else{
                        break;
                    }
                }
                else if(s[j]=='L'){
                    if((x-1)>=0){
                        x-=1;
                        cnt+=1;
                    }
                    else{
                        break;
                    }
                }
                else if(s[j]=='U'){
                    if((y-1)>=0){
                        y-=1;
                        cnt+=1;
                    }
                    else{
                        break;
                    }
                }
                else if(s[j]=='D'){
                    if((y+1)<n){
                        y+=1;
                        cnt+=1;
                    }
                    else{
                        break;
                    }
                }
            }
            v.push_back(cnt);
        }
        return v;
    }
};