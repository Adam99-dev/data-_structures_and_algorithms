

// Problem Link: https://www.naukri.com/code360/problems/implement-trie_631356?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    // Insert
    void insert(string word)
    {
        TrieNode *temp = root;

        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            int index = ch - 'a';

            if (temp->children[index] == NULL)
            {
                temp->children[index] = new TrieNode(ch);
            }

            temp = temp->children[index];
        }

        temp->isTerminal = true;
    }

    // Search full word
    bool search(string word)
    {
        TrieNode *temp = root;

        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            int index = ch - 'a';

            if (temp->children[index] == NULL)
            {
                return false;
            }

            temp = temp->children[index];
        }

        return temp->isTerminal;
    }

    // Prefix search
    bool startsWith(string prefix)
    {
        TrieNode *temp = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            char ch = prefix[i];
            int index = ch - 'a';

            if (temp->children[index] == NULL)
            {
                return false;
            }

            temp = temp->children[index];
        }

        return true;
    }

    void deleteWord(string word)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            int index = ch - 'a';
            if (temp->children[index] == NULL)
            {
                return;
            }
            temp = temp->children[index];
        }
        temp->isTerminal = false;
    }
};

int main()
{
    Trie t;

    t.insert("apple");
    t.insert("app");

    cout << "Search apple: " << t.search("apple") << endl; // 1
    cout << "Search app: " << t.search("app") << endl;     // 1
    cout << "Search ap: " << t.search("ap") << endl;       // 0

    cout << "StartsWith ap: " << t.startsWith("ap") << endl; // 1
    cout << "StartsWith ba: " << t.startsWith("ba") << endl; // 0
    
    t.deleteWord("app");
    return 0;
}