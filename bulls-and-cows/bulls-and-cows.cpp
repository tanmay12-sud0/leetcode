class Solution {
public:
    string getHint(string secret, string guess) {
        int cow=0;
        int bull=0;
        unordered_map<char, int>hash;
        for(int i=0; i<secret.length(); i++){
            hash[secret[i]]++;
        }
        for(int i=0; i<guess.length(); i++){
            if(hash.count(guess[i]) and hash[guess[i]] != 0 and secret[i] == guess[i]){
                bull++;
                hash[secret[i]]--;
            }
        }
        
        for(int i=0; i<guess.length(); i++){
        if(hash.count(guess[i]) and hash[guess[i]] != 0 and secret[i] != guess[i]){
                cow++;
                cout << "hello" << i << endl;
                hash[guess[i]]--;
            }
        }
        
        cout << cow << ", " << bull << endl;
        string s = "";
        s = to_string(bull) + "A" + to_string(cow) + "B";
        return s;
    }
};