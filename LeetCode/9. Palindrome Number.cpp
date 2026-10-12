class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 ) return false;

        int temp = x;
        int reversed_x = 0;

        while(temp > 0) {
            int digit = temp % 10;
            if (reversed_x > (INT_MAX - digit) / 10) return false;
            reversed_x = reversed_x * 10 + digit;
            temp = temp / 10;
        }
        
        return x == reversed_x;
    }
};