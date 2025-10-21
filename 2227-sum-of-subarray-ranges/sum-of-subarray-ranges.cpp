class Solution {
public:
    void pge(vector<int> & left1,vector<int> & arr){
        int n=arr.size();
        stack<int> s;
      
        s.push(0);
        for(int i=1;i<arr.size();i++){
            if(s.empty()){
                s.push(i);
            }
            else if(arr[i]<arr[s.top()]){
                  left1[i]=s.top();
                  s.push(i);
            }
            else{
                while(arr[i]>=arr[s.top()]){
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                if(!s.empty()){
                    left1[i]=s.top();
                }
                s.push(i);
            }
        }
    }

    void nge(vector<int> & right1,vector<int> & arr){
         int n=arr.size();
        stack<int> s1;
        s1.push(n-1);

        for(int i=n-2;i>=0;i--){
            if(s1.empty()){
                s1.push(i);
            }
            else if(arr[i]<=arr[s1.top()]){
                
                right1[i]=s1.top();
                s1.push(i);
            }
            else{
                while(arr[i]>arr[s1.top()]){
                    s1.pop();
                    if(s1.empty()){
                        break;
                    }
                }
                if(!s1.empty()){
                    right1[i]=s1.top();
                }
                s1.push(i);
            }
        }

    }

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
        for(int i=0;i<left.size();i++){
            cout<<left[i];
            cout<<" ";
        }
        cout<<"\n";
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,-1);
        vector<int> right(n,-1);

        pse(left,nums);
        nse(right,nums);

        vector<int> left1(n,-1);
        vector<int> right1(n,-1);

        pge(left1,nums);
        nge(right1,nums);

      


         long long int ans=0;
 
         vector<int> arr=nums;

        for(int i=0;i<arr.size();i++){
            
            if(left[i]==-1 && right[i]==-1){
                ans+=(long long)(arr[i])*(long long)(i+1)*(long long)(n-i);
            
            }
            else {
                int l=left[i];
                int r=right[i];
                if(r!=-1 && l!=-1){
                    ans+=(long long)(arr[i])*(long long)(i-l)*(long long)(r-i);
                    
                }
                else if(l==-1){
                    ans+=(long long)(arr[i])*(long long)(i+1)*(long long)(r-i);
                  
                }
                else if(r==-1){
                    ans+=(long long)(arr[i])*(long long)(i-l)*(long long)(n-i);
                   
                }
            }
           
        }
long long int ans1=0;

         for(int i=0;i<arr.size();i++){
            if(left1[i]==-1 && right1[i]==-1){
                ans1+=(long long)(arr[i])*(long long)(i+1)*(long long)(n-i);
            
            }
            else {
                int l=left1[i];
                int r=right1[i];
                if(r!=-1 && l!=-1){
                    ans1+=(long long)(arr[i])*(long long)(i-l)*(long long)(r-i);
                    
                }
                else if(l==-1){
                    ans1+=(long long)(arr[i])*(long long)(i+1)*(long long)(r-i);
                   
                }
                else if(r==-1){
                    ans1+=(long long)(arr[i])*(long long)(i-l)*(long long)(n-i);
                   
                }
            }
           
        }

     return ans1-ans;
        
        
    }
};