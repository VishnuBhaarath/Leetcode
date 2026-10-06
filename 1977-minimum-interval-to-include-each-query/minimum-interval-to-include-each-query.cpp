class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
            map<int, set<pair<int, int>>> line;
        // -1 :  Entry  1 : Exit , 2 : Query & size of interval
        for(auto& i : intervals){
            int size = i[1] -i[0] + 1;
            line[i[0]].insert(make_pair(-1, size));
            line[i[1]+1].insert(make_pair(1, size));
        }
        
        for(int i =0; i < queries.size(); ++i){
            line[queries[i]].insert(make_pair(2, i));
        }
        vector<int> ans(queries.size(), -1);
        multiset<int> sizes;
        for(auto& [x, intervals] :  line){
            for(auto& i : intervals){
                if(i.first==-1)
                    sizes.insert(i.second);
                else if (i.first==1)
                    sizes.erase(sizes.lower_bound(i.second));
                else if (i.first ==2 and !sizes.empty())
                    ans[i.second] = *(sizes.begin());
                
            }
            
        }
        return ans;
    }
};