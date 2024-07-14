class Solution {
private:
    // Current index. It should be global as needs 
    // to be updated in the recursive function
    int n, idx = 0;
    map<string, int> parseFormula(string& formula){
        // Local variable
        string currAtom = "", currCnt = "";
        map<string, int> currMap;
        
        while (idx < n){
            // Uppercase letter
            if (isupper(formula[idx])){
                // Save the previous atom and count.
                if (!currAtom.empty()){
                    if (currCnt.empty()) ++currMap[currAtom];
                    else
                        currMap[currAtom] += stoi(currCnt);
                }
                
                currAtom = formula[idx++];
                currCnt = "";
            }
            
            // Lowercase letter
            else if (islower(formula[idx])){
                currAtom += formula[idx++];
            }
            
            // Digit. Concentrate the count
            else if (isdigit(formula[idx])){
                currCnt += formula[idx++];
            }
            
            // Left parentheses
            else if (formula[idx] == '('){
                ++idx;
                map<string, int> nestedMap = parseFormula(formula);
                for (auto& [atom, cnt] : nestedMap)
                    currMap[atom] += cnt;
            }
            
            // Right parentheses
            else if (formula[idx] == ')'){
                // Save the last atom and count of nested formula
                if (!currAtom.empty()){
                    if (currCnt.empty())
                        ++currMap[currAtom];
                    else
                        currMap[currAtom] += stoi(currCnt);
                }
                
                ++idx;
                string multiplier = "";
                
                while (idx < n && isdigit(formula[idx])){
                    multiplier += formula[idx++];
                }
                
                if (!multiplier.empty()){
                    int mult = stoi(multiplier);
                    for (auto& [atom, cnt] : currMap)
                        currMap[atom] = cnt * mult;
                }
                
                return currMap;
            }
        }
        
        // Save the last atom and count
        if (!currAtom.empty()){
            if (currCnt.empty())
                ++currMap[currAtom];
            else
                currMap[currAtom] += stoi(currCnt);
        }
        
        return currMap;
    }
    
public:
    string countOfAtoms(string formula) {
        this -> n = formula.size();
        string ans = "";
        map<string, int> finalMap = parseFormula(formula);
        
        for (auto& [atom, val] : finalMap){
            ans += atom;
            if (val > 1) ans += to_string(val);
        }
        
        return ans;
    }
};