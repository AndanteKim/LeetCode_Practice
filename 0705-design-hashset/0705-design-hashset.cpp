/*struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};*/

class BSTree{
public:
    TreeNode* root;

    BSTree(){
        root = nullptr;
    }
    
    TreeNode* searchBST(TreeNode* root, int val){
        if (!root || val == root -> val) return root;
        
        return (val < root -> val)? searchBST(root -> left, val) : searchBST(root -> right, val);
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if (!root) return new TreeNode(val);
        
        if (val > root -> val)
            root -> right = insertIntoBST(root -> right, val);
        else if (val == root -> val) return root;
        else root -> left = insertIntoBST(root -> left, val);
        return root;
    }
    
    int successor(TreeNode* root){
        root = root -> right;
        while (root -> left) root = root -> left;
        return root -> val;
    }
    
    int predecessor(TreeNode* root){
        root = root -> left;
        while (root -> right) root = root -> right;
        return root -> val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key){
        if (!root) return nullptr;
        if (key > root -> val) root -> right = deleteNode(root -> right, key);
        else if (key < root -> val) root -> left = deleteNode(root -> left, key);
        else{
            if (!(root -> left || root -> right)) root = nullptr;
            else if (root -> right){
                root -> val = successor(root);
                root -> right = deleteNode(root -> right, root -> val);
            }
            else{
                root -> val = predecessor(root);
                root -> left = deleteNode(root -> left, root -> val);
            }
        }
        
        return root;
    }
};

class Bucket {
private:
    BSTree* tree;

public:
    Bucket(){
        tree = new BSTree();
    }
    
    void insert(int value){
        tree -> root = tree -> insertIntoBST(tree -> root, value);
    }
    
    void erase(int value){
        tree -> root = tree -> deleteNode(tree -> root, value);
    }
    
    bool exists(int value){
        return tree -> searchBST(tree -> root, value) != nullptr;
    }
};

class MyHashSet {
private:
    int keyRange;
    vector<Bucket*> bucketArray;
protected:
    int hash(int key){
        return key % keyRange;
    }
public:
    MyHashSet() {
        keyRange = 769;
        Bucket* bucket = new Bucket();
        for (int i = 0; i < 769; ++i) bucketArray.push_back(bucket);
    }
    
    void add(int key) {
        int bucketIndex = hash(key);
        bucketArray[bucketIndex] -> insert(key);
    }
    
    void remove(int key) {
        int bucketIndex = hash(key);
        bucketArray[bucketIndex] -> erase(key);
    }
    
    bool contains(int key) {
        int bucketIndex = hash(key);
        return bucketArray[bucketIndex] -> exists(key);
    }
};




/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */