class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>m_elements;
        
        for (const char&c : magazine) ++m_elements[c];
        for (const char&c : ransomNote){
            if (m_elements.find(c) == m_elements.end() || m_elements[c] == 0) return false;
            else --m_elements[c];
        }
        
        return true;
    }
};