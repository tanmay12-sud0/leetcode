class Solution {
public:
    
    
class Node{
    public:

        char s;
        unordered_map<char, Node*>hash;
        bool terminal;
        unordered_map<char, int>cnt;
    
        Node(char ss){
            s = ss;
            terminal = false;
        }
};

class Trie{
    Node* root;
    public:
        Trie(){
            root = new Node('\0');
        }
        void insert(string w){
            Node* temp = root;
            for(int i=0; w[i]!='\0'; i++){
                char ch = w[i];
                if(temp->hash.count(ch)){
                    temp->cnt[ch]++;
                    temp = temp->hash[ch];
                }else{
                    Node* n = new Node(ch);
                    temp->hash[ch] = n;
                    temp->cnt[ch]++;
                    temp = n;
                    
                }
            }
            temp->terminal = true;
        }

        string find(string w, int n){
            Node* temp = root;
            string pp="";
            for(int i=0; w[i]!='\0'; i++){
                char ch = w[i];
                cout << temp->cnt[ch] << endl;
                if(temp->cnt[ch] != n){
                    return pp;
                }else{
                    pp += ch;
                    temp = temp->hash[ch];
                }
            }
            return pp;
        }
};

    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        int n = strs.size();
        for(auto x : strs){
            t.insert(x);
        }
        return t.find(strs[0], n);
    }
};