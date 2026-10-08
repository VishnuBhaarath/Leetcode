class Solution {

public:
    int eraseOverlapIntervals(vector<vector<int>>& I) {
        if(I.empty())return 0;

        int mn=INT_MAX,mx=INT_MIN;

        for(vector<int>&i:I){
            mn=min(mn,i[1]);
            mx=max(mx,i[1]);
        }

        int offset=-mn;
        int range=mx-mn+1;

        vector<int>start(range,INT_MIN);

        for(vector<int>&i:I){
            int e=i[1]+offset;
            start[e]=max(start[e],i[0]);
        }

        int last=INT_MIN,c=0;

        for(int e=0;e<range;e++){
            if(start[e]!=INT_MIN){
                int realEnd=e-offset;

                if(start[e]>=last){
                    c++;
                    last=realEnd;
                }
            }
        }

        return I.size()-c;
    }
};
   