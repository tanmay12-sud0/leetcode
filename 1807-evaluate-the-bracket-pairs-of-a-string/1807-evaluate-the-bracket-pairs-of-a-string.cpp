class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string>m;
        for(int i=0;i<knowledge.size();i++)
        {
            m[knowledge[i][0]]=knowledge[i][1];
        }
        stack<char>st;
        string ans="";
        int i=0;
        while(i<s.length())
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                while(s[i]!=')')
                {
                    st.push(s[i]);
                    i++;
                    
                }
                continue;
            }
            else if(s[i]==')')
            {
                string temp="";
                while(st.top()!='(' and !st.empty())
                {
                   temp+=st.top();
                   st.pop(); 
                }
                st.pop();
                reverse(temp.begin(),temp.end());
                if(m.find(temp)==m.end())
                {
                    ans+='?';
                }
                else
                {
                    ans+=m[temp];
                }
               
            }
            else
            {
                ans+=s[i];
            }
            i++;
                
        }
        return ans;
    }
};