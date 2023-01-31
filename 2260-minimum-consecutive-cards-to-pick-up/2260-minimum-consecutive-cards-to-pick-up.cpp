class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> dictionary;
        int answer = INT_MAX;
        for (int i = 0; i < cards.size(); ++i){
            if (dictionary.find(cards[i]) != dictionary.end()){
                answer = min(answer, i - dictionary[cards[i]] + 1);
            }
            dictionary[cards[i]] = i;
        } 
        return answer == INT_MAX? -1: answer;
    }
};