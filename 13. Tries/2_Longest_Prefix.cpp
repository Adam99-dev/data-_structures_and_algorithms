

// Problem Link: https://www.naukri.com/code360/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

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

    // Longest Common Prefix using Trie
    string getLCP(string first){
        string ans = "";
        TrieNode* temp = root;

        for(int i=0 ; i<first.length() ; i++){
            char ch = first[i];
            int index = ch - 'a';

            // count children
            int count = 0;
            for(int j=0 ; j<26 ; j++){
                if(temp->children[j] != NULL){
                    count++;
                }
            }

            // if only one child and not terminal
            if(count == 1 && temp->isTerminal == false){
                ans.push_back(ch);
                temp = temp->children[index];
            }
            else{
                break;
            }
        }

        return ans;
    }
};

string longestCommonPrefix(vector<string> &arr, int n){
    Trie t;

    // insert all words
    for(int i=0 ; i<n ; i++){
        t.insertWord(arr[i]);
    }

    // take first string to compare
    return t.getLCP(arr[0]);
}

int main(){
    vector<string> arr = {"flower", "flow", "flight"};
    int n = arr.size();

    cout << "Longest Common Prefix: " 
         << longestCommonPrefix(arr, n) << endl;

    return 0;
}