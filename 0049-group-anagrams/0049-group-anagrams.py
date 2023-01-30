class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        group_list = defaultdict(list)
        
        for string in strs:
            word_chars = [0] * 26
            for c in string:
                word_chars[ord(c)-ord('a')] += 1
            group_list[tuple(word_chars)].append(string)
        ans = []
        for group in group_list:
            ans.append(group_list[group])
            
        return ans
        