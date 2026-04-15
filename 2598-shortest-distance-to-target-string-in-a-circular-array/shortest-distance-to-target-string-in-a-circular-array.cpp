class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int idx=-1;
        int n=words.size();
        for(int i=0;i<words.size();i++){
            if(words[i]==target){
                 if(i==startIndex){
                    return 0;
                 }
                 if(i>startIndex){
                    int idx1=i-startIndex;
                    int idx2=startIndex+(n-i);
                    int ans=min(idx1,idx2);
                    if(idx==-1){
                        idx=ans;
                    }
                    else{
                        idx=min(idx,ans);
                    }
                 }
                 else if(i<startIndex){
                     int idx1=startIndex-i;
                     int idx2=i+(n-startIndex);
                     int ans=min(idx1,idx2);
                     if(idx==-1){
                        idx=ans;
                     }
                     else{
                        idx=min(idx,ans);
                     }
                 }
            }
        }
        return idx;
    }
};