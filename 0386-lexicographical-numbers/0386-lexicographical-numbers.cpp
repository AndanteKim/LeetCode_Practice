struct Node {
    Node *links[10];
    bool flag = false;
    bool containsKey(char ch) const{
        return links[ch - '0'] != NULL;
    }
    
    void put(char& ch, Node* node){
        links[ch - '0'] = node;
    }
    
    Node* get(char& ch) const{
        return links[ch - '0'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool getEnd() const{
        return flag;
    }
};

class Trie{
private:
    Node* root;
    friend class Solution;
    
public:
    Trie(){
        root = new Node();
    }
    
    void insert(string& num){
        Node* temp = root;
        for (int i = 0; i < num.size(); ++i){
            if (!temp -> containsKey(num[i]))
                temp -> put(num[i], new Node());
            temp = temp -> get(num[i]);
        }
        temp -> setEnd();
    }
};

class Solution {
private:
    void dfs(Node* root, int curr, vector<int>& ans){
        if (!root) return;
        
        if (root -> getEnd()){
            ans.push_back(curr);
        }
        
        for (char ch = '0'; ch <= '9'; ++ch){
            if (root -> containsKey(ch))
                dfs(root -> get(ch), (curr * 10) + ch - '0', ans);
        }
        
    }
    
public:
    vector<int> lexicalOrder(int n) {
        Trie *trie = new Trie();
        
        for (int i = 1; i <= n; ++i){
            string s = to_string(i);
            trie -> insert(s);
        }
        
        vector<int> ans;
        dfs(trie -> root, 0, ans);
        return ans;
    }
};