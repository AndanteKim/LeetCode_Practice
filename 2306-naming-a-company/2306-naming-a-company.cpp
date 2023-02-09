class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> initial_groups[26];
        
        for (string& idea: ideas){
            initial_groups[idea[0] - 'a'].insert(idea.substr(1));
        }
        
        long long answer = 0;
        for (int i = 0; i < 25; ++i){
            for (int j = i + 1; j < 26; ++j){
                int num_of_mutual = 0;
                for (const string& ideaA : initial_groups[i]){
                    if (initial_groups[j].count(ideaA)) ++num_of_mutual;
                }
                answer += 2LL * (initial_groups[i].size() - num_of_mutual) * (initial_groups[j].size() - num_of_mutual);
            }
        }
        
        return answer;
    }
};