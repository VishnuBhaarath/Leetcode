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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* temp1=NULL;
        temp=temp->next;
        int sum=0;
        while(temp!=NULL){
            if(temp->val!=0){
                sum+=temp->val;
            }
            else{
                ListNode* node=new ListNode();
                node->val=sum;
                sum=0;
                if(prev!=NULL){
                prev->next=node;}
                else{
                    temp1=node;
                }
                prev=node;
            }
            temp=temp->next;
        }
        return temp1;
    }
};