class Solution:
    def largestVariance(self, s: str) -> int:
        ans = 0
        chars_pos = defaultdict(list)
        
        for i in range(len(s)):
            chars_pos[s[i]].append(i)
        
        for major in chars_pos.keys():
            for minor in chars_pos.keys():
                if major == minor:
                    continue
                major_idx = minor_idx = major_count = minor_count = 0
                major_len, minor_len = len(chars_pos[major]), len(chars_pos[minor])
                
                while major_idx < major_len or minor_idx < minor_len:
                    if major_idx < major_len and (minor_idx == minor_len or chars_pos[major][major_idx] < chars_pos[minor][minor_idx]):
                        major_count += 1
                        major_idx += 1
                    elif minor_idx < minor_len:
                        minor_count += 1
                        minor_idx += 1
                    
                    if minor_count < major_count and major_idx < major_len:
                        major_count = minor_count = 0
                    if major_count > 0 < minor_count:
                        ans = max(ans, minor_count - major_count)
        return ans