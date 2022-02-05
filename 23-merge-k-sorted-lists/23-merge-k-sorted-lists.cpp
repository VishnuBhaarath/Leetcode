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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>> > pq;
        ListNode* temp=NULL;
        for(int i=0;i<lists.size();i++){
            ListNode* root=lists[i];
            while(root!=NULL){
                pq.push(make_pair(root->val,root));
              
                root=root->next;
            }
           
        }
        ListNode* root=NULL;
        
        while(!pq.empty()){
            pair<int,ListNode*>p=pq.top();
            pq.pop();
          
            if(root==NULL){
                root=p.second;
                temp=root;
            }
            else{
                root->next=p.second;
                root=root->next;
            }
           
        }
        return temp;
    }
};