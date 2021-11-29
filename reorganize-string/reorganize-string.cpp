struct myComp
{
    constexpr bool operator()(
        pair<char, int> const &a,
        pair<char, int> const &b)
    
    {
        return a.second < b.second;
    }
};
class Solution
{

public:
    string reorganizeString(string s)
    {
        map<char, int> freq;
        int x = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i]]++;
        }

        priority_queue<pair<char, int>,vector<pair<char, int>>, myComp> pq;

        for (auto it : freq)
        {
            pq.push({it.first, it.second});
        }

        s = "";

        pair<char, int> prev = {'#', -1};

        while (!pq.empty())
        {
            auto k = pq.top();
            pq.pop();

            s += k.first;

            if (prev.second > 0)
                pq.push(prev);

            k.second--;
            prev = k;
        }

        if (x != s.length())
            return "";
        else
            return s;
    }
};


// class Solution {
// public:
//     string reorganizeString(string s) {
//         map<char, int>hash;
//         for(int i=0; s[i]!='\0'; i++){
//             hash[s[i]]++;
//         }
//         priority_queue<pair<int, char>>pq;
//         for(auto x : hash){
//             pq.push(make_pair(x.second, x.first));
//         }
//         string ss;
//         while(pq.size()>1){
//             pair<char, int>a = pq.top();
//             pq.pop();
//             pair<char, int>b = pq.top();
//             pq.pop();
            
//             ss += char(a.second);
//             ss += char(b.second);
//             a.first--;
//             b.first--;
//             if(a.first){
//                 pq.push(a);
//             }
//             if(b.first){
//                 pq.push(b);
//             }
//         }
//         // cout << ss << endl;
//         // cout << pq.size();
//         if(pq.size()==1){
//              pair<char, int>a = pq.top();
//             // cout << int(a.first) << "and " << char(a.second) << endl;
//              if(int(a.first) > 1){
//                  return "";
//              }
//             ss += a.second;
//             pq.pop();
//         }
//         return ss;
//     }
// };