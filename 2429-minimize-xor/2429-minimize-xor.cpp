class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = 0;
        while(num2) {
            count += num2&1;
            num2>>=1;
        }
        int x = 0;
        for(int i=31;i>=0 && count;i--) {
            int temp = 1<<i;
            if(num1&temp) {
                x |= temp;
                count--;
            }
        }
        // cout<<x<<" "<<count<<"\n";
        for(int i=0;i<32 && count; i++) {
            int temp = 1<<i;
            // cout<<temp<<"\n";
            if((x&temp) == 0) {
                // cout<<temp<<" "<<count<<"\n";
                x |= temp;
                count--;
            }
        }
        return x;
    }
};