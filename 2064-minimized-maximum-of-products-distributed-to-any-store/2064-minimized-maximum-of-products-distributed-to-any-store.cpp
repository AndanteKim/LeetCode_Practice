class Solution {
private:
    int m, n;
    bool canDistribute(int x, vector<int>& quantities){
        // Pointer to the first not fully distributed product type
        // Remaining quantity of the jth product type
        int j = 0, remaining = quantities[j];
        
        // Loop through each store
        for (int i = 0; i < n; ++i){
            // Check if the remaining quantity of the jth product type
            // can be fully distributed to the ith store
            if (remaining <= x){
                // If yes, move the pointer to the next product type
                ++j;
                
                // Check if all products have been distributed
                if (j == m) return true;
                else
                    remaining = quantities[j];
            }
            else
                // Distribute the maximum possible quantity (x) to the ith store
                remaining -= x;
        }
        
        return false;
    }
    
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        // Initialize the boundaries of the binary search
        int left = 0, right = *max_element(quantities.begin(), quantities.end());
        this -> m = quantities.size();
        this -> n = n;
        
        // Perform binary search until the boundaries converge
        while (left < right){
            int mid = left + ((right - left) >> 1);
            
            if (canDistribute(mid, quantities))
                // Try for a smaller maximum
                right = mid;
            else
                // Increase the minimum possible maximum
                left = mid + 1;
        }
        
        return left;
    }
};