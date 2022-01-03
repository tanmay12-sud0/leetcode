class Solution {
public:
    string solveEquation(string equation) {
        int i =0;
        int para=0, xpara=0;
        int flag = 1;
        while(i<equation.size())
        {
            int sign = 1;
            int temp = 0;
            if(equation[i] == '=') 
            {
                flag = -1;
                i++;
            }
            if(equation[i] == '-') 
            {
                sign = -1; 
                i++;
            }
            if(equation[i] == '+') 
            {
                sign = 1;
                i++;
            }
            
            if(isdigit(equation[i]))
            {
                while(i<equation.size() && isdigit(equation[i]))
                {
                    temp = temp*10 + equation[i]-'0';
                    i++;
                }
                if(i< equation.size() && equation[i] == 'x')
                {
                    xpara += flag*sign*temp;
                    i++;
                } 
                else 
                    para += flag*sign*temp;
            } 
            else //x
            {
                xpara += flag*sign;
                i++;
            }
            
        }
        string res;
        //cout<<para<<", "<<xpara<<endl;
        if(para == 0 && xpara == 0) 
            res = "Infinite solutions";
        else if(xpara == 0) 
            res = "No solution";
        else
            res = "x="+to_string(para/xpara*-1);
        return res;
    }
};









// class Solution {
// public:
    
//     string solve(string s) {
//         int n = s.length();
//         int leftValue = 0;
//         int rightValue = 0;
//         int leftX = 0;
//         int rightX = 0;
//         bool flag = false;
//         for(int i=0; i<n; i++){
//             if(s[i] == '='){
//                 flag = true;
//                 continue;
//             }
//             if(!flag){
//                 if((i-1>=0 and s[i-1]=='+' and s[i] == 'x')or(i-1<0)){
//                     leftX++;
//                 }
//                 if(i-1>=0 and s[i-1]=='-' and s[i] == 'x'){
//                     leftX--;
//                 }

//                 if((i-1>=0 and s[i-1]=='+' and s[i]>='1' and s[i]<='9' )or(i-1<0 and  s[i]>='1' and s[i]<='9')){
//                     // cout << s[i] <<"first " <<  endl;
//                     leftValue += (s[i]-'0');
//                 }
//                 if((i-1>=0 and s[i-1]=='-' and s[i]>='1' and s[i]<='9' )){
//                     // cout << s[i] <<"second " <<  endl;
//                     leftValue -= (s[i]-'0');
//                 }
//             }
//             if(flag){
//                 if((i-1>=0 and s[i-1]=='+' and s[i] == 'x')or(s[i-1] == '=' and s[i]=='x')){
//                     rightX++;
//                 }
//                 if(i-1>=0 and s[i-1]=='-' and s[i] == 'x'){
//                     rightX--;
//                 }

//                 if((i-1>=0 and s[i-1]=='=' and s[i]>='1' and s[i]<='9' )or(s[i-1]=='+' and s[i]>='1' and s[i]<='9')){
//                     rightValue += (s[i]-'0');
//                 }
//                 if((i-1>=0 and s[i-1]=='-' and s[i]>='1' and s[i]<='9' )){
//                     rightValue -= (s[i]-'0');
//                 }
//             }
//         }
//         cout << leftValue << ", " << rightValue << ", " << leftX << ", " << rightX <<  endl;
        
//         if(leftX == rightX and leftValue==0 and rightValue==0){
//             return "Infinite solutions";
//         }
//         if(leftX == rightX and (leftValue==0 or rightValue==0)){
//             return "x=0";
//         }
//         if(leftX>=rightX){
//             string s = to_string(leftX-rightX)=='1' ? "x" : to_string(leftX-rightX)+"x"; 
//                 s += "=" + to_string(rightValue-leftValue);
//             return s;
//         }else{
//             string s = to_string(rightX-leftX) + "=" + to_string(leftValue-rightValue);
//             return s;
//         }
        
//         return "tan";
//      }

    
    
    
//     string solveEquation(string equation) {
//         return solve(equation);
//     }
// };