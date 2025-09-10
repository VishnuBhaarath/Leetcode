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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int cnt=1;
        ListNode* temp1=head;
        int tc=0;
        while(temp1!=NULL){
            temp1=temp1->next;
            tc+=1;
        }
        if(tc==n){
            return head->next;
        }
       
        for(int i=1;i<(tc-n);i++){
            temp=temp->next;
        }
        if(temp!=NULL){
            ListNode* front=temp->next;
            if(front==NULL){
                temp->next=NULL;
            }
            else{
                temp->next=front->next;
            }
        }
        return head;
    }
};