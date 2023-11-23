class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        unsigned n=num;
        string res;
        char digits[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        while(n>0){
            res=(digits[n%16])+res;
            n/=16;
        }
        return res;
    }
};
string toHex(int num) {
        
        if(num == 0) return "0";
        
        string res;
        unsigned int n = num;
        char digits[] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'a','b', 'c', 'd', 'e', 'f'};
        
        while(n > 0)
        {
            res = (digits[n%16]) + res;
            n /= 16;
        }
        
        return res;
    }