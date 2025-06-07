class Solution {
public:
    string clearStars(string s) {
        unordered_set<int> remove;
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> minHeap;

        string ans = "";
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '*'){
                remove.insert(i);
                remove.insert(-minHeap.top().second);
                minHeap.pop();
            }
            else{
                minHeap.push({s[i], -i});
            }
        }

        for (int i = 0; i < s.size(); ++i){
            if (!remove.count(i)) ans.push_back(s[i]);
        }
        return ans;
    }
};