/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        function<string(string)> get_hostname = [](string url) -> string{
            int pos = min(url.size(), url.find('/', 7));
            return url.substr(7, pos - 7);
        };
        
        string start_hostname = get_hostname(startUrl);
        unordered_set<string> *visited = new unordered_set<string>;
        
        function<void(string)> dfs = [&](string url) -> void{
            visited -> insert(url);
            for (string& next_url : htmlParser.getUrls(url)){
                if (get_hostname(next_url) == start_hostname && !visited -> count(next_url)) dfs(next_url);
            }
        };
        
        dfs(startUrl);
        return vector<string>(visited -> begin(), visited -> end());
    }
};