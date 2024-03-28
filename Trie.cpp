#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*> childrens;
        bool isterminated;
        TrieNode(char data)
        {
            this->data = data;
            isterminated = false;

        }
};

class Trie{
    public:

        TrieNode *root;

        Trie()
        {
            root = new TrieNode('\0');
        }
};

int main()
{
    Trie *t=new Trie();

    TrieNode *curr;

    int n;
    cout << "Enter number of Word You want to add in Trie" << endl;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        string s;
        cin >> s;

        curr = t->root;

        for(auto it:s)
        {
            if(curr->childrens.find(it)==curr->childrens.end())
            {
                curr->childrens[it] = new TrieNode(it);
            }

            curr = curr->childrens[it];
        }

        curr->isterminated = true;
    }

    int m;
    cout << "Enter number of Word You Want to Search in Trie" << endl;
    cin >> m;
    

    for (int i = 0; i < m;i++)
    {
        string s;
        cin >> s;

        curr = t->root;

        int flag = 1;

        for(auto it:s)
        {
            if(curr->childrens.find(it)==curr->childrens.end())
            {
                flag = 0;
                break;
            }
            curr = curr->childrens[it];
        }

        if(flag && curr->isterminated)
        {
            cout << "Yes" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    int a;
    cout << "Enter number of Word you want to delete from trie" << endl;
    cin >> a;
    

    for (int i = 0; i < a;i++)
    {
        string s;
        cin >> s;
        curr = t->root;

        for(auto it:s)
        {
            if(curr->childrens.find(it)==curr->childrens.end())
            {
                break;
            }

            curr = curr->childrens[it];

        }

        if(curr->isterminated)
        {
            cout << "Yes Word Deleted" << endl;
            curr->isterminated = false;
        }
        else{
            cout << "Word does not Exist in Trie" << endl;
        }


    }

    int b;
    cout << "Enter number of Word You Want to Search in Trie" << endl;
    cin >> b;

    for (int i = 0; i < m;i++)
    {
        string s;
        cin >> s;

        curr = t->root;

        int flag = 1;

        for(auto it:s)
        {
            if(curr->childrens.find(it)==curr->childrens.end())
            {
                flag = 0;
                break;
            }
            curr = curr->childrens[it];
        }

        if(flag && curr->isterminated)
        {
            cout << "Yes" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }


    return 0;
}
