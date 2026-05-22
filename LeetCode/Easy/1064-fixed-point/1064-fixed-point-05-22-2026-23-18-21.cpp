class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int n = arr.size(), ans = -1;
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (arr[mid] == mid) {
                right = mid - 1;
                ans = mid;
            }
            else if (arr[mid] < mid) left = mid + 1;
            else right = mid - 1;
        }

        return ans;
    }
};