class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> process(bank.begin(), bank.end()), seen;
        queue<pair<string, int>> queue;
        queue.push({startGene, 0});
        seen.insert(startGene);
        int ans = INT_MAX;
        
        while(!queue.empty()){
            auto[gene, mutations] = queue.front();
            queue.pop();
            
            if (gene == endGene) return mutations;
            
            for (int digit = 0; digit < 8; ++digit){
                for (const char& c : {'A', 'C', 'G', 'T'}){
                    string newGene = gene.substr(0, digit) + c + gene.substr(digit+1);
                    if (seen.find(newGene) == seen.end() && process.find(newGene) != process.end()){
                        seen.insert(newGene);
                        queue.push({newGene, mutations + 1});
                    }
                }
            }
        }
        
        return ans == INT_MAX? -1 : ans;
    }
};