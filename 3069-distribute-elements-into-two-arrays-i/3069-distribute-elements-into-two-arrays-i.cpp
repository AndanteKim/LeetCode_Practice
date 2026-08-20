class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        int idx = 0, revIdx = n - 1;
        arr[0] = nums[0], arr.back() = nums[1]; 

        for (int i = 2; i < n; ++i) {
            if (arr[idx] > arr[revIdx]) {
                arr[++idx] = nums[i];
            }
            else {
                arr[--revIdx] = nums[i];
            }
        }

        int l = revIdx, r = n - 1;
        while (l < r) {
            swap(arr[l++], arr[r--]);
        }

        return arr;
    }
};