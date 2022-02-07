class Bitset {
public:
    string st;
    string flip_st;
    int n=0;
    int cnt1=0;
    Bitset(int size) {
        st=string(size,'0');
        flip_st=string(size,'1');
        n=size;
    }
    
    void fix(int idx) {
        if(st[idx]=='0'){
            cnt1+=1;
        }
        st[idx]='1';
        flip_st[idx]='0';
        
    
    }
    
    void unfix(int idx) {
        if(st[idx]=='1'){
            cnt1-=1;
        }
        st[idx]='0';
        flip_st[idx]='1';
    }
    
    void flip() {
        st.swap(flip_st);
        cnt1=n-cnt1;
    }
    
    bool all() {
        if(cnt1==n){
            return true;
        }
        return false;
    }
    
    bool one() {
        if(cnt1>0){
            return true;
        }
        return false;
    }
    
    int count() {
        return cnt1;
    }
    
    string toString() {
       
        return st;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */