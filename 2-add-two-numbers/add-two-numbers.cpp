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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int r=0;
       
       
        ListNode* prev=NULL;
        ListNode * head=NULL;
        while(l1!=NULL || l2!=NULL){
             int q=0;
            if(l1!=NULL){
              q+=l1->val;
            }
            if(l2!=NULL){
                q+=l2->val;
            }
            q+=r;
            r=q/10;
            q=q%10;
            ListNode* temp=new ListNode();
            temp->val=q;
            if(prev!=NULL){
                prev->next=temp;
            }
            if(prev==NULL){
                head=temp;
            }
            prev=temp;
            if(l1!=NULL){
            l1=l1->next;}
            if(l2!=NULL){
            l2=l2->next;}
        }
        if(r!=0){
            ListNode* temp=new ListNode();
            temp->val=r;
            prev->next=temp;
        }
     
        return head;
    }
};