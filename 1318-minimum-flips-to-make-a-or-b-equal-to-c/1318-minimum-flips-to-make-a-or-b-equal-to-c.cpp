class Solution {
public:
    int minFlips(int a, int b, int c) {
        // int m = a | b;
//         int r = 0;
        
//         for (int i = 0; i < sizeof(c)*8-1; ++i)
//         {
//             int s = 1 << i;
//             if ((m & s) != (c & s))
//             {
//                 if ((a & s) && (b & s))
//                     r += 2;
//                 else
//                     ++r;
//             }
//         }
//         return r;
        
        int m=a|b;
        int x=0;
        for(int i=0;i<sizeof(x)*8-1;i++){
            int t=1<<i;
            if((m&t)!=(c&t)){
                if((a&t) && (b&t)){
                    x+=2;
                }
                else x++;
            }
        }
        return x;
    }
};