class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j=0;
	    int max_so_far = 0;
	    unordered_map<char, int>hash;
	    while(s[j] !='\0'){
		    if(hash.count(s[j]) and hash[s[j]] >= i){
			    max_so_far = max(max_so_far, j-i);
			    i = hash[s[j]]+1;
		    }else{
			    hash[s[j]] = j;
			    j++;
		    }
	    }
	    max_so_far = max(max_so_far, j-i);
	    return max_so_far;
    }
};