class Node{
    public:
    Node* prev;
    Node* next;
    int val;
    int key;


};

class LRUCache {
public:
    map<int,Node*> umap;
     Node* head=new Node();
      Node* tail=new Node();
      int cnt=0;
      int sz=0;
    LRUCache(int capacity) {
       sz=capacity;
        head->val=-1;
      //  head->next=NULL;
        head->prev=NULL;

       
        tail->val=-1;
        tail->next=NULL;
        tail->prev=head;
        head->next=tail;

        
    }
    
    int get(int key) {
        cout<<key;
        cout<<"\n";
        if(umap[key]==NULL){
            return -1;
        }
         deleteNode(key);
            inserthead(key,umap[key]->val);
        return umap[key]->val;
    }
    
    void put(int key, int value) {
        Node* temp=umap[key];
        if(temp==NULL){
            if(cnt<sz){
            inserthead(key,value);
            cnt+=1;
            }
            else{
delete1();
inserthead(key,value);
            }
        }
        else{
            deleteNode(key);
            inserthead(key,value);
           // cnt+=1;
        }
    }
    void inserthead(int key,int val){
           Node* temp=new Node();
           temp->val=val;
           temp->key=key;

           Node* temp1=head->next;

           head->next=temp;
           temp->prev=head;

           temp->next=temp1;
           temp1->prev=temp;
           umap[key]=temp;
    }

    void deleteNode(int key){
        Node* temp=umap[key];
        Node* temp1=temp->next;
        Node* temp2=temp->prev;

        temp1->prev=temp2;
        temp2->next=temp1;

        temp->prev=NULL;
        temp->next=NULL;
    }
    void delete1(){
        Node* temp=tail->prev;
        Node* temp1=temp->prev;
        temp1->next=tail;
        tail->prev=temp1;
        umap[temp->key]=NULL;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */