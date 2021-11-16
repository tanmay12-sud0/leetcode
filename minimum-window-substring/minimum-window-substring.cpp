class Solution {
public:
    string minWindow(string s, string t) {
        int FP[256] = {0};
	int FS[256] = {0};

	for(int i=0; i<t.length(); i++){
		FP[t[i]]++;
	}

	int cnt = 0;
	int start = 0;
	int start_idx = -1;
	int min_so_far = INT_MAX;
	int window_size = -1;



	for(int i=0; i<s.length(); i++){
		char ch = s[i];
		FS[ch]++;

		if(FP[ch]!=0 and FS[ch] <= FP[ch]){
			cnt++;
		}
		if(cnt == t.length()){
			while(FP[s[start]]==0 or FS[s[start]] > FP[s[start]]){
				FS[s[start]]--;
				start++;
			}
			int window_size = i-start+1;
			if(window_size < min_so_far){
				min_so_far = window_size;
				start_idx = start;
			}
		}
		

	}

	if(start_idx != -1){
		return s.substr(start_idx, min_so_far);
	}
    return "";
    }
};