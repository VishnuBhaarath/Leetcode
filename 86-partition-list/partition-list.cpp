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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL){
            return head;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* front=NULL;
        ListNode* temp1=NULL;
        ListNode* temp2=NULL;
        while(curr!=NULL){
          if(curr->val<x){
            if(prev==NULL){
                 prev=curr;
                 temp1=prev;
               }
               else{
                 prev->next=curr;
                 prev=curr;
               }
            }
            else{
              if(front==NULL){
                front=curr;
                temp2=front;
              }
              else{
                front->next=curr;
                front=curr;
              }
            }
           
            curr=curr->next;
        }
        if(temp1==NULL){
            return temp2;
        }
        if(temp2==NULL){
            return temp1;
        }
        

        front->next=NULL;
        prev->next=temp2;
      
        
        return temp1;
    }
};