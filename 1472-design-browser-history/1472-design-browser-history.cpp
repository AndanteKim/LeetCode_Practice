class BrowserHistory {
    vector<string> history, future;
    string current;
public:
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        history.push_back(current);
        current = url;
        future.clear();
    }
    
    string back(int steps) {
        while (steps > 0 && !history.empty()){
            future.push_back(current);
            current = history.back();
            history.pop_back();
            --steps;
        }
        return current;
    }
    
    string forward(int steps) {
        while (steps > 0 && !future.empty()){
            history.push_back(current);
            current = future.back();
            future.pop_back();
            --steps;
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */