class Solution {
public:
       void nse(vector<int> & right,vector<int> & arr){
         int n=arr.size();
         stack<int> s1;
        s1.push(n-1);

        for(int i=n-2;i>=0;i--){
            if(s1.empty()){
                s1.push(i);
            }
            else if(arr[i]>=arr[s1.top()]){
                
                right[i]=s1.top();
                s1.push(i);
            }
            else{
                while(arr[i]<arr[s1.top()]){
                    s1.pop();
                    if(s1.empty()){
                        break;
                    }
                }
                if(!s1.empty()){
                    right[i]=s1.top();
                }
                s1.push(i);
            }
        }

    }
    void pse(vector<int> & left,vector<int> & arr){
         int n=arr.size();
        stack<int> s;
        s.push(0);
        for(int i=1;i<arr.size();i++){
            if(s.empty()){
                s.push(i);
            }
            else if(arr[i]>arr[s.top()]){
                  left[i]=s.top();
                  s.push(i);
            }
            else{
                while(arr[i]<=arr[s.top()]){
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                if(!s.empty()){
                    left[i]=s.top();
                }
                s.push(i);
            }
        }
       
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n,-1);
        vector<int> right(n,-1);

        pse(left,heights);
        nse(right,heights);
        int ans=0;
       
        for(int i=0;i<heights.size();i++){
            if(left[i]==-1 && right[i]==-1){
                ans=max(ans,(n*heights[i]));
            }
            else if(left[i]!=-1 && right[i]!=-1){
                 int w=(right[i]-left[i])-1;
                 ans=max(ans,(w*heights[i]));
            }
            else if(left[i]!=-1){
                int w=n-1-left[i];
                ans=max(ans,(w*heights[i]));
            }
            else if(right[i]!=-1){
                int w=right[i];
                ans=max(ans,(w*heights[i]));
            }
        }
        return ans;
    }
};