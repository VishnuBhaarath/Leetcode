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
    ListNode* reverseList(ListNode* head,int k){
        ListNode* curr=head;
        ListNode* prev =NULL;
       
        for(int i=0;i<k;i++){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
      
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        ListNode* curr=head;
        ListNode* start=head;
        ListNode * head1=NULL;
         ListNode* temp2=NULL;
          ListNode* prev=NULL;
          ListNode* temp1=NULL;
        int cnt=1;
        while(curr!=NULL){
          if(cnt==k){
            
             
           ListNode * temp=curr->next;
          temp1=start;
          
           prev= reverseList(start,k);
          
           if(head1==NULL){
            head1=prev;
           }
           else{
             if(temp2!=NULL){
                
                temp2->next=prev;
             }
           }
           temp2=temp1;
         
             
             
             start=temp;
             curr=temp;
             if(temp!=NULL){
                cnt=1;
             }
          }  
          if(curr!=NULL){
          curr=curr->next;}
          if(curr!=NULL){
          cnt+=1;}
        }
       
        if(cnt<k && cnt>0){
            
            temp1->next=start;
            
        }
        return head1;
    }
};