/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        int n=0;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            v.push_back(slow->val);
            n+=1;
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            
        }
        int ans=0;
        int i=0;
        while(slow!=NULL){
            int val=slow->val+v[n-1-i];
            i+=1;
            ans=max(ans,val);
            slow=slow->next;
        }
        return ans;
    }
};