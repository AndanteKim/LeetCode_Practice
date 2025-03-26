class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flatten;

        for (const auto& row : grid){
            for (const int elem : row){
                flatten.push_back(elem);
            }
        }

        sort(flatten.begin(), flatten.end());
        int ans = 0, median = ((int)flatten.size()) % 2 == 0? flatten[((int)flatten.size() >> 1) - 1] : flatten[((int)flatten.size()) >> 1];
        for (int elem : flatten){
            // If the x is not divisible, it means we cannot make a Uni-value grid
            if (abs(elem - median) % x != 0) return -1;

            ans += abs(elem - median) / x;
        }
        return ans;
    }
};