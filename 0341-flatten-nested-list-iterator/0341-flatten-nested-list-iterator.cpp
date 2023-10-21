/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<NestedInteger> stack;
    NestedIterator(vector<NestedInteger> &nestedList) {
        stack = nestedList;
        reverse(stack.begin(), stack.end());
    }
    
    int next() {
        makeStackTopAnInteger();
        int ans = stack.back().getInteger();
        stack.pop_back();
        return ans;
    }
    
    bool hasNext() {
        makeStackTopAnInteger();
        return stack.size() > 0;
    }
    
    void makeStackTopAnInteger(){
        // While the stack contains a nested list at the top...
        while (!stack.empty() && !stack.back().isInteger()){
            // unpack the list at the top by putting its items
            // onto the stack in reverse order
            vector<NestedInteger> unpack = stack.back().getList();
            stack.pop_back();
            reverse(unpack.begin(), unpack.end());
            stack.insert(stack.end(), unpack.begin(), unpack.end());
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */