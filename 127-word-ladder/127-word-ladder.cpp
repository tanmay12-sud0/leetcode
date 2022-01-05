class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        int count = 0;
        set<string>s{wordList.begin(), wordList.end()};
        q.push(beginWord);
        q.push("<--");
        while(!q.empty()){
            string a = q.front();
            cout << a << endl;
            string p = a;
            q.pop();
            if(a == "<--"){
                count++;
                if(q.empty()){
                    return 0;
                }
                q.push("<--");
                continue;
            }
            if(a == endWord){
                return ++count;
            }
            for(int i=0; i<a.length(); i++){
                for(int j=0; j<26; j++){
                    p[i] = 'a'+j;
                    if(s.count(p)){
                        q.push(p);
                        s.erase(p);
                    }
                }
                p = a;
            }
            
        }
        return 0;
    }
};