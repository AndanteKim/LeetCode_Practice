class Solution {
private:
    // Direction map for zero's possible moes in a 1D representation of the 2x3 board
    const vector<vector<int>> directions{
        {1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}\
    };
    
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450", startState = "";
        
        // Convert the 2D board into a string representation
        for (const vector<int>& row : board){
            for (const int num : row)
                startState.push_back(num + '0');
        }
        
        queue<string> q;
        q.push(startState);
        int moves = 0;
        // To store visited states
        unordered_set<string> visited;
        visited.insert(startState);
        
        // BFS to find the minimum number of moves
        while (!q.empty()){
            int size = q.size();
            
            for (int i = 0; i < size; ++i){
                string currState = q.front(); q.pop();
                
                // Check if we reached the target solved state
                if (currState == target) return moves;
                
                int zeroPos = currState.find('0');
                for (const int nextPos : directions[zeroPos]){
                    swap(currState[zeroPos], currState[nextPos]);
                    
                    // Skip if this state has been visited
                    if (visited.count(currState)){
                        swap(currState[zeroPos], currState[nextPos]);
                        continue;
                    }
                    
                    // Mark the new state as visited and add it to the queue
                    visited.insert(currState);
                    q.push(currState);
                    swap(currState[zeroPos], currState[nextPos]);
                }
            }
            ++moves;
        }
        
        return -1;
    }
};