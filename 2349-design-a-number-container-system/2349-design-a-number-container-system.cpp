class NumberContainers {
public:
   map<int,int> umap; 
   NumberContainers() {
        
    }
    void change(int index, int number) {
        umap[index]=number;
    }
    
    int find(int number) {
       for(auto x:umap){
           if(x.second==number){
               return x.first;
           }
       }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */