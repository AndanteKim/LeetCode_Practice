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
    stack<pair<vector<NestedInteger>, int>> stack;
    NestedIterator(vector<NestedInteger> &nestedList) {
        stack.push(make_pair(nestedList, 0));
    }
    
    void makeStackTopAnInteger(){
        while (!stack.empty()){
            vector<NestedInteger> currList = stack.top().first;
            int currIndex = stack.top().second;
            // If the top is used up, pop it and its index
            if (currList.size() == currIndex){
                stack.pop();
                continue;
            }
            
            // Otherwise, if it's already an int, we don't need to do anything
            if (currList[currIndex].isInteger())
                break;
                
            // Otherwise, it muse be a list. We need to increment the index on the previous list
            // and add the new list
            vector<NestedInteger> newList = currList[currIndex].getList();
            // increment old
            ++stack.top().second;
            stack.push(make_pair(newList, 0));
        }
    }
    
    int next() {
        makeStackTopAnInteger();
        vector<NestedInteger> currList = stack.top().first;
        int currIndex = stack.top().second;
        ++stack.top().second;
        return currList[currIndex].getInteger();
    }
    
    bool hasNext() {
        makeStackTopAnInteger();
        return stack.size() > 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */