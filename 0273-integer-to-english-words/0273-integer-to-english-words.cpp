class Solution {
public:
    string numberToWords(int num) {
        // Handle the special case where the number is zero.
        if (num == 0)
            return "Zero";
        
        // Arrays to store words for single digits, tens, and thousands
        const vector<string> ones {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", \
                             "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",\
                             "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        const vector<string> tens {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",\
                             "Eighty", "Ninety"};
        const vector<string> thousands {"", "Thousand", "Million", "Billion"};
        
        // StringBuilder to accumulate the result
        string ans = "";
        int groupIndex = 0;
        
        // Process the number in chunks of 1000
        while (num > 0){
            // Process the last three digits
            if (num % 1000 != 0){
                string groupResult = "";
                int part = num % 1000;
                
                // Handle hundreds
                if (part >= 100){
                    groupResult += ones[part / 100] + " Hundred ";
                    part %= 100;
                }
                
                // Handle tens and units
                if (part >= 20){
                    groupResult += tens[part / 10] + " ";
                    part %= 10;
                }
                
                // Handle units
                if (part > 0)
                    groupResult += ones[part] + " ";
                
                // Append the scale (thousand, million, billion) for the current group
                groupResult += thousands[groupIndex] + " ";
                
                // Insert the group result at the beginning of the final result
                ans = groupResult + ans;
            }
            
            // Move to the next chunk of 1000
            num /= 1000;
            ++groupIndex;
        }
        
        return ans.substr(0, ans.find_last_not_of(" ") + 1); // Remove trailing spaces
    }
};