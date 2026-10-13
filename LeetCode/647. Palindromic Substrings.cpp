class Solution {
public:
    int countSubstrings(string s) {
        int palindroms = s.size();
        
        for(int i=0; i<s.size(); i++){
            int j = i-1;
            int k = i+1;
            
            while(j>=0 && k<s.size() && s[j] == s[k]){
                palindroms++;
                j--;
                k++;
            }

            j = i-1;
            k = i;

            while(j>=0 && k<s.size() && s[j] == s[k]){
                palindroms++;
                j--;
                k++;
            }
        }

        return palindroms;
    }
};