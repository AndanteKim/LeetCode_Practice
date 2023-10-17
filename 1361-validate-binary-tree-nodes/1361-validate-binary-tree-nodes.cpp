class Solution {
private:
    int findRoot(vector<int>& leftChild, vector<int>& rightChild){
        unordered_set<int> children;
        children.insert(leftChild.begin(), leftChild.end());
        children.insert(rightChild.begin(), rightChild.end());
        
        for (int i = 0; i < leftChild.size(); ++i)
            if (children.find(i) == children.end())
                return i;
        return -1;
    }
    
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(leftChild, rightChild);
        if (root == -1) return false;
        unordered_set<int> seen;
        stack<int> s;
        s.push(root);
        seen.insert(root);
        
        while (!s.empty()){
            int i = s.top();
            s.pop();
            
            int children[] = {leftChild[i], rightChild[i]};
            for (int node : children){
                if (node != -1){
                    if (seen.find(node) != seen.end())
                        return false;
                    seen.insert(node);
                    s.push(node);
                }
            } 
        }
        
        return seen.size() == n;
    }
};