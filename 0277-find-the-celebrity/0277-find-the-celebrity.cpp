/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
private:
    int n;
    
    bool isCelebrity(int i){
        for (int j = 0; j < n; ++j){
            if (i == j) continue;
            
            if (knows(i, j) || !knows(j, i))
                return false;
        }
        
        return true;
    }
    
public:
    int findCelebrity(int n) {
        this -> n = n;
        
        for (int i = 0; i < n; ++i){
            if (isCelebrity(i))
                return i;
        }
        
        return -1;
    }
};