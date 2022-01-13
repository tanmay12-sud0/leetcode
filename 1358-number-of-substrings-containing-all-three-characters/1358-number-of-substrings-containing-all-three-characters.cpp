class Solution {
public:
    int numberOfSubstrings(string s) {
        // O(N) time , O(1) space [because hasmap size is always 3]
        int left = 0 , right = 0 , end = s.size() - 1;
        unordered_map<char,int> map;
        
        int count = 0;
        
        while(right != s.size())
        {
            map[s[right]] += 1; // adding new element to window
            
            while(map['a'] and map['b'] and map['c']) // while(window is good)
            {
                count += 1 + (end - right);
                
				// removing first element[means shrinking window from front to form new window]
                map[s[left]] -= 1; 
                left++;
            }
            right++;
        }
        return count;
    }
};









// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int count = 0;
//         unordered_map<char, int>hash;
//         int left = 0;
//         int right = 0;
//         int n = s.length();
//         while(right < n){
            
//             if(hash.size() == 3 and hash[s[left]]>1){
//                 // count++;
//                 while(hash.size() == 3 and hash[s[left]]>1){
//                     count++;
//                     hash[s[left]]--;
//                     if(hash[s[left]] == 0){
//                         hash.erase(s[left]);
//                     }
//                     left++;
//                 }
//             }else{
//                 hash[s[right]]++;
//                 if(hash.size() == 3){
//                     count++;
//                 }
//                 right++;
//             }
            
//         }
//         // if(hash.size() == 3){
//         //     count++;
//         // }
//         return count;
//     }
// };