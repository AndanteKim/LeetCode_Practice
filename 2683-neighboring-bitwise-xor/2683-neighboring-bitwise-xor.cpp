class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // Create an original array initialized with 0.
        int n = derived.size();
        vector<int> original{0};
        for (int i = 0; i < n; ++i)
            original.push_back(original[i] ^ derived[i]);

        // Store the validation results in checkForZero and checkForOne respectively.
        bool checkForZero = (original[0] == original.back());
        original = {1};
        for (int i = 0; i < n; ++i)
            original.push_back(original[i] ^ derived[i]);

        bool checkForOne = (original[0] == original.back());

        return checkForZero | checkForOne;
    }
};