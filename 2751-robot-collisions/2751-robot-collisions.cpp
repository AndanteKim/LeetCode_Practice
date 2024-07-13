class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        
        sort(indices.begin(), indices.end(), [&positions](int lhs, int rhs){return positions[lhs] < positions[rhs];});
        stack<int> stk;
        
        
        for (int currIdx : indices){
            // Add right-moving robots to the stack
            if (directions[currIdx] == 'R')
                stk.push(currIdx);
            else{
                while (!stk.empty() && healths[currIdx] > 0){
                    // Pop the top robot from the stack for collision check
                    int topIdx = stk.top(); stk.pop();
                    
                    // Top robot survives, current robot is destroyed
                    if (healths[topIdx] > healths[currIdx]){
                        --healths[topIdx];
                        healths[currIdx] = 0;
                        stk.push(topIdx);
                    }
                    else if (healths[topIdx] < healths[currIdx]){
                        // Current robot survives, top robot is destroyed
                        healths[topIdx] = 0;
                        --healths[currIdx];
                    }
                    else{
                        // Both robots are destroyed
                        healths[topIdx] = 0;
                        healths[currIdx] = 0;
                    }
                }
            }
        }
        
        // Collect surviving robots
        vector<int> ans;
        for (int health : healths){
            if (health > 0) ans.push_back(health);
        }
        
        return ans;
    }
};