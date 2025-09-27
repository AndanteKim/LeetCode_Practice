struct Node{
    string name;
    int timestamp;
    string website;
};

bool compareNodes(const Node* a, const Node* b){
    return a -> timestamp < b -> timestamp;
}

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<Node*> nodes;
        for (size_t i = 0; i < username.size(); ++i)
            nodes.push_back(new Node({username[i], timestamp[i], website[i]}));
        
        sort(nodes.begin(), nodes.end(), compareNodes);
        unordered_map<string, vector<Node*>> userVisits;
        for(const auto& node : nodes)
            userVisits[node -> name].push_back(node);
        
        map<vector<string>, int> route;
        for (const auto& entry : userVisits){
            set<vector<string>> tmp;
            for (size_t i = 0; i < entry.second.size(); ++i){
                for (size_t j = i + 1; j < entry.second.size(); ++j){
                    for (size_t k = j + 1; k < entry.second.size(); ++k){
                        tmp.insert({
                            entry.second[i] -> website,
                            entry.second[j] -> website,
                            entry.second[k] -> website
                        });
                    }
                }
            }
        
            for (const auto& path : tmp) ++route[path];
        }

        vector<string> result;
        int max = -1;

        for (const auto& entry : route){
            if (entry.second > max ||
                (entry.second == max && entry.first < result)){
                    max = entry.second;
                    result = entry.first;
            }
        }

        return result;
    }
};