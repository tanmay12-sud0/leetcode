class Solution {
public:
    int firstUniqChar(string s) {
     
        queue<pair<char, int>>q;
	    int freq[27]={0};

	    for(int i=0; s[i]!='\0'; i++){
		q.push(make_pair(s[i], i));
		int idx = s[i]-'a';
		freq[idx]++;
	}	

	while(!q.empty()){
			pair<char, int> f = q.front();
			// q.pop();
			int idx = f.first-'a';
			if(freq[idx] > 1){
				q.pop();
				// freq[idx]--;
			}else{
				return f.second ;
				
			}
	}
	if(q.empty()){
		return -1;
	}
    return -1;
    }
};