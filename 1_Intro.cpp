#include <iostream>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode *childen[26];
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            childen[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(string word){
        TrieNode *temp = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            int index = ch - 'a';
            if(temp->childen[index] == NULL){
                TrieNode *newNode = new TrieNode(ch);
                temp->childen[index] = newNode;
            }
            temp = temp->childen[index];
        }
        temp->isTerminal = true;
    }

    bool searchWord(string word){
        TrieNode *temp = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            int index = ch - 'a';
            if(temp->childen[index] == NULL){
                return false;
            }
            temp = temp->childen[index];
        }
        return temp->isTerminal;
    }

    void deleteWord(string word){
        TrieNode *temp = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            int index = ch - 'a';
            if(temp->childen[index] == NULL){
                return;
            }
            temp = temp->childen[index];
        }
        temp->isTerminal = false;
    }
};

int main(){

    Trie *t = new Trie();
    t->insertWord("app");
    (t->searchWord("ap")) ? cout << "Present" << endl : cout << "Not Present" << endl;
    (t->searchWord("app")) ? cout << "Present" << endl : cout << "Not Present" << endl;
    t->deleteWord("app");
    (t->searchWord("app")) ? cout << "Present" << endl : cout << "Not Present" << endl;
    return 0;
}