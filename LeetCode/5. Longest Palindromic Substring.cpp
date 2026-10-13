class Solution {
public:
    string longestPalindrome(string s) {
        string largestSubstring = "";
        int largestSize = 0, start = 0;

        for(int i=0; i < s.size(); i++){
            int j = i-1;
            int k = i+1;

            while(j >= 0 && k < s.size() && s[j] == s[k]){
                j--; k++;
            }

            int length = k - j - 1;
            if(length > largestSize){
                start = j + 1;
                largestSize = length;
            }

            j = i-1;
            k = i;

            while(j >= 0 && k < s.size() && s[j] == s[k]){
                j--; k++;
            }
            
            length = k - j - 1;
            if(length > largestSize){
                start = j + 1;
                largestSize = length;
            }
        }

        return s.substr(start, largestSize);
    }
};