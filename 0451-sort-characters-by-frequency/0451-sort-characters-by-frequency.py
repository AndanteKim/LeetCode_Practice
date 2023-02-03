class Solution:
    def frequencySort(self, s: str) -> str:
        dict_s = defaultdict(int)
        for c in s:
            dict_s[c] += 1
        
        sort_dict = sorted(dict_s, key = dict_s.get, reverse= True)
        answer = ""
        for key in sort_dict:
            answer += key * dict_s[key]
            
        return answer