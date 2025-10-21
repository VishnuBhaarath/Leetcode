class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<int> s;
        vector<int> left(n,0);
        int ans=0;
        for(int i=0;i<height.size();i++){
          
            if(s.empty()){
                s.push(height[i]);
            }
            else if(height[i]<s.top()){
              
                left[i]=s.top()-height[i];
            }
            else{
                while(height[i]>=s.top()){
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                if(s.empty()){
                    s.push(height[i]);
                }
                else{
                    left[i]=s.top();
                }
            }
           
        }

        for(int i=0;i<left.size();i++){
            cout<<left[i];
            cout<<" ";
        }
        vector<int> right(n,0);
        stack<int> s1;
        for(int i=n-1;i>=0;i--){
            if(s1.empty()){
                s1.push(height[i]);
            }
            else if(height[i]<s1.top()){
                right[i]=s1.top()-height[i];
            }
            else{
                while(height[i]>=s1.top()){
                    s1.pop();
                    if(s1.empty()){
                        break;
                    }
                }
                 if(s1.empty()){
                    s1.push(height[i]);
                }
                else{
                    right[i]=s1.top();
                }
            }

        }
        for(int i=0;i<left.size();i++){
            ans+=min(left[i],right[i]);
        }
        return ans;
    }
};