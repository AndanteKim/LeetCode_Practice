typedef long long ll;

class LogSystem {
private:
    vector<pair<ll, int>> logs;     // {normalized_timestamp, id}
    unordered_map<string, int> graMap;

    // Parse timestamp string to integer vector [Y, M, D, h, m, s]
    vector<int> parseTimestamp(const string& ts) {
        vector<int> parts;
        stringstream ss(ts);
        string token;

        while (getline(ss, token, ':')) parts.push_back(stoi(token));    
        
        return parts;
    }
    
    // Convert [Y, M, D, h, m, s] to normalized timestamp value
    ll convert(vector<int> st) {
        if (st[1] != 0) --st[1];
        if (st[2] != 0) --st[2];

        return (st[0] - 1999L) * (31LL * 12 * 24 * 60 * 60)\
            + st[1] * (31LL * 24 * 60 * 60)\
            + st[2] * (24LL * 60 * 60)\
            + st[3] * (60LL * 60)\
            + st[4] * 60LL
            + st[5];
    }

    // normalized timestamp
    ll criteria(const string& ts, const string& gra, bool isEnd) {
        vector<string> base = {"1999", "00", "00", "00", "00", "00"};
        vector<string> parts = split(ts, ':');

        int graIdx = graMap[gra];
        for (int i = 0; i <= graIdx; ++i) base[i] = parts[i];

        // Convert to integers and adjust end boundary
        vector<int> comps;
        for (const auto& s : base) comps.push_back(stoi(s));
        if (isEnd) comps[graIdx]++;
        return convert(comps);
    }

    // Helper: split string by delimiter
    vector<string> split(const string& s, char delim) {
        vector<string> tokens;
        string token;
        istringstream iss(s);
        while (getline(iss, token, delim)) tokens.push_back(token);

        return tokens;
    }

public:
    LogSystem() {
        graMap = {
            {"Year", 0}, {"Month", 1}, {"Day", 2},
            {"Hour", 3}, {"Minute", 4}, {"Second", 5}
        };
    }
    
    void put(int id, string timestamp) {
        vector<int> parts = parseTimestamp(timestamp);
        ll tsVal = convert(parts);
        logs.emplace_back(tsVal, id);
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        ll startTS = criteria(start, granularity, false);
        ll endTS = criteria(end, granularity, true);     // exclusive upper bound

        vector<int> ans;
        for (const auto& [ts, id] : logs) {
            if (ts >= startTS && ts < endTS) ans.push_back(id);
        }

        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */