class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for (int i = 0; i < 2; ++i) {
            unordered_map<char, int> chS1{{s1[i], 1}, {s1[i + 2], 1}}, chS2{{s2[i], 1}, {s2[i + 2], 1}};

            if (chS1 != chS2) return false;
        }

        return true;
    }
};