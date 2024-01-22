class Solution {
public:
   vector<int> findErrorNums(vector<int>& nums) {

	int n = nums.size();
//missing el:- 1-n (xor) X (nums[0]-nums[n-1])//
	// Sorting Array.
	sort(nums.begin(), nums.end());

	// Creating output vector.
	vector<int> res(2);

	// Storing XOR of unique numbers in array.
	int xorOfArray = nums[0];

	// Storing XOR of integers from 1 to N.
	int xorUptoN = n;

	// If XOR of any two numbers in the array is zero i.e. they are same.
	// Else we would store them this would remove duplicate element in our XOR.
	for (int i = 1; i < n; i++) {
		if ((nums[i - 1] ^ nums[i]) == 0) res[0] = nums[i];
		else xorOfArray ^= nums[i];
		xorUptoN ^= i;
	}

	// We could see that the difference in both of these XORs would be the element missing.
	res[1] = xorUptoN ^ xorOfArray;

	return res;
}               
};