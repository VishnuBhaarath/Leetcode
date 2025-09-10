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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev =head;
        ListNode* curr=head;
        int t=0;
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        if(head->val==head->next->val){
            t=1;
        }

        while(curr!=NULL){
            if(curr->next==NULL){
                break;
            }
            if(curr->val!= curr->next->val){
              
                prev=curr;
                curr=curr->next;
            }
            else{
              
                ListNode* temp=curr;
             
                curr=curr->next;
                while(curr->val==temp->val){
                    curr=curr->next;
                  
                    if(curr==NULL){
                        break;
                    }
                }
               
              
                
                prev->next=curr;
            }
         
        }
        if(t==1){
            return head->next;
        }
        return head;
    }
};