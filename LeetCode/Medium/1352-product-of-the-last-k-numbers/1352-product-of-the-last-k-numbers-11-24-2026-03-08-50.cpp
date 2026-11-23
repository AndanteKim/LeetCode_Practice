class ProductOfNumbers {
private:
    vector<int> prefix{1};
    int size = 0;

public:
    ProductOfNumbers() {}
    
    void add(int num) {
        if (num == 0) {
            prefix = {1}, this -> size = 0;
        }
        else {
            prefix.push_back(prefix.back() * num);
            ++(this -> size);
        }
    }
    
    int getProduct(int k) {
        return k > size? 0 : prefix[this -> size] / prefix[this -> size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */