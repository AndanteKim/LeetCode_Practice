class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> sentences;
};


class AutocompleteSystem {
private:
    TrieNode* root;
    TrieNode* currNode;
    TrieNode* dead;
    string currSentence;

    void addToTrie(const string& sentence, int count) {
        TrieNode* node = root;
        for (const char& c : sentence) {
            if (!node -> children.count(c)) node -> children[c] = new TrieNode();
            node = node -> children[c];
            node -> sentences[sentence] += count;
        }
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode(), dead = new TrieNode();

        for (int i = 0; i < sentences.size(); ++i) addToTrie(sentences[i], times[i]);
        currNode = root;
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            addToTrie(currSentence, 1);
            currSentence = "";
            currNode = root;
            return {};
        }

        currSentence += c;

        if (!currNode -> children.count(c)) {
            currNode = dead;
            return {};
        }

        currNode = currNode -> children[c];
        vector<pair<string, int>> sortedSentences(currNode -> sentences.begin(), currNode -> sentences.end());
        sort(sortedSentences.begin(), sortedSentences.end(),
            [](const auto& a, const auto& b) {
                return a.second != b.second? a.second > b.second : a.first < b.first;
            }
        );

        vector<string> ans;
        for (int i = 0; i < min(3, (int)sortedSentences.size()); ++i) ans.push_back(sortedSentences[i].first);

        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */