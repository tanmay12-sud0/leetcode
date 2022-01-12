class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        if(bills[0] != 5){
            return false;
        }
        int count5 = 0;
        int count10 = 0;
        int count20 = 0;
        for(int i=0; i<n; i++){
            if(bills[i]==5){
                count5++;
            }else{
                int x = bills[i]-5;
                if(x == 5 and count5>0){
                    count10++;
                    count5--;
                }
                else if(x == 15 and count10>=1 and count5>=1){
                    count5--;
                    count10--;
                    count20++;
                }else if(x == 15 and count5 >= 3){
                    count20++;
                    count5-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};