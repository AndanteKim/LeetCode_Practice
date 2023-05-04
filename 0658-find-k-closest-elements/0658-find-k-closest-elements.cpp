class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size() == k) return arr;
        
        int left = lower_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        int right = left + 1;
        
        while (right - left - 1 < k){
            if (left == -1){
                ++right;
                continue;
            }
            if (right == arr.size() || abs(arr[left] - x) <= abs(arr[right] - x)) --left;
            else ++right;
        }
        vector<int> ans;
        ans.assign(arr.begin() + left + 1, arr.begin() + right);
        return ans;
    }
};