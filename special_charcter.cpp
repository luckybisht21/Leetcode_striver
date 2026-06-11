class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>lower,upper;
        for(int i=0;i<word.size();i++){
            if(islower(word[i])) lower[word[i]]++;
            else upper[word[i]]++;
            
        }int count =0;
        for( char c='a';c<='z';c++){
            if(lower.count(c) && upper.count(toupper(c))) count++;
        }
        return count;
        
    }
};