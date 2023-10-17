class Solution {
private:
    int n;
    int findRoot(vector<int>& leftChild, vector<int>& rightChild){
        unordered_set<int> children;
        children.insert(leftChild.begin(), leftChild.end());
        children.insert(rightChild.begin(), rightChild.end());
        for (int i = 0; i < n; ++i){
            if (children.find(i) == children.end())
                return i;
        }
        
        return -1;
    }
    
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        this -> n = n;
        int root = findRoot(leftChild, rightChild);
        
        if (root == -1) return false;
        
        queue<int> q;
        q.push(root);
        unordered_set<int> seen;
        seen.insert(root);
        
        while (!q.empty()){
            int i = q.front();
            q.pop();
            
            int children[] = {leftChild[i], rightChild[i]};
            for (int child : children){
                if (child != -1){
                    if (seen.find(child) != seen.end())
                        return false;
                    
                    q.push(child);
                    seen.insert(child);
                }
            }
        }
        
        return seen.size() == n;
    }
};