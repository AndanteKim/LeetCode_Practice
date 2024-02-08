class Solution {
public:
    int numSquares(int n) {
        // List of square numbers that are less than 'n'
        vector<int> squareNumbers;
        for (int i = 1; i <= (int)sqrt(n); ++i)
            squareNumbers.push_back(i * i);
        
        unordered_set<int> queue{n};
        int level = 0;
        
        while (!queue.empty()){
            ++level;
            /*! important: use set() instead of list() to eliminate the redundancy
            which would even produce a 5-times speedup, 200ms vs 1000ms.
            */
            unordered_set<int> nextQueue;
            // construct the queue for the next level
            for (int remainder:queue){
                for (int squareNum:squareNumbers){
                    if (remainder == squareNum)
                        return level; // find the node
                    else if (remainder < squareNum)
                        break;
                    else
                        nextQueue.insert(remainder - squareNum);
                }
            }
            queue = nextQueue;
        }
        
        return level;
    }
};