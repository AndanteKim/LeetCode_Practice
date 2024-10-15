class FirstUnique {
private:
    struct Node{
        int val;
        Node *prev, *next;
        Node(int x, Node* p, Node* n): val(x), prev(p), next(n){}
    };
    unordered_map<int, Node*> root;
    unordered_set<int> duplicates;
    Node *head, *tail;
    
public:
    FirstUnique(vector<int>& nums): head(nullptr), tail(nullptr) {
        for (int num : nums)
            // Notice that we're calling the "add" method of FirstUnique; not of the queue.
            add(num);
    }
    
    int showFirstUnique() {
        // Check if there's still a value left in the queue. There might be no uniques.
        if (head) return head -> val;
        return -1;
    }
    
    void add(int value) {
        if (duplicates.count(value)) return;
        
        auto iter = root.find(value);
        if (iter == root.end()){
            if (tail){
                tail -> next = new Node(value, tail, nullptr);
                tail = tail -> next;
            }
            else{
                head = new Node(value, nullptr, nullptr);
                tail = head;
            }
            root.insert({value, tail});
        }
        else{
            duplicates.insert(value);
            Node* node = iter -> second;
            
            if (head == node)
                head = node -> next;
            
            if (tail == node)
                tail = tail -> prev;
            
            if (node -> next)
                node -> next -> prev = node -> prev;
            
            if (node -> prev)
                node -> prev -> next = node -> next;
            root.erase(iter);
            delete node;
        }
        
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */