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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        if(left==1){
           ListNode* prev=NULL;
           ListNode* curr=head;
            for(int i=0;i<=(right-left);i++){
                ListNode* front=curr->next;
                curr->next=prev;
                prev=curr;
                curr=front;
            }
            head->next=curr;
            return prev;

        }
        else{
            ListNode* prev=head;
            int cnt=1;
            for(int i=1;i<(left-1);i++){
                prev=prev->next;
            }
            ListNode* start=prev;
            ListNode* end=start->next;
            ListNode* curr=prev->next;
            prev=NULL;
            for(int i=0;i<=(right-left);i++){
                ListNode* front=curr->next;
                curr->next=prev;
                prev=curr;
                curr=front;
            }
           
            if(curr!=NULL){
                cout<<curr->val;
            }
            cout<<" ";
            if(prev!=NULL){
                cout<<prev->val;
            }
            start->next=prev;
            end->next=curr;
        }
        return head;
    }
};