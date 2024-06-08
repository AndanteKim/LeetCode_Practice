class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""
        
        dict_t = Counter(t)
        required = len(dict_t)
        
        # Filter all the characters from s into a new list along with their index.
        # The filtering criteria is that the character should be present in t.
        filtered_s = []
        for i, ch in enumerate(s):
            if ch in dict_t:
                filtered_s.append((i, ch))
        
        l, r = 0, 0
        formed = 0
        window_counts = dict()
        ans = float('inf'), None, None
        
        # Look for the characters only in the filtered list instead of entire s. This helps to reduce our search.
        # Hence, we follow the sliding window approach on as small list.
        while r < len(filtered_s):
            ch = filtered_s[r][1]
            window_counts[ch] = window_counts.get(ch, 0) + 1
            
            if window_counts[ch] == dict_t[ch]:
                formed += 1
                
            # If the current window has all the characters in the desired frequencies i.e. t is present in the window
            while l <= r and formed == required:
                ch = filtered_s[l][1]
                
                # Save the smallest window until now.
                end = filtered_s[r][0]
                start = filtered_s[l][0]
                if end - start + 1 < ans[0]:
                    ans = (end - start + 1, start, end)
                    
                window_counts[ch] -= 1
                if window_counts[ch] < dict_t[ch]:
                    formed -= 1
                l += 1
            
            r += 1
        
        return "" if ans[0] == float('inf') else s[ans[1] : ans[2] + 1]