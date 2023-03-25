
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
//         intution:- we have 2 array and for each element we have to xor it with another array, and then xor all numbers so we finaly have each element that will be xor'ed to it self in the given number of another array.
// now lets understand it with ex:-

// example
// lets say we have array [a,b] and [c,d,e] so according to question:

// we will have numbers a^c , a^d, a^e, b^c, b^d , b^e;
// final number will be a^c ^ a^d ^ a^e ^b^c^ b^d ^ b^e;
// if we try to see pattern here a comes 3 times ,b 3 times c 2 times d 2 times and e 2 times which is nothing but the number of other array.

// and by xor property we know if we xor any number to self even times it will become 0 or if we do odd times it will become itself

// so now problem reduce to find the xor of all element in the array which have odd length which we can solve.
        int n1=nums1.size();
        int n2=nums2.size();
        int ans=0;
        if(n2&1) {
            for(auto i: nums1) ans^=i;
        }
        if(n1&1){
            for(auto i: nums2) ans^=i;
        }
        return ans;
    }
};