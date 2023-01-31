class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, vector<int>> dictionary;
        int answer = INT_MAX;
        for (int i = 0; i < cards.size(); ++i) dictionary[cards[i]].push_back(i);
        
        for (const auto& [key, value] : dictionary){
            vector<int> arr = value;
            for (int i = 0; i < arr.size()-1; ++i) answer = min(answer, arr[i+1] - arr[i] + 1);
        }
        return answer == INT_MAX? -1: answer;
    }
};