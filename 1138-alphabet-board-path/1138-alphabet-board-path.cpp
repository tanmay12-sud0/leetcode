class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<char, pair<int, int>>hash;
        string ss;
        string a = "abcde";
        string b = "fghij";
        string c = "klmno";
        string d = "pqrst";
        string e = "uvwxy";
        string f = "z";
        int i = 0;
        for(auto x : a){
            hash[x] = make_pair(0, i);
            i++;
        }
        i=0;
        for(auto x : b){
            hash[x] = make_pair(1, i);
            i++;
        }
        i=0;
        for(auto x : c){
            hash[x] = make_pair(2, i);
            i++;
        }
        i=0;
        for(auto x : d){
            hash[x] = make_pair(3, i);
            i++;
        }
        i=0;
        for(auto x : e){
            hash[x] = make_pair(4, i);
            i++;
        }
        i=0;
        for(auto x : f){
            hash[x] = make_pair(5, i);
            i++;
        }
        bool flag = false;
        int currX = 0;
        int currY = 0;
        for(auto x : target){
           
            pair<int, int>l = hash[x];
            if(l.first < currY ){
                while(l.first < currY and((currY>=0 and currY<=4 and currX>=0 and currX<=4)or(currX==0 and currY==5))){
                    ss += 'U';
                    currY--;
                }
            }
            if(l.second < currX ){
                while(l.second < currX and((currY>=0 and currY<=4 and currX>=0 and currX<=4)or(currX==0 and currY==5))){
                    ss += 'L';
                    currX--;
                }
            }
            
            if(l.first > currY){
                while(l.first > currY and((currY>=0 and currY<=4 and currX>=0 and currX<=4)or(currX==0 and currY==5))){
                    ss += 'D';
                    currY++;
                }
            }
            
            if(l.second > currX){
                while(l.second > currX and((currY>=0 and currY<=4 and currX>=0 and currX<=4)or(currX==0 and currY==5))){
                    ss += 'R';
                    currX++;
                }
            }
        
            ss += '!';
        }

        return ss;
    }
};