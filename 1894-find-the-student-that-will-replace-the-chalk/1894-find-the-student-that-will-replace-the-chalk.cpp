class Solution {
private:
    int n;
    int binarySearch(vector<long>& prefixSum, int remain){
        int left = 0, right = n;
        
        while (left < right){
            int mid = (left + right) >> 1;
            
            if (prefixSum[mid] <= remain)
                left = mid + 1;
            else
                right = mid;
        }
        
        return right;
    }
    
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        this -> n = chalk.size();
        vector<long> prefixSum(n);
        prefixSum[0] = chalk[0];
        
        for (int i = 1; i < n; ++i)
            prefixSum[i] = prefixSum[i - 1] + chalk[i];
        
        k %= prefixSum.back();
        return binarySearch(prefixSum, k);
    }
};