class Solution {
private:
    // Direction map for zero's possible moves in a flattened 1D array (2x3 board)
    const vector<vector<int>> directions{
        {1, 3},\
        {0, 2, 4},\
        {1, 5},\
        {0, 4},\
        {1, 3, 5},\
        {2, 4}
    };
    
    void dfs(string state, int zeroPos, int moves, unordered_map<string, int>& visited){
        // Skip if this state has been visited with fewer or equal moves
        if (visited.count(state) && visited[state] <= moves)
            return;
        
        visited[state] = moves;
        
        // Try moving zero to each possible adjacent position
        for (int nextPos : directions[zeroPos]){
            swap(state[zeroPos], state[nextPos]);   // Swap to generate new state
            dfs(state, nextPos, moves + 1, visited);  // Recursive DFS with updated state and move count
            swap(state[zeroPos], state[nextPos]);   // Swap back to restore original state
        }
    }
    
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Map to store the minimum moves for each visited state
        unordered_map<string, int> visited;
        
        // Convert the 2D board into a string representation to use as state
        string startState = "";
        for (const auto& row : board){
            for (const int num : row)
                startState.push_back(num + '0');
        }
        
        // Start DFS traversal from initial board state
        dfs(startState, startState.find('0'), 0, visited);
        
        // Return the minimum moves required to reach the target state, or -1 if unreachable
        return visited.find("123450") == visited.end()? -1 : visited["123450"];
    }
};