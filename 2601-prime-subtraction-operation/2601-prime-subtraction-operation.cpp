class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> primes(1001, true);
        int i = 2;
        
        while (i * i <= 1000){
            for (int p = i * i; p <= 1000; p += i)
                primes[p] = false;
            ++i;
        }
        
        vector<int> sieves;
        for (int i = 2; i <= 1000; ++i){
            if (primes[i]) sieves.push_back(i);
        
        }
        int n = nums.size(), p = sieves.size();
        
        for (int i = n - 2; i >= 0; --i){
            if (nums[i] >= nums[i + 1]){
                int left = upper_bound(sieves.begin(), sieves.end(), nums[i] - nums[i + 1]) - sieves.begin();
                if (left == p) return false;
                
                nums[i] -= sieves[left];
                // 0 means prime == target or prime > target
                if (nums[i] <= 0) return false;
            }
        }
        
        return true;
    }
};