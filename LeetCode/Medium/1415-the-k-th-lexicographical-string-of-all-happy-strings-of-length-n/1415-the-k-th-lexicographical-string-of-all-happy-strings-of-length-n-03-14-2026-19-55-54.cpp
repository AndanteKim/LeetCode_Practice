class Solution {
private:
    string currStr = "", ans = "";
    int indexInSortedList = 0;
    vector<char> chars{'a', 'b', 'c'};

    void backtrack(int n, int k) {
        // Base case
        if (currStr.size() == n) {
            ++indexInSortedList;
            if (indexInSortedList == k)
                ans = currStr;
            return;
        }

        // Try adding each character ('a', 'b', 'c') to the current string
        for (const auto& c : chars) {
            // Skip if the current character is the same as the last one
            if (currStr.size() > 0 && currStr.back() == c) continue;

            currStr.push_back(c);

            // Recursively generate the next character
            backtrack(n, k);
            
            // If the ans is found, stop further processing
            if (ans != "") return;

            // Backtrack by removing the last character
            currStr.pop_back();
        }
    }

public:
    string getHappyString(int n, int k) {
        // Generate happy strings and track the k-th string
        backtrack(n, k);    
    
        return ans;
    }
};