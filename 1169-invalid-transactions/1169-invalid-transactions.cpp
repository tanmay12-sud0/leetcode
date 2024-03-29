class Solution {
public:
    struct CustomerDetail{
        string name;
        int time;
        int amount;
        string city;
    };
    CustomerDetail prepareCustomerObject(string s){
        vector<string>temp;
        string t;
        istringstream f(s);
        while(getline(f,t,',')){
            temp.push_back(t);
        }
        CustomerDetail obj =  CustomerDetail();
        obj.name=temp[0];
        obj.time=stoi(temp[1]);
        obj.amount=stoi(temp[2]);
        obj.city=temp[3];
        return obj;
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<bool> invalid(transactions.size());
        vector<CustomerDetail> details;
        map<string/*name*/,vector<int>/*list of indexes*/> hashmap;
        int i=0;
        for(string s: transactions) {
            CustomerDetail obj = prepareCustomerObject(s);
            invalid[i]=obj.amount>1000;
        
            if(hashmap.find(obj.name) != hashmap.end()) {
                vector<int> indexes = hashmap[obj.name];
                
                for(int ind: indexes) {
                    if(details[ind].city != obj.city && abs(obj.time-details[ind].time)<= 60) {
                        invalid[ind]=true;
                        invalid[i]=true;
                    }
                }
            }
            hashmap[obj.name].push_back(i);
            details.push_back(obj);
            i++;
        }
        vector<string> ans;
        for(i=0;i<transactions.size();i++){
            if(invalid[i])
                ans.push_back(transactions[i]);
        }
        return ans;
    }
};











// class Solution {
// public:

//     vector<string> invalidTransactions(vector<string>& transactions) {
//         vector<string>s;
//         unordered_map<string, vector<vector<string>>>hash;
//         int n = transactions.size();
//         for(int i=0; i<n; i++){
//             string a = transactions[i];
//             string pp;
//             string name;
//             string city;
//             string time;
//             string money;
//             int count = 0;
//             for(int j=0; j<a.length(); j++){
//                 if(a[j] == ',' and count == 0){
//                     name = pp;
//                     pp = "";
//                     count = 1;
//                 }
//                 else if(a[j] == ',' and count == 1){
//                     time = pp.substr(1);
//                     pp = "";
//                     count = 2;
//                 }
//                 else if(a[j] == ',' and count == 2){
//                     money = (pp.substr(1));
//                     pp = "";
//                     count = 3;
//                 }
//                 pp += a[j];
//             }
//             city = pp.substr(1);
//             pp.clear();
//             if(money <= "1000"){
//                 if(hash.count(name)){
//                     string t = hash[name][1];
//                     cout << t << endl;
//                     if(abs(stoi(time)-stoi(t))>60){
//                         // vector<string>s{money, time, city};
//                         hash[name].push_back({money, time, city});
//                     }
//                 }
//                 else{
//                     vector<string>s{money, time, city};
//                     hash[name] = s;
//                 }
//             }
//         }
//         for(auto x : hash){
//             string p = x.first+","+x.second[1]+","+x.second[0]+","+x.second[2];
//             s.push_back(p);
//             p.clear();
//         }

//          return s;
//     }
// };