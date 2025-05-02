// 14426 접두사 찾기
// Trie 알고리즘

#include <iostream>
#include <cstring>

using namespace std;

struct Trie
{
    bool finish;
    Trie* next[26];

    Trie() : finish(false)
    {
        memset(next, 0, sizeof(next));
    }

    ~Trie()
    {
        for(int i = 0; i < 26; i++)
        {
            if(next[i])
                delete next[i];
        }
    }

    void insert(const char* key)
    {
        if(*key == '\0')
            finish = true;
        else
        {
            int curr = *key - 'a';
            if(next[curr] == NULL)
            {
                next[curr] = new Trie();
            }
            next[curr]->insert(key + 1);
        }
    }

    Trie* find(const char* key)
    {
        if(*key == '\0') return this;
        int curr = *key - 'a';
        if(next[curr] == NULL) return NULL;
        return next[curr]->find(key+1);
    }
};

int main()
{
    Trie Tri;

    int n, m;
    int sol = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        char str[550];
        cin >> str;
        Tri.insert(str);
    }

    for(int i = 0; i < m; i++)
    {
        char str[550];
        cin >> str;
        if(Tri.find(str) != NULL)
        {
            sol++;
        }
    }

    cout << sol;
}