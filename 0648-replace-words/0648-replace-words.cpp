class Solution {
private:
    string shortestRoot(string& word, unordered_set<string>& mapSet){
        // Find the shortest root of the word in the dictionary
        for (int i = 1; i <= word.size(); ++i){
            string root = word.substr(0, i);
            if (mapSet.find(root) != mapSet.end())
                return root;
        }
        
        // There is not a corresponding root in the dictionary
        return word;
    }
    
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> mapSet(dictionary.begin(), dictionary.end());
        istringstream sStream(sentence);
        
        // Replace each word in sentence with the corresponding shortest root
        string word, newSentence;
        while (getline(sStream, word, ' '))
            newSentence += shortestRoot(word, mapSet) + " ";
        
        newSentence.pop_back(); // remove extra space
        return newSentence;
    }
};