class Solution:
    def numberToWords(self, num: int) -> str:
        # Handle the special case where the number is zero
        if num == 0:
            return "Zero"
        
        # Arrays to store words for single digits, tens, and thousands
        ones = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",\
               "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",\
               "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        
        tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", \
               "Eighty", "Ninety"]
        thousands = ["", "Thousand", "Million", "Billion"]
        
        # StringBuilder to accumulate the result
        ans, group_idx = "", 0
        
        # Process the number in chunks of 1000
        while num > 0:
            # Process the last three digits
            if num % 1000 != 0:
                group_res = ""
                part = num % 1000
                
                # Handle hundreds:
                if part >= 100:
                    group_res += ones[part // 100] + " Hundred "
                    part %= 100
                    
                # Handle tens and units
                if part >= 20:
                    group_res += tens[part // 10] + " "
                    part %= 10
                
                # Handle units
                if part > 0:
                    group_res += ones[part] + " "
                    
                # Append the scale (thousand, million, billion) for the current group
                group_res += thousands[group_idx] + " "
                
                # Insert the group result at the beginning of the final result
                ans = group_res + ans
                
            # Move to the next chunk of 1000
            num //= 1000
            group_idx += 1
            
        return ans.strip()