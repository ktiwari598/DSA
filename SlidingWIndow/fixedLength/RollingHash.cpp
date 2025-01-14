//
// Created by Karan Tiwari on 14/01/25.
//
int mod = 5381;

int powerM(int x, int y, int mod) {
    if(y == 0) return 1;
    int temp = powerM(x, y/2, mod);
    if(y & 1) {
        return ((temp * temp)%mod * x)%mod;
    }
    return (temp * temp)%mod;
}

int getHash(string str) {
    int hash = 0;
    for(int i=0;i<str.length();i++) {
        hash = (hash +  (str[i] - 'a' + 1) * powerM(26, str.length()-i-1, mod))%mod;
    }
    return hash;
}

//Rolling Hash
// Hash+= (s[i] -'a' + 1) * pow(26, s.length()-i-1);
// For eg. s = "abcdef"
// i = 3, s[i] = 'd'
// Hash+= (4 * pow(26, 2))

int strStr(string haystack, string needle) {
    int patternHash = getHash(needle);
    int n = needle.length();
    int h = powerM(26, n-1, mod);
    string str = haystack.substr(0, n);
    int hash = getHash(str);
    if(patternHash == hash) return 0;
    int j = 0;
    for(int i=n;i<haystack.length();i++) {
        int temp = (hash - ((haystack[j++]-'a' + 1) * h)%mod + mod)%mod;
        hash = ((26 * temp)%mod + (haystack[i] - 'a' + 1))%mod;
        if(patternHash == hash) return j;
    }
    return -1;
}