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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=NULL;
        ListNode* prev=NULL;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                if(prev!=NULL){
                prev->next=list1;}
                else{
                    head=list1;
                }
                prev=list1;
                list1=list1->next;
            }
            else{
                if(prev!=NULL){
                prev->next=list2;}
                else{
                    head=list2;
                }
                prev=list2;
                list2=list2->next;
            }

        }
       if(list1!=NULL){
        if(prev!=NULL){
        prev->next=list1;}
        else{
            head=list1;
        }
       }
       if(list2!=NULL){
        if(prev!=NULL){
         prev->next=list2;}
         else{
            head=list2;
         }
       }
        return head;
    }
};