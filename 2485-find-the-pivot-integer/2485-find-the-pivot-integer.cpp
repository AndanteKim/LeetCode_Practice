class Solution {
public:
    int pivotInteger(int n) {
        unordered_map<int, long> sigma;
        int sum = 0;
        
        for (int i = 0; i <= n; ++i){
            sum += i;
            sigma[i] = sum;
        }
        
        sum = 0;
        for (int pivot = 1; pivot <= n; ++pivot){
            sum += pivot;
            if (sum == (sigma[n] - sigma[pivot - 1]))
                return pivot;
        }
        
        return -1;
    }
};