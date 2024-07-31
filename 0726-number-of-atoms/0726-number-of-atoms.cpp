class Solution {
public:
    string countOfAtoms(string formula) {
        // For multiplier
        int runningMul = 1;
        stack<int> st;
        st.push(1);
        
        // Map to store the count of atoms
        map<string, int> finalMap;
        
        // Strings to take care of current atom and count
        string currAtom = "", currCount = "";
        
        // Index to traverse the formula in reverse and parse the formula
        for (int i = formula.size() - 1; i >= 0; --i){
            // If digit, update the count
            if (isdigit(formula[i]))
                currCount = formula[i] + currCount;
            
            // If lowercase letter, prepend to the currAtom
            else if (islower(formula[i]))
                currAtom = formula[i] + currAtom;
            
            // If uppercase letter, prepend and update the finalMap
            else if (isupper(formula[i])){
                currAtom = formula[i] + currAtom;
                if (!currCount.empty())
                    finalMap[currAtom] += stoi(currCount) * runningMul;
                else
                    finalMap[currAtom] += 1 * runningMul;
                
                currAtom.clear(), currCount.clear();
            }
            
            // If the right parenthesis, the currCount if any
            // will be considered a multiplier
            else if (formula[i] == ')'){
                int currMultiplier = (!currCount.empty())? stoi(currCount) : 1;
                st.push(currMultiplier);
                runningMul *= currMultiplier;
                currCount.clear();
            }
            
            // If the left parenthesis, update the runningMul
            else if (formula[i] == '('){
                runningMul /= st.top();
                st.pop();
            }
            
        }
        
        // Generate the answer string
        string ans = "";
        for (auto& [atom, val] : finalMap){
            ans += atom;
            if (val > 1)
                ans += to_string(val);
        }
        
        return ans;
    }
};