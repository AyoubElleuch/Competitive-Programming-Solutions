class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2 == 1) return false;

        int min = 0, max = 0;

        for(int i=0; i<s.size(); i++){
            if(locked[i] == '1'){
                if(s[i] == '('){
                    min++; max++;
                }else{
                    min--; max--;
                }
            }else{
                min--; max++;
            }

            if(max<0) return false;
            min = min<0? 0:min;
        }

        if(min == 0) return true;
        return false;
    }
};