class Solution {
public:
    int pathSum(vector<int>& nums) {
        // Store the data in a hashmap, with the coordinates as the key and the
        // node value as the value
        unordered_map<int, int> map;
        for (int element : nums) {
            int coordinates = element / 10;
            int value = element % 10;
            map[coordinates] = value;
        }

        // Initialize sum with 0 and pass it by reference in the sum function.
        int sum = 0;
        dfs(nums[0] / 10, 0, sum, map);

        return sum;
    }

    void dfs(int rootCoordinates, int preSum, int& sum,
             unordered_map<int, int>& map) {
        // Find the level and position values from the coordinates.
        int level = rootCoordinates / 10;
        int position = rootCoordinates % 10;

        // Find out the left child and right child positions of the tree.
        int left = (level + 1) * 10 + position * 2 - 1;
        int right = (level + 1) * 10 + position * 2;
        int currSum = preSum + map[rootCoordinates];

        // If left child and right child does not exist, return.
        if (!map.count(left) and !map.count(right)) {
            sum += currSum;
            return;
        }
        // Otherwise iterate through the left and right children recursively
        // using depth first search.
        if (map.count(left)) {
            dfs(left, currSum, sum, map);
        }
        if (map.count(right)) {
            dfs(right, currSum, sum, map);
        }
    }
};