class Solution {
private:
    bool isDividedBy(int n, int count, unordered_set<int>& squareNums){
        /*
        return: true if "n" can be decomposed into "count" number of perfect square nums
        e.g. n = 12, count = 3: true
             n = 12, count = 2: false
        */
        
        if (count == 1)
            return squareNums.find(n) != squareNums.end();
        
        for (int k : squareNums){
            if (isDividedBy(n - k, count - 1, squareNums))
                return true;
        }
        
        return false;
    }
    
public:
    int numSquares(int n) {
        unordered_set<int> squareNums;
        
        for (int i = 1; i <= (int)sqrt(n); ++i)
            squareNums.insert(i * i);
        
        for (int count = 1; count <= n; ++count)
            if (isDividedBy(n, count, squareNums))
                return count;
        
        return -1;
    }
};