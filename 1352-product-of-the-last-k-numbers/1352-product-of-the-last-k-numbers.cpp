class ProductOfNumbers {
private:
    // Stores cumulative product of the stream
    // Initialize the product list with 1 to handle multiplication logic
    vector<int> prefixProduct{1};
    int size = 0;

public:
    ProductOfNumbers() {}
    
    void add(int num) {
        if (num == 0){
            // If num is 0, reset the cumulative products since multiplication
            // with 0 invalidates previous products
            prefixProduct = {1};
            size = 0;
        }
        else{
            // Append the cumulative product of the current number with the last product
            prefixProduct.push_back(prefixProduct.back() * num);
            ++size;
        }
    }
    
    int getProduct(int k) {
        // Check if the requested product length exceeds the size of the valid product list
        // otherwise, compute the product of the last k elements using division.
        return (k > size)? 0 : prefixProduct[size] / prefixProduct[size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */