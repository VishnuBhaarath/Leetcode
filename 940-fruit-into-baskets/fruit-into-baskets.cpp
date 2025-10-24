class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        int j=0;
        int temp1=-1;
        int temp2=-1;
        int cnt=0;
        int cnt1=0;
        int cnt2=0;
        int ans=0;
        while(j<fruits.size()){
           
            if(temp1==-1 || temp1==fruits[j]){
                temp1=fruits[j];
                cnt=1;
                cnt1+=1;
            }
            else if(temp2==-1 || temp2==fruits[j]){
                temp2=fruits[j];
                cnt=2;
                cnt2+=1;
            }
            else{
                while(i<=j){
                    if(fruits[i]==temp1){
                        cnt1-=1;
                    }
                    else if(fruits[i]==temp2){
                        cnt2-=1;
                    }
                      i+=1;
                    if(cnt1==0 || cnt2==0){
                        break;
                    }
                  
                }
                
                if(cnt1==0){
                    temp1=temp2;
                    temp2=fruits[j];
                    cnt1=cnt2;
                    cnt2=1;
                }
                else if(cnt2==0){
                     temp2=fruits[j];
                     cnt2=1;
                }
            }
            ans=max(ans,cnt1+cnt2);
          
           
            j+=1;
        }
          return ans;
    }
};