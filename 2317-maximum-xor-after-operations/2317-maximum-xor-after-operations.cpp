/*
Let's establish first that n & (n ^ x) can be used to turn off a bit

Let's say n is 0101 and we want to turn off the 2nd idx bit

1. We choose x = 0100 and take xor with it. We get 0001. This is what we wanted
2. Then we & it with n to get 0001 i.e. the number of 1s do not change because bitwise and does not increase the number of 1s. They either remain same or reduce

So we have established that n & (n ^ x) can be used to only turn off a bit

Now, lets say we have the following numbers
011
010
001

The maximum xor is 011 when we turn off one set bit in both 0th and 1st column. This we can do with the above operation.

So, at the end we only want to check which columns have atleast one set bit. This can be done by just ORing the numbers. If a column has no set bit, we cannot fo anything. If it has even set bits, we can reduce one set bit to make it odd. If we already have odd number of set bits, we don't do anything
*/
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        
        for(int num: nums) ans |= num;
        
        return ans;
    }
};