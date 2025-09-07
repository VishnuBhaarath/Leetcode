/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> umap;
        umap[head]+=1;
        while(head!=NULL){
            head=head->next;
            if(umap[head]!=0){
                return true;
            }
            umap[head]+=1;
        }
        return false;
    }
};