class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        


         int n=arr.size();
        vector<int> l(n,-1);
        vector<int> r(n,-1);

        stack<int> s;
        for(int i=0;i<arr.size();i++){
            if(s.empty()){
                s.push(i);
            }
            else{
                if(arr[s.top()]<arr[i]){
                    s.push(i);
                }
                else{
                    while(arr[s.top()]>=arr[i]){
                        l[s.top()]=i;
                        s.pop();
                        if(s.empty()){
                            break;
                        }
                    }
                    s.push(i);
                }
            }
        }

      
        stack<int> s1;
        for(int i=n-1;i>=0;i--){
            if(s1.empty()){
                s1.push(i);
            }
            else{
                if(arr[s1.top()]<=arr[i]){
                    s1.push(i);
                }
                else{
                    while(arr[s1.top()]>arr[i]){
                        r[s1.top()]=i;
                        s1.pop();
                        if(s1.empty()){
                            break;
                        }
                    }
                    s1.push(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<l.size();i++){
            int l1=l[i];
            int r1=r[i];
            int w=1;
            if(r1!=-1 && l1!=-1){
                cout<<"one";
                w=(l1-r1-1);
            }
            else if(r1==-1 && l1!=-1){
                 cout<<"two";
                w=i+(l1-i);
            }
            else if(l1==-1 && r1!=-1){
                cout<<"three";
                w=(n-i)+(i-r1)-1;
            }
            else if(l1==-1 && r1==-1){
                cout<<"four";
                w=n;
            }
         
            int area=arr[i]*w;
            ans=max(ans,area);
            
        }

        return ans;
    }
};