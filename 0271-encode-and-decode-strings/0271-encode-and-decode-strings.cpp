class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        ostringstream outputStringStream;
        for (string& str: strs){
            if (str.empty()) outputStringStream << '\0';
            else outputStringStream << str;
            outputStringStream << '\n';
        }
        
        return outputStringStream.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        istringstream inputStringStream(s);
        string tempStr;
        vector<string> ans;
        while (getline(inputStringStream, tempStr, '\n')){
            if (tempStr == "\0") ans.push_back("");
            else ans.push_back(tempStr);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));