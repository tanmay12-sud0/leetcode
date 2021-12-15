class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int ans = 0;
        int end = letters.size();
        while(start <= end){
            int mid = (start+end)/2;
            if(letters[mid] > target){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return letters[ans];
    }
};