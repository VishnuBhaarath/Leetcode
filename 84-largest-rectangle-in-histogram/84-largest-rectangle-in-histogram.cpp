class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans=0;
        for(int i=0;i<heights.size();i++){
            if(st.empty()){
               st.push(i);
            }
            else{
                if(heights[i]>=heights[st.top()]){
                    st.push(i);
                }
                else{
                    while(heights[i]<heights[st.top()]){
                        int tp=st.top();
                        st.pop();
                        int w=0;
                        if(st.empty()){
                            w=i;
                        }
                        else{
                            int tp1=st.top();
                            w=i-tp1-1;
                        }
                        cout<<heights[tp];
                        int area=heights[tp]*w;
                        cout<<" ";
                        cout<<area;
                        cout<<"\n";
                        ans=max(ans,area);
                        if(st.empty()){
                            break;
                        }
                        
                    }
                    st.push(i);
                }
            }
        }
        int n=heights.size();
        while(!st.empty()){
            int tp=st.top();
            st.pop();
            int w=n-tp;
            if(!st.empty()){
                w+=(tp-st.top()-1);
            }
            else{
                w+=tp;
            }
            int area=heights[tp]*w;
         
            ans=max(ans,area);
        }
        return ans;
    }
};