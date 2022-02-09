class Solution {
public:
    string convert(string s, int numRows) {
        string s1="";
        if(numRows==1){
            return s;
        }
        if(numRows>=s.size()){
            return s;
        }
        int t=numRows+(numRows-2);
        int t1=t-2;
        for(int i=0;i<numRows;i++){
            if(i>=s.size()){
                break;
            }
            if((i==0)||(i==numRows-1)){
                int j=i;
                s1+=s[j];
                while(j+t<s.size()){
                    j=j+t;
                    s1+=s[j];
                }
             }
            else{
                int j=i;
                s1+=s[j];
                while(j+t1<s.size()){
                    s1+=s[j+t1];
                    if(j+t<s.size()){
                        s1+=s[j+t];
                    }
                    j=j+t;
                }
                t1-=2;
            }
        }
        return s1;
    }
};