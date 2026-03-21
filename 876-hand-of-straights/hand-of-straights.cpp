class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        unordered_map<int,int> umap;
        for(int i=0;i<hand.size();i++){
            umap[hand[i]]+=1;
        }
        for(int i=0;i<hand.size();i++){
           
             if(umap[hand[i]]>0){
                umap[hand[i]]-=1;
                int j=hand[i]+1;
                
                int k=1;
                while(k<groupSize){
                    if(umap[j]>0){
                        umap[j]-=1;

                    }
                    else{
                        return false;
                    }
                    j+=1;
                    k+=1;
                }
             }
           
        }
        return true;
    }
};