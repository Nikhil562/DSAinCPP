class Solution {
public:

int binaryGap(int n) {
    int v=__builtin_popcount(n);
    if(v<=1) return 0;
    int c=0,res=0;
    while((n&1)==0) n=n>>1;

    while(n){
        if(n&1==1){
            res=max(res,c+1);
            c=0;
        }else{
            c++;
        }
        n=n>>1;
        //cout<<c<<" ";
    }
    return res;
}
};