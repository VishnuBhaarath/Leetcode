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
    ListNode* reverseList(ListNode* head) {
        ListNode * temp=head;
        if(head==NULL){
            return head;
        }
        if(head->next == NULL){
            return temp;
        }
        ListNode * next1=temp->next;
        while(next1!=NULL){
            ListNode * temp1=next1->next;
            next1->next=temp;
            cout<<temp->val;
            cout<<" ";
            cout<<next1->val;
            cout<<" ";
            if(temp1!=NULL){
                cout<<temp1->val;
                cout<<" ";
            }
            cout<<"\n";
            
            temp=next1;
            next1=temp1;

            if(next1==NULL){
                break;
            }
            
        }
         if(head != NULL) {
        head->next = NULL;
    }
        cout<<temp->val;
        return temp;
    }
};