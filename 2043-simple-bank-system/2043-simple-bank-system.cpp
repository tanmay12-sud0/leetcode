class Bank {
public:
    unordered_map<long long int, long long int>hash;
    int count = 1;
    Bank(vector<long long>& balance) {
        for(int i=0; i<balance.size(); i++){
            hash[i+1] = balance[i];
            count++;
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(hash[account1] >= money and account1 <= count and account2 <= count){
            hash[account1]-= money;
            hash[account2]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account <= count){
            hash[account]+= money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(hash[account] >= money and account <= count){
            hash[account]-= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */