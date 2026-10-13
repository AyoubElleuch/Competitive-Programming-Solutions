class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> validParenthesis;
        
        findValidParenthesis(validParenthesis, n, 0, 0, "");

        return validParenthesis;
    }

    void findValidParenthesis(vector<string>& validParenthesis, int n, int left, int right, string s){
        if(left == right && left == n) validParenthesis.push_back(s);

        if(left < n && left >= right){
            s += '(';
            findValidParenthesis(validParenthesis, n, left+1, right, s);
            s.pop_back();
        }

        if(right < left && right < n){
            s+= ')';
            findValidParenthesis(validParenthesis, n, left, right+1, s);
            s.pop_back();
        }
    }
};