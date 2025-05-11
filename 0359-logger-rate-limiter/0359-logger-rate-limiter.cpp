class Logger {
private:
    unordered_map<string, int> logs;

public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (logs.count(message) > 0 && logs[message] + 10 > timestamp) return false;
        logs[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */