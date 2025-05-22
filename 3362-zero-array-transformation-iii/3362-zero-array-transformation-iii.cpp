class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size(), n = nums.size();
        sort(queries.begin(), queries.end());
        priority_queue<int> heap;
        vector<int> deltaArray(n + 1);
        int j = 0, operations = 0;

        for (int i = 0; i < n; ++i){
            operations += deltaArray[i];

            while (j < m && queries[j][0] == i){
                heap.push(queries[j][1]);
                ++j;
            }
            
            while (operations < nums[i] && !heap.empty() && heap.top() >= i){
                ++operations;
                --deltaArray[heap.top() + 1];
                heap.pop();
            }

            if (operations < nums[i]) return -1;
        }

        return heap.size();
    }
};