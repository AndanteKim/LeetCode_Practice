class Solution:
    def maxLength(self, arr: List[str]) -> int:
        # Initialize results with an empty string
        # from which to build all future results
        results, ans = [""], 0
        
        for word in arr:
            # We only want to iterate through results
            # that exisited prior this loop
            
            for i in range(len(results)):
                # Form a new result combination and
                # use a set to check for duplicate characters
                new_res = results[i] + word
                if len(new_res) != len(set(new_res)):
                    continue
                
                # Add valid options results and
                # keep track of the longest so far
                results.append(new_res)
                ans = max(ans, len(new_res))
       
        return ans
        