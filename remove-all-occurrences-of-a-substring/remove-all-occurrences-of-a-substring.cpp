class Solution {
public:
    string removeOccurrences(string s, string part) {
        int partLen = part.size();
        size_t found = s.find(part); 
        
        while(found != string::npos){
            s.erase(s.begin()+found, s.begin()+found+partLen);  
            found = s.find(part); 
        }
        return s;
    }
};