class Solution {
private:
    struct Seg {
        int left, right;
        bool operator<(const Seg& rhs) const {
            if (right == rhs.right) return left > rhs.left;
            
            return right < rhs.right;
        }
    };

public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<Seg> seg(26, (Seg){-1, -1});
        // Preproces the left and right endpoints
        for (int i = 0; i < s.size(); ++i) {
            int chIdx = s[i] - 'a';
            if (seg[chIdx].left == -1) seg[chIdx].left = seg[chIdx].right = i;
            else seg[chIdx].right = i;
        }

        for (int i = 0; i < 26; ++i) {
            if (seg[i].left != -1) {
                for (int j = seg[i].left; j <= seg[i].right; ++j) {
                    int chIdx = s[j] - 'a';
                    if (seg[i].left <= seg[chIdx].left && seg[chIdx].right <= seg[i].right) continue;
                    
                    seg[i].left = min(seg[i].left, seg[chIdx].left);
                    seg[i].right = max(seg[i].right, seg[chIdx].right);
                    j = seg[i].left;
                }
            }
        }

        sort(seg.begin(), seg.end());
        vector<string> ans;
        int end = -1;
        for (auto& se : seg) {
            int left = se.left, right = se.right;
            if (left == -1) continue;
            if (end == -1 || left > end) {
                end = right;
                ans.emplace_back(s.substr(left, right - left + 1));
            }
        }

        return ans;
    }
};