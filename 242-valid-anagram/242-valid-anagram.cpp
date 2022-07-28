class Solution {
public:
    bool isAnagram(string s, string t) {
        string s1 = s; 
        sort(s1.begin(), s1.end());
        string s2 = t;
        sort(s2.begin(), s2.end());
        
        return s1 == s2;
    }
};