class ProductOfNumbers {
public:
    vector<int>v1;
    int idx=-1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num!=0){
        if(v1.size()==0){
        v1.push_back(num);}
        else{
            if(v1[v1.size()-1]==0){
                v1.push_back(num);
            }
            else{
            v1.push_back(v1[v1.size()-1]*num);
            }
        }
        }
        else{
            v1.push_back(num);
            idx=v1.size()-1;
        }
    }
    
    int getProduct(int k) {
        
        if(idx==-1){
            int n=v1.size();
            int m=n-k;
            if(m-1>=0){
            long long val=v1[n-1]/v1[m-1];
            return val;
            }
            else{
                return v1[n-1];
            }
        }
        else{
            int n=v1.size();
            if(idx>=(n-k)){
                return 0;
            }
            else{
                if(idx==(n-k-1)){
                    return v1[n-1];
                }
                else{
                    int m=n-k;
            long long val=v1[n-1]/v1[m-1];
            return val;
                }
            }
        }
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */