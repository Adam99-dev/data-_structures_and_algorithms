// Problem Link: https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM


#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    char data;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(char ch){
        data = ch;
        for(int i=0 ; i<26 ; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(string word){
        TrieNode* temp = root;
        for(int i=0 ; i<word.length() ; i++){
            char ch = word[i];
            int index = ch - 'a';

            if(temp->children[index] == NULL){
                temp->children[index] = new TrieNode(ch);
            }
            temp = temp->children[index];
        }
        temp->isTerminal = true;
    }

    void printSuggestions(vector<string> &temp, TrieNode* curr, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a' ; ch <= 'z' ; ch++){
            TrieNode* next = curr->children[ch - 'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(temp, next, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string queryStr){
        vector<vector<string>> output;
        TrieNode* prev = root;
        string prefix = "";

        for(int i=0 ; i<queryStr.length() ; i++){
            char lastChar = queryStr[i];
            prefix.push_back(lastChar);

            TrieNode *curr = prev->children[lastChar - 'a'];

            if(curr == NULL){
                break;
            }

            vector<string> temp;
            printSuggestions(temp, curr, prefix);
            output.push_back(temp);

            prev = curr;
        }

        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string &queryStr){
    Trie* t = new Trie();

    for(int i=0 ; i<contactList.size() ; i++){
        t->insertWord(contactList[i]);
    }

    return t->getSuggestions(queryStr);
}

// 🔥 MAIN FUNCTION (Test Cases)
int main(){
    vector<string> contacts = {
        "alice", "ali", "bob", "bobby", "alex", "albert"
    };

    string query = "al";

    vector<vector<string>> result = phoneDirectory(contacts, query);

    // Output
    for(int i = 0; i < result.size(); i++){
        cout << "Suggestions for prefix \"" 
             << query.substr(0, i+1) << "\":\n";

        for(auto word : result[i]){
            cout << word << " ";
        }
        cout << "\n\n";
    }

    return 0;
}