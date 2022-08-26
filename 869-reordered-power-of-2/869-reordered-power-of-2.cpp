class Solution {
public:
    bool check(unordered_map<int, int> hashN, unordered_map<int, int> hashPow){
        for(auto p: hashN){
            if(!hashPow.count(p.first) || hashPow[p.first] != p.second) return false;
        }
        for(auto p: hashPow){
            if(!hashN.count(p.first) || hashN[p.first] != p.second) return false;
        }
        return true;
    }
    
    unordered_map<int, int> genMap(int n){
        unordered_map<int, int> ump;
        
        while(n != 0){
            ump[n%10]++;
            n/=10;
        }
        
        return ump;
    }
    bool reorderedPowerOf2(int n) {
        unordered_map<int, int> hashN = genMap(n);
        
        for(int i = 1; i <= 1e9; i *= 2){
            unordered_map<int, int> hashPow = genMap(i);
            if(check(hashN, hashPow)) return true;
        }
        
        return false;
    }
};