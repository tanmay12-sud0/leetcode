class Solution {
public:
    
    string findDifferentBinaryString(vector<string>& nums) {
	  // to store the numbers and compare in constant time
	  unordered_set<string> s;
	  
	  // insert entire input into set
        for (auto num : nums)
        {
            s.insert(num);
        }

       // check one by one from 0 to 2^n
        for (int i = 0; i < pow(2, nums.size()); i++)
        {
			// convert to binary and only take last digits (equal to length of vector)
            string binary = std::bitset<16>(i).to_string();
            binary = binary.substr(16 - nums.size(), nums.size());
           
		   // if does not exist, then return
            if (s.find(binary) == s.end())
            {
                return binary;
            }
        }

		// consistent return for compiler
        string f = "--";
        return f;
    }
};



// class Solution {
// public:
    
//     int binaryToDecimal(int n)
// {
//     int num = n;
//     int dec_value = 0;
 
//     int base = 1;
 
//     int temp = num;
//     while (temp) {
//         int last_digit = temp % 10;
//         temp = temp / 10;
 
//         dec_value += last_digit * base;
 
//         base = base * 2;
//     }
 
//     return dec_value;
// }
    
    
//     string decToBinary(int n)
// {
//     // array to store binary number
//     int binaryNum[32];
 
//     // counter for binary array
//     int i = 0;
//     while (n > 0) {
 
//         // storing remainder in binary array
//         binaryNum[i] = n % 2;
//         n = n / 2;
//         i++;
//     }
//     string s;
//     // printing binary array in reverse order
//     for (int j = i - 1; j >= 0; j--)
//         s += to_string(binaryNum[j]);
    
//         return s;
// }
    
    
    
//     string findDifferentBinaryString(vector<string>& nums) {
//         int len = nums[0].length();
//         unordered_map<int, int>hash;
//         for(int i=0; i<nums.size(); i++){
//             hash[binaryToDecimal(stoi(nums[i]))]++;
//         }
//         for(int i=0; i<=(pow(2,len)-1); i++){
//             if(!hash.count(i)){
//                 if(i == 0){
//                     string tan = "";
//                     for(int i=0; i<len; i++){
//                         tan += "0";
//                     }
//                     return tan;
//                 }
//                 if(decToBinary(i).lenght == len){
//                     return decToBinary(i);
//                 }
//                 return ();
//             }
//         }
//         return "";
//     }
// };