class Solution {
public:
    bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
    int c=0;
    int countPrimeSetBits(int left, int right) {
        for(int i=left;i<right+1;i++){
            int b=__builtin_popcount(i);
            if(isPrime(b)) c++;
        }
        return c;
    }
};