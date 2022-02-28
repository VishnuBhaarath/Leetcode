class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
     unsigned long long int x=time[0];
     unsigned long long int y=totalTrips;   
     unsigned long long int q=x*y;
     unsigned long long int  l=0;
     unsigned long long int r=q;
     unsigned long long int ans=0;
        while(l<=r){
            unsigned long long int m=(l+r)/2;
            unsigned long long int cnt=0;
            for(int j=0;j<time.size();j++){
                if(time[j]>m){
                    break;
                }
                cnt+=(m/time[j]);
                if(cnt>=totalTrips){
                    break;
                }
            }
            if(cnt>=totalTrips){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};