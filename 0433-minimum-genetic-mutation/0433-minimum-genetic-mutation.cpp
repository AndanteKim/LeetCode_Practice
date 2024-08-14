class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int ans = INT_MAX, n = startGene.size();
        unordered_set<string> validBank(bank.begin(), bank.end()), visited;
        queue<pair<string, int>> queue;
        queue.push({startGene, 0});
        visited.insert(startGene);
        const vector<int> geneChar{'A', 'C', 'G', 'T'};
        
        while (!queue.empty()){
            auto [curr, steps] = queue.front(); queue.pop();
            
            if (curr == endGene)
                ans = min(ans, steps);
            
            for (int i = 0; i < n; ++i){
                char temp = curr[i];
                for (const auto& c : geneChar){
                    if (curr[i] != c){
                        curr[i] = c;
                        if (validBank.count(curr) && !visited.count(curr)){
                            queue.push({curr, steps + 1});
                            visited.insert(curr);
                        }
                        curr[i] = temp;
                    }
                }
            }
        }
        
        return ans == INT_MAX? -1 : ans;
    }
};