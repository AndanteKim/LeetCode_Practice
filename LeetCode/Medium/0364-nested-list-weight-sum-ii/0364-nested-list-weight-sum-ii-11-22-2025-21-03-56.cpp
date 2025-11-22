/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    int findMaxDepth(const NestedInteger& nestedInt) {
        if (nestedInt.isInteger()) return 1;

        int maxDepth = 0;

        for (const auto& nested : nestedInt.getList()) {
            maxDepth = max(maxDepth, 1 + findMaxDepth(nested));
        }

        return maxDepth;
    }

    int dfs(const NestedInteger& nestedInt, int depth, int maxDepth) {
        if (nestedInt.isInteger()) {
            int weight = (maxDepth - depth) + 1;
            return weight * nestedInt.getInteger();
        }

        int total = 0;
        for (const auto& nested : nestedInt.getList())
            total += dfs(nested, depth + 1, maxDepth);

        return total;
    }

public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = 0;

        for (const auto& nestedInt : nestedList)
            maxDepth = max(maxDepth, findMaxDepth(nestedInt));
        
        int ans = 0;

        for (const auto& nestedInt : nestedList)
            ans += dfs(nestedInt, 1, maxDepth);
        
        return ans;
    }
};