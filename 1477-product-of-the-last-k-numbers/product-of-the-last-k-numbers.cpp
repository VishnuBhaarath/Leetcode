class ProductOfNumbers {
public:
    vector<int>v1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v1.push_back(num);
    }
    
    int getProduct(int k) {
        long long val=1;
        int n=v1.size();
        for(int i=n-1;i>=0;i--){
            val*=v1[i];
            k-=1;
            if(k==0){
                return val;
            }
        }
        return val;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */