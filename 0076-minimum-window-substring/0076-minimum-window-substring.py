class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""
        
        dict_t = Counter(t)
        required = len(dict_t)
        
        # Filter all the characters from s into a new list along with their index.
        # The filtering criteria is that the character should be present in t.
        filtered_s = []
        
        for i, c in enumerate(s):
            if c in dict_t:
                filtered_s.append((i, c))
                
        left, formed = 0, 0
        window_counts = dict()
        ans = float("inf"), None, None
        
        # Look for the characters only in the filtered list instead of entire s. This helps to reduce our search.
        # Hence, we follow the sliding window approach on as small list.
        
        for right in range(len(filtered_s)):
            ch = filtered_s[right][1]
            window_counts[ch] = window_counts.get(ch, 0) + 1
            
            if window_counts[ch] == dict_t[ch]:
                formed += 1
                
            # If the current window has all the characters in desired frequencies i.e. t is present in the window
            while left <= right and formed == required:
                ch = filtered_s[left][1]
                
                # Save the smallest window until now.
                end, start = filtered_s[right][0], filtered_s[left][0]
                if end - start + 1 < ans[0]:
                    ans = (end - start + 1, start, end)
                    
                window_counts[ch] -= 1
                if window_counts[ch] < dict_t[ch]:
                    formed -= 1
                left += 1
         
        return "" if ans[0] == float("inf") else s[ans[1] : ans[2] + 1]
        
                