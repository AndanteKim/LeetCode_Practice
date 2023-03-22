/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
    string start_hostname;
    unordered_set<string> visited;
    
    string get_hostname(string url){
        int pos = min(url.size(), url.find('/', 7));
        return url.substr(7, pos - 7);
    }
    
    void dfs(string url, HtmlParser htmlParser){
        visited.insert(url);
        for (string& nextUrl : htmlParser.getUrls(url)){
            if (get_hostname(nextUrl) == start_hostname && !visited.count(nextUrl)) dfs(nextUrl, htmlParser);
        }
    }
    
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        start_hostname = get_hostname(startUrl);
        dfs(startUrl, htmlParser);
        return vector<string>(visited.begin(), visited.end());
    }
};