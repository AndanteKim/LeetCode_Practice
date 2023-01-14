class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        ans, match_up = "", dict()
        
        for i in range(len(s1)):
            if s1[i] not in match_up.keys():
                match_up[s1[i]] = {s1[i]}
            
                
            if s2[i] not in match_up.keys():
                match_up[s2[i]] = {s2[i]}
                
                
            match_up[s2[i]].add(s1[i])
            temp = copy.deepcopy(match_up)
            for char in match_up[s1[i]]:
                temp[s2[i]].add(char)
                temp_char = temp[char]
                for c in temp_char:
                    temp[s2[i]].add(c)
            match_up = copy.deepcopy(temp)
            
            match_up[s1[i]].add(s2[i])
            temp = copy.deepcopy(match_up)
            for char in match_up[s2[i]]:
                temp[s1[i]].add(char)
                temp_char = temp[char]
                for c in temp_char:
                    temp[s1[i]].add(c)
            match_up = copy.deepcopy(temp)
            
        
        for key, value in match_up.items():
            curr = len(value)
            for char in value:
                match_up[key] = max(match_up[key], match_up[char], key = len)
        
        for c in baseStr:
            ans += c if c not in match_up.keys() else min(match_up[c])
        return ans