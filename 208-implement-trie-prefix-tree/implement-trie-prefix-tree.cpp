class Node{
public:
     Node* children[26];
     bool isleaf=false;
      Node(){
     for(int i=0;i<26;i++){
        children[i]=NULL;
     }}
};

class Trie {
public:
    Node * root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node * temp=root;
        for(int i=0;i<word.size();i++){
             if(temp->children[word[i]-'a']== NULL){
                  Node* node=new Node();
                  temp->children[word[i]-'a']=node;
                  temp=temp->children[word[i]-'a'];
             }
             else{
                 temp=temp->children[word[i]-'a'];
             }
        }
        temp->isleaf=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
             if(temp->children[word[i]-'a']== NULL){
                 return false;
             }
             else{
                 temp=temp->children[word[i]-'a'];
             }
        }
        if(temp->isleaf==true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string word) {
       Node* temp=root;
        for(int i=0;i<word.size();i++){
             if(temp->children[word[i]-'a']== NULL){
                 return false;
             }
             else{
                 temp=temp->children[word[i]-'a'];
             }
        }
       
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */