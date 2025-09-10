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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* fast=head;
        ListNode* slow=head;
        if(k==0){
            return head;
        }
        ListNode* curr1=head;
        int cnt=0;
        while(curr1!=NULL){
            curr1=curr1->next;
            cnt+=1;
        }
        if(cnt==0){
            return head;
        }
        if(k>=cnt){
        k=(k%cnt);}
        
        for(int i=0;i<k;i++){
            fast=fast->next;
            if(fast==NULL){
                fast=head;
            }
        }
     
        if(fast->next==NULL){
            fast->next=curr;
            head=slow->next;
            slow->next=NULL;
            return head;
        }
        while(1){
            slow=slow->next;
            fast=fast->next;
            
            if(fast->next==NULL){
                break;
            }

        }
       
        fast->next=curr;
        head=slow->next;
        slow->next=NULL;
      
        return head;
    }
};