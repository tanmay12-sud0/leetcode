class Trie {
public:
    
    
class Node{
    public:

        char s;
        unordered_map<char, Node*>hash;
        bool terminal;

        Node(char ss){
            s = ss;
            terminal = false;
        }
};

class Tries{
    Node* root;
    public:
        Tries(){
            root = new Node('\0');
        }
        void insert(string w){
            Node* temp = root;
            for(int i=0; w[i]!='\0'; i++){
                char ch = w[i];
                if(temp->hash.count(ch)){
                    temp = temp->hash[ch];
                }else{
                    Node* n = new Node(ch);
                    temp->hash[ch] = n;
                    temp = n;
                }
            }
            temp->terminal = true;
        }

        bool find(string w){
            Node* temp = root;
            for(int i=0; w[i]!='\0'; i++){
                char ch = w[i];
                if(!temp->hash.count(ch)){
                    return false;
                }else{
                    temp = temp->hash[ch];
                }
            }
            return temp->terminal;
        }
    
        bool findss(string w){
            Node* temp = root;
            for(int i=0; w[i]!='\0'; i++){
                char ch = w[i];
                if(!temp->hash.count(ch)){
                    return false;
                }else{
                    temp = temp->hash[ch];
                }
            }
            return true;
        }
};


    
    Tries t;
        
    Trie() {
        
    }
    
    void insert(string word) {
        t.insert(word);
        return;
    }
    
    bool search(string word) {
        return t.find(word);
    }
    
    bool startsWith(string prefix) {
        return t.findss(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */