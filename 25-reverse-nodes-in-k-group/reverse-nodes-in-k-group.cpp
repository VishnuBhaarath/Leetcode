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
        while(head!=NULL){
            cout<<head->val;
            head=head->next;
            cout<<" ";
        }
        cout<<"\n";
        for(int i=0;i<k;i++){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        ListNode * prev1=prev;
        while(prev1!=NULL){
            cout<<prev1->val;
            cout<<" ";
            prev1=prev1->next;
        }
       
        cout<<"\n";
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
            if(start!=NULL){
                cout<<start->val;
                cout<<"\n";
             }
             
           ListNode * temp=curr->next;
          temp1=start;
          
           prev= reverseList(start,k);
           if(prev!=NULL){
            cout<<"prev";
            cout<<prev->val;
            cout<<"\n";
           }
           if(head1==NULL){
            head1=prev;
           }
           else{
             if(temp2!=NULL){
                cout<<"temp2";
                cout<<temp2->val;
                cout<<"\n";
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
        cout<<"cnt";
        cout<<cnt;
        cout<<"\n";
        if(cnt<k && cnt>0){
            cout<<"out";
            cout<<"\n";
            cout<<temp1->val;
            cout<<" ";
            cout<<start->val;
            cout<<" ";
            temp1->next=start;
            
        }
        return head1;
    }
};