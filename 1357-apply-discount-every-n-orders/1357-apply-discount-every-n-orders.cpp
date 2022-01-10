class Cashier {
public:
    unordered_map<int, int>hash;
    int N;
    int Discount;
    int cnt = 0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        Discount = discount;
        N = n;
        for(int i=0; i<products.size(); i++){
            hash[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bill = 0.0;
        cnt++;
        for(int i=0; i<product.size(); i++){
            bill += amount[i]*hash[product[i]];
        }
        if(cnt%N==0){
            bill = bill*double(100-Discount)/100.00;
        }
        return bill;
    }
};
