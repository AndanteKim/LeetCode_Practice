class Solution {
private:
    int maxWidth;
    vector<string> getWords(int i, vector<string>& words){
        vector<string> currentLine;
        int currLength = 0;
        
        while (i < words.size() && currLength + words[i].size() <= maxWidth){
            currentLine.push_back(words[i]);
            currLength += words[i].size() + 1;
            ++i;
        }
        
        return currentLine;
    }
    
    string createLine(vector<string>& line, int i, vector<string>& words){
        int baseLength = -1;
        for (string& word : line) baseLength += word.size() + 1;
            
        int extraSpaces = maxWidth - baseLength;
        if (line.size() == 1 || i == words.size()){
            string ans = "";
            for (string& word : line){
                ans += word + ' ';
            }
            return ans.substr(0, ans.size() - 1) + string(extraSpaces, ' ');
        }
        
        int wordCount = line.size() - 1;
        int spacesPerWord = extraSpaces / wordCount + 1, needsExtraSpace = extraSpaces % wordCount;
        
        for (int j = 0; j < needsExtraSpace; ++j) {
            line[j] += " ";
        }
        for (int j = 0; j < wordCount; ++j) line[j] += string(spacesPerWord, ' ');
        
        string ans = "";
        for (string& word : line) {
            ans += word;
        }
        return ans;
    }
    
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        this -> maxWidth = maxWidth;
        while (i < words.size()){
            vector<string> currentLine = getWords(i, words);
            i += currentLine.size();
            ans.push_back(createLine(currentLine, i, words));
        }
        
        return ans;
    }
};