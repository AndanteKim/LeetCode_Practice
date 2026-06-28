class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0, prev = 0;

        for (int num : arr) {
            if (abs(num - prev) >= 1) {
                num = prev + 1;
                prev = num;
            }
            
            ans = max(ans, num);
        }

        return ans;
    }
};