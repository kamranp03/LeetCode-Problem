class Solution {
public:
    bool isVowel(char c)
    {
        string vowel="aeiouAEIOU";
        return vowel.contains(c);
    }
    string sortVowels(string s) {
        string vowel;

        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
                vowel+=s[i];
        }

    sort(vowel.begin(),vowel.end());


        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                s[i]=vowel[j];
                j++;
            }
        }

        return s;
    }
};