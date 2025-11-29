class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);

        for (const auto& update : updates) {
            int start = update[0], end = update[1], inc = update[2];
            arr[start] += inc;

            if (end < length - 1) arr[end + 1] -= inc;
        }

        for (int i = 0; i < length - 1; ++i) arr[i + 1] += arr[i];
    
        return arr;
    }
};