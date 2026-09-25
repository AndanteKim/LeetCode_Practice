class Solution {
private:
    string expression;
    int i;

    set<string> item() {
        set<string> ret;
        if (expression[i] == '{') {
            ++i;
            ret = expr();
        }
        else ret = {string(1, expression[i])};
        ++i;
        return move(ret);
    }

    set<string> term() {
        set<string> ret = {""};
        while (i < expression.size() && (expression[i] == '{' || isalpha(expression[i]))) {
            auto sub = item();
            set<string> tmp;
            for (auto& left : ret) {
                for (auto& right : sub) tmp.insert(left + right);
            }

            ret = move(tmp);
        }

        return move(ret);
    }

    set<string> expr() {
        set<string> ret;
        while (true) {
            ret.merge(term());

            if (i < expression.size() && expression[i] == ',') {
                ++i;
                continue;
            } else break;
            
        }

        return move(ret);
    }

public:
    vector<string> braceExpansionII(string expression) {
        this -> expression = expression;
        this -> i = 0;
        auto ret = expr();
        return {ret.begin(), ret.end()};
    }
};