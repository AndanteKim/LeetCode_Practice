class Solution {
public:
    int minSwaps(vector<int>& data) {
        int k = count(data.begin(), data.end(), 1), n = data.size();
        int left = 0, ans = std::numeric_limits<int>::max(), swapCount = 0;
        
        for (int right = 0; right < n; ++right){
            if (data[right] == 0) ++swapCount;
            
            while (right - left >= k){
                if (data[left++] == 0) --swapCount;
            }

            if (right + 1 >= k) ans = min(ans, swapCount);
        }

        return ans;
    }
};