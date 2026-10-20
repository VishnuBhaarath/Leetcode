class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        stack<int> s;
        for(int i=0;i<nums2.size();i++){
            if(s.empty()){
                s.push(nums2[i]);
            }
            else if(nums2[i]<=s.top()){
                s.push(nums2[i]);
            }
            else{
                 while(nums2[i]>s.top()){
                    umap[s.top()]=i;
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                 }
                 s.push(nums2[i]);
            }
        }
        for(int i=0;i<nums1.size();i++){
            if(umap[nums1[i]]==0){
                nums1[i]=-1;
            }
            else{
                nums1[i]=nums2[umap[nums1[i]]];
            }
        }
        return nums1;
    }
};