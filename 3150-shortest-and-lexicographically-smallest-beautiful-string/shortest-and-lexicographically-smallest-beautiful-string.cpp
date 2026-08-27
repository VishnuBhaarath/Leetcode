class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();

        int l=0;
        int r=0;

        int cnt=0;
        int len=-1;
        string temp="";
        while(r<n){
            if(s[r]=='1'){
                if(cnt<k){
                    cnt+=1;
                    if(cnt==k){
                          string s1=s.substr(l,(r-l+1));
                        
                        if(len==-1){
                            len=s1.size();
                            temp=s1;
                        }
                        else{
                            if(s1.size() ==len){
                                if(s1< temp){
                                    temp=s1;
                                }

                            }
                            else if(s1.size() < len){
                                len=s1.size();
                                temp=s1;
                            }

                        }
                        
                    }
                }
                else{
                    while(s[l]=='0'){
                        l+=1;
                    }
                    l+=1;
                      string s1=s.substr(l,(r-l+1));
                 
                   
                    if(len==-1){
                            len=s1.size();
                            temp=s1;
                        }
                        else{
                            if(s1.size() ==len){
                                if(s1< temp){
                                    temp=s1;
                                }
                            }
                            else if(s1.size() < len){
                                len=s1.size();
                                temp=s1;
                            }
                        }
                  

                    
                }
            }
            else{
                if(cnt==k){
                      string s1=s.substr(l,(r-l+1));
                     
                      
                      if(len==-1){
                            len=s1.size();
                            temp=s1;
                        }
                        else{
                            if(s1.size() ==len){
                                if(s1< temp){
                                    temp=s1;
                                }
                            }
                            else if(s1.size() < len){
                                len=s1.size();
                                temp=s1;
                            }
                        }
                        
                }
            }
            while(s[l]=='0'){
                l+=1;
            }
            string s1=s.substr(l,(r-l+1));
                   
                    
                          if(cnt==k){
                           if(len==-1){
                            len=s1.size();
                            temp=s1;
                        }
                        else{
                            if(s1.size() ==len){
                                if(s1< temp){
                                    temp=s1;
                                }
                            }
                            else if(s1.size() < len){
                                len=s1.size();
                                temp=s1;
                            }
                        }}
                        
            r+=1;
        }
        while(cnt==k){
            if(s[l]=='0'){
                l+=1;
                string s1=s.substr(l,(r-l+1));
                 
                  if(len==-1){
                            len=s1.size();
                            temp=s1;
                        }
                        else{
                            if(s1.size() ==len){
                                if(s1< temp){
                                    temp=s1;
                                }
                            }
                            else if(s1.size() < len){
                                len=s1.size();
                                temp=s1;
                            }
                        }
                        
            }
            else{
                break;
            }
        }
        return temp;
    }
};