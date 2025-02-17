class Solution {
private:
    int n;
    void backtrack(int i, int& ans, unordered_map<char, int>& count){
        if (i == n) return;

        for (auto& it : count){
            if (count[it.first] > 0){
                --count[it.first];
                ++ans;
                backtrack(i + 1, ans, count);
                ++count[it.first];
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        this -> n = tiles.size();
        int ans = 0;
        unordered_map<char, int> count;

        for (const char& c : tiles){
            ++count[c];
        }
        backtrack(0, ans, count); 

        return ans;   
    }
};