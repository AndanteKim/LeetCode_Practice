class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        // Base case
        if (rows == 1) return encodedText;

        int n = encodedText.size(), cols = n / rows;
        string ans;
        ans.reserve(n);

        for (int c = 0; c < cols; ++c) {
            for (int i = 0, j = c; i < rows && j < cols && i * cols + j < n; ++i, ++j) {
                ans.push_back(encodedText[i * cols + j]);
            }
        }

        while (!ans.empty() && ans.back() == ' ') ans.pop_back();

        return ans;
    }
};