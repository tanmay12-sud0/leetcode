class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string s = num1;
        int i=0;
        string x1,x2,x3,x4;
        while(s[i]!='+'){
            x1 += s[i];
            i++;
        }
        i++;
        while(s[i]!='i'){
            x2 += s[i];
            i++;
        }
        i=0;
        while(num2[i]!='+'){
            x3 += num2[i];
            i++;
        }
        i++;
        while(num2[i]!='i'){
            x4 += num2[i];
            i++;
        }
        int a = stoi(x1);
        int b = stoi(x2);
        int c = stoi(x3);
        int d = stoi(x4);
        cout << a <<" " << b << " " << c << " " << d << endl;
        int first = (a*c)-(b*d);
        int second = (a*d+ b*c);
        string p = to_string(first) + "+" + to_string(second) + "i";
        
        return p;
        
    }
};