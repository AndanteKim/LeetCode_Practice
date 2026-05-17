class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (0 <= start && start < arr.size() && arr[start] >= 0) {
            if (arr[start] == 0) return true;

            arr[start] = -arr[start];

            return canReach(arr, start - arr[start]) || canReach(arr, start + arr[start]);
        }

        return false;
    }
};