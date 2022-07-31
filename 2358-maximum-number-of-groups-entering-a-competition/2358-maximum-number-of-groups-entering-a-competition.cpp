class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        vector<long long int> presum;
        sort(grades.begin(),grades.end());
        presum.push_back(grades[0]);
    
        for(int i=1;i<grades.size();i++){
            presum.push_back(presum[presum.size()-1]+grades[i]);
        }
        int i=0;
        int cnt=1;
        int j=2;
        int prev=grades[i];
        while(j<presum.size()){
            int curr=presum[j]-presum[i];
            cnt+=1;
            int k=j-i;
            cout<<j;
            cout<<" ";
            cout<<i;
            cout<<" ";
            cout<<cnt;
            cout<<"\n";
            if((j+k+1)>=grades.size()){
                return cnt;
            }
            int temp=j;
            i=j;
            j=temp+k+1;
            
        }
        cout<<"\n";
        return cnt;
    }
};