class Node{
 public:
    int key;
    int val;
    Node* next;
    Node* prev;
};

class LRUCache {
public:
    unordered_map<int,Node*> umap;
    int cap=0;
    Node* head=new Node();
    Node* tail=new Node();
    
    LRUCache(int capacity) {
        head->val=-1;
        tail->val=-1;
        head->next=tail;
        head->prev=NULL;
        tail->prev=head;
        tail->next=NULL;
        cap=capacity;
    }
    
    int get(int key) {
        if(umap.find(key)==umap.end()){
            return -1;
        }
        
        int value = umap[key]->val;  // Save value before deleting
        deletenode(key);
        insertafterhead(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if(umap.find(key) == umap.end()){
            if(cap==0){
                Node* node=tail->prev;
                deletenode(node->key);  // Delete LRU node
            } 
            else{
                cap-=1;
            }
            insertafterhead(key, value);
        }
        else{
            deletenode(key);
            insertafterhead(key, value);
        }
    }
    
    void insertafterhead(int key, int value){
        Node* forward=head->next;
        
        Node* node=new Node();
        node->key=key;
        node->val=value;
        node->prev=head;
        node->next=forward;
        
        forward->prev=node;
        head->next=node;  
        umap[key]=node;
    }
    
    void deletenode(int key){
        Node* node = umap[key];
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        nextNode->prev=prevNode;
        prevNode->next=nextNode;
        
        umap.erase(key);  // Remove from map
       // delete node;       // Free memory
    }
};