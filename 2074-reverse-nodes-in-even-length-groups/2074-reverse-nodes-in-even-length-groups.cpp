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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        ListNode* temp2=NULL;
        while(temp!=NULL){
            temp=temp->next;
            n+=1;
        }
        temp=head;
        int j=0;
        int cnt=1;
        int i=0;
        while(head!=NULL){
            ListNode* temp1=head;
           
            head=head->next;
            j+=1;
            i+=1;
            if(head==NULL){
                break;
            }
            if(j==cnt){
               
                j=0;
                cnt+=1;
                
                if((n-i)>=cnt){
                    if(cnt%2==0){
                        ListNode* curr=head;
                        ListNode* prev=NULL;
                        ListNode* forward=NULL;
                        int t=0;
                        temp2=curr;
                        while(t<cnt){
                            forward=curr->next;
                            curr->next=prev;
                            prev=curr;
                            
                            curr=forward;
                            
                            t+=1;
                            
                            i+=1;
                        }
                      
                         temp1->next=prev;
                       cout<<prev->val;
                        cout<<" ";
                        if(forward!=NULL){
                        cout<<forward->val;}
                        head->next=forward;
                    head=forward;
                        cnt+=1;
                        if(n-i<cnt){
                            cout<<n-i;
                            cout<<" ";
                            cout<<cnt;
                            cout<<" ";
                            break;
                        }
                        
                    }
                   
                }
                else{
                  
                    
                    if(((n-i)%2)==0){
                        ListNode* curr=head;
                        ListNode* prev=NULL;
                        ListNode* forward=NULL;
                        while(curr!=NULL){
                            forward=curr->next;
                            curr->next=prev;
                            prev=curr;
                            curr=forward;
                            i+=1;
                        }
                        temp1->next=prev;
                         if(forward!=NULL){
                        cout<<forward->val;}
                        head->next=forward;
                        head=forward;
                        break;
                    }
                }
             
            }
           
           
        }
       
        
        if(head!=NULL){
            if((n-i)%2==0){
             ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
              
       
                temp2->next=prev;
            }
            
       }
        return temp;
    }
};