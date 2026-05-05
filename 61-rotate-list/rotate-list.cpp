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
        ListNode* temp=head;
        
        int n=0;
        while(temp!=NULL){
            n+=1;
            temp=temp->next;
        }
        if(n==0){
            return NULL;
        }
        int q=k%n;
        if(q==0){
            return head;
        }
        int r=n-q;
        
        ListNode* temp1=head;
        int i=0;
        while(i<(r-1)){
            temp1=temp1->next;
            i+=1;
        }
        ListNode * temp2=temp1->next;
        temp1->next=NULL;

        ListNode * head1=temp2;
        while(temp2!=NULL){
             if(temp2->next==NULL){
                temp2->next=head;
                return head1;
             }
             temp2=temp2->next;
        }
       
        return head;
    }
};