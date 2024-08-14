class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        queue<pair<string, int>> queue;
        queue.push({startGene, 0});
        int n = startGene.size();
        unordered_set<string> visited, bankGenes(bank.begin(), bank.end());
        visited.insert(startGene);
        const string geneChar{"ACGT"};
        
        while (!queue.empty()){
            auto [curr, steps] = queue.front(); queue.pop();
            
            if (curr == endGene)
                return steps;
            
            for (const char& c : geneChar){
                for (int i = 0; i < n; ++i){
                    string neighbor = curr.substr(0, i) + c + curr.substr(i + 1);
                    if (bankGenes.count(neighbor) && !visited.count(neighbor)){
                        visited.insert(neighbor);
                        queue.push({neighbor, steps + 1});
                    }
                }
            }
            
        }
        
        return -1;
    }
};