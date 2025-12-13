class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, 
                                           vector<string>& businessLine, 
                                           vector<bool>& AreActive) {
        unordered_map<string, priority_queue<string, vector<string>, greater<>>> categories;
        vector<string> ans;
        
        for (int i = 0; i < code.size(); i++) {
            const string& coupon_code = code[i];
            const string& b_l = businessLine[i];
            bool isActive = AreActive[i];
            
            // Check if code is non-empty
            bool isValid = !coupon_code.empty();
            
            // Validate characters if code is non-empty
            if (isValid) {
                for (char c : coupon_code) {
                    if (!(islower(c) || isupper(c) || isdigit(c) || c == '_')) {
                        isValid = false;
                        break;
                    }
                }
            }
            
            if (isValid && isActive) {
                categories[b_l].push(coupon_code);
            }
        }
        
        // Process categories in specified order
        vector<string> category_order = {"electronics", "grocery", "pharmacy", "restaurant"};
        for (const string& category : category_order) {
            auto it = categories.find(category);
            if (it != categories.end()) {
                auto& pq = it->second;
                while (!pq.empty()) {
                    ans.push_back(pq.top());
                    pq.pop();
                }
            }
        }
        
        return ans;
    }
};