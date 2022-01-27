class Solution {
public:
    string pushDominoes(string dominoes) {

	int n=dominoes.size();
	vector<int> left(n);
	vector<int> right(n);

	int k=-1;
	for(int i=0;i<n;i++){
		if(dominoes[i]=='R')
			k=0;
		else if(dominoes[i]=='.' && k>=0)
			k++;
		else
			k=-1;

		right[i]=k;
	}

	 for(int i=n-1;i>=0;i--){
		if(dominoes[i]=='L')
			k=0;
		else if(dominoes[i]=='.' && k>=0)
			k++;
		else
			k=-1;

		left[i]=k;
	}
	string ans="";

	for(int i=0;i<n;i++){
	  if(left[i]==-1 && right[i]==-1)
		  ans.push_back('.');
	  else if(left[i]==-1)  
		  ans.push_back('R');
	  else if(right[i]==-1)  
		  ans.push_back('L');
	  else if(right[i]<left[i])
		  ans.push_back('R');
	  else if(right[i]>left[i])
		  ans.push_back('L');
	  else if(right[i]==left[i])
		  ans.push_back('.');  
	}

	return ans;
}
    
};




// string pushDominoes(string dominoes) {
//         int n = dominoes.length();
//         vector<int>left(n, INT_MAX);
//         vector<int>right(n, INT_MAX);
//         right[0] = dominoes[0] == 'R' ? 0 : INT_MAX;
//         left[n-1] = dominoes[n-1] == 'L' ? 0 : INT_MAX;
//         for(int i=1; i<n; i++){
//             if(dominoes[i] == 'R'){
//                 right[i] = 0;
//             }
//             else if(dominoes[i] == 'L'){
//                 right[i] = INT_MAX;
//             }
//             else{
//                 if(right[i-1]!=INT_MAX){
//                     right[i] = right[i-1]+1;
//                 }
//             }
//         }
//         for(int i=n-2; i>=0; i--){
//             if(dominoes[i] == 'L'){
//                 left[i] = 0;
//             }
//             else if(dominoes[i] == 'R'){
//                 left[i] = INT_MAX;
//             }
//             else{
//                 if(left[i+1]!=INT_MAX){
//                     left[i] = left[i+1]+1;
//                 }
//             }
//         }
//         string ss;
//         for(int i=0; i<n; i++){
//             if(left[i] == right[i]){
//                 ss += '.';
//             }else{
//                 if(right[i]<left[i]){
//                     ss += 'R';
//                 }else{
//                     ss += 'L';
//                 }
//             }
//         }
        
//         return ss;