class Solution {
private:
    void addOne(string& s){
        int n = s.size(), i = n - 1;
        
        while (i >= 0 && s[i] != '0'){
            s[i--] = '0';
        }
        
        if (i < 0)
            s = '1' + s;
        else
            s[i] = '1';
    }
    
public:
    int numSteps(string s) {
        int n, operations = 0;
        
        while (s.size() > 1){
            int n = s.size();
            if (s[n - 1] == '1')
                addOne(s);
            else
                s.pop_back();
            
            ++operations;
        }
        
        return operations;
    }
};