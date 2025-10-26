class Bank {
private:
    int n;
    vector<long long> balances;

public:
    Bank(vector<long long>& balance) {
        this -> n = balance.size();
        balances = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (notAvailableTransaction(account1, money) || account2 > n) return false;

        balances[account1 - 1] -= money;
        balances[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > n) return false;
        balances[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (notAvailableTransaction(account, money)) return false;
        balances[account - 1] -= money;
        return true;
    }

    bool notAvailableTransaction(int account, long long money){
        return account > n || balances[account - 1] < money;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */