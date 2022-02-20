#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p2w = {};
        unordered_map<string, char> w2p = {};
        string tmp = "";
        string tmp2 = "";
        int start = 0;
        int nouw = 0;
        for(int i = 0; i <= s.size(); i++)
        {
            if(s[i] != ' ' && i != s.size())
            {
                continue;
            }
            tmp = s.substr(start, i - start);
            start = i + 1;

            if(p2w.find(pattern[nouw]) == p2w.end() && w2p.find(tmp) == w2p.end())
            {
                p2w[pattern[nouw]] = tmp;
                w2p[tmp] = pattern[nouw];
                nouw++;
                continue;
            }
            if(p2w.find(pattern[nouw]) == p2w.end() || w2p.find(tmp) == w2p.end())
            {
                return false;
            }
            if(p2w[pattern[nouw]] != tmp)
            {
                return false;
            }
            nouw++;
        }
        if(nouw != pattern.size())
        {
            return false;
        }
        return true;
    }
};
