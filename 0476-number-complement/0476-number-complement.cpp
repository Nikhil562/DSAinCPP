class Solution {
public:
    int findComplement(int num) {
       int m=num;
        int c=0;
        while(num){
            c++;
            num>>=1;
        }
        int res=pow(2,c)-m-1;
        return res;
    }
};