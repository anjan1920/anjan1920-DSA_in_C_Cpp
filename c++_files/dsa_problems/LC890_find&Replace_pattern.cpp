#include<iostream>
#include<string>
#include<vector>

using namespace std;

//map the pattern and return the mapped version
string find_mapped(string pattern){
    //map the pattern
    char map_ch[300] = {0};
    char start = 'a';

    for(int i = 0 ;i < pattern.size(); i++){
        char idx = pattern[i];

        if(map_ch[idx] == 0 && map_ch[idx] != ' '){
            //assign the char
            map_ch[idx] = start;
            start++;
        }
    }

    //now return the mapped string
    string ans;
    for(int i = 0 ; i < pattern.size(); i++){
        char ch = pattern[i];
        if(ch == ' '){
            ans.push_back(' ');
        }else{
            //push the mapped character
            ans.push_back(map_ch[ch]);
        }
    }
    return ans;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    //first find the map of the pattern
    string mapped_pattern = find_mapped(pattern);

    //now for each vector string i.e words find the mapped words
    //and if both mapped_pattern & word_mapped are same push to ans
    vector<string> ans;
    for(int idx = 0 ; idx < words.size(); idx++ ){
        string word = words[idx];
        string word_mapped = find_mapped(word);
        if(mapped_pattern == word_mapped){
            ans.push_back(word);
        }
    }

    return ans;
}

int main(){
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector<string> ans = findAndReplacePattern(words, pattern);

    //print the result
    for(string s : ans){
        cout << s << " ";
    }
}
