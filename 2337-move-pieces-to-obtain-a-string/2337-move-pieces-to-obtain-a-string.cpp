class Solution {
public:
    bool canChange(string start, string target) {
        int startL=0;
        int startR=0;
        int targetL=0;
        int targetR=0;
        for(int i=0;i<start.size();i++){
            if(start[i]=='L'){
                startL+=1;
            }
            if(target[i]=='L'){
                targetL+=1;
            }
            if(start[i]=='R'){
                startR+=1;
            }
            if(target[i]=='R'){
                targetR+=1;
            }
        }
        if(startL!=targetL){
            return false;
        }
        if(startR!=targetR){
            return false;
        }
        int r1=0;
        int r2=0;
        int l1=0;
        int l2=0;
        for(int i=0;i<start.size();i++){
            if(target[i]=='R'){
                
                r2+=1;
            }
            if(start[i]=='R'){
               
                r1+=1;
            }
            if(r2>r1){
                return false;
            }
            if(start[i]=='L'){
               
                l1+=1;
            }
            if(target[i]=='L'){
                l2+=1;
            }
            if(l1>l2){
               return false;
            }
            if(start[i]=='L'){
                 if(r1!=r2){
                    return false;
                }
                r1=0;
                r2=0;
            }
            if(start[i]=='R'){
                 if(l1!=l2){
                    return false;
                }
                l1=0;
                l2=0;
            }
            if(target[i]=='L'){
                if(r1>r2){
                    if(l1<l2){
                        return false;
                    }
                }
            }
            
            
            
        }
        return true;
    }
};