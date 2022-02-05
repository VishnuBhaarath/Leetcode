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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        ListNode* temp=head;
        ListNode* val=NULL;
        ListNode* ans=NULL;
        int n=0;
        while(temp!=NULL){
            temp=temp->next;
            n+=1;
            
        }
        ListNode*prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;
        ListNode* temp1=head;
        while(n>=k){
            int cnt=0;
           
            while(cnt<k){
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
                cnt+=1;
                n-=1;
            }
            if(val!=NULL){
                val->next=prev;
            }
            else{
                ans=prev;
            }
            val=temp1;
          
            temp1=curr;
          
           
            prev=NULL;
            forward=NULL;
           
      
            
            
            
          
        }
      
    val->next=temp1;
     
       
        return ans;
    }
};