class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> r_table, m_table;
        
        for (const auto &c:ransomNote) r_table[c] += 1;
        for (const auto&c:magazine) m_table[c] += 1;
        
        for (auto iter : r_table){
            if (iter.second > m_table[iter.first]) return false;
        }
        
        return true;
    }
};