#include <iostream>
#include <vector>
using namespace std;

struct Tree
{
    vector<Tree*> Child;
    int value;

    Tree()
    {

    }
};

int sol = 0;
int x;
vector<Tree*> Trees;

void mola(int idx)
{
    if(idx == x) return;
    if(Trees[idx]->Child.size() == 0)
    {
        sol++;
    }
    else if(Trees[idx]->Child.size() == 1 && Trees[idx]->Child[0]->value == x)
    {
        sol++;
    }
    else
    {
        for(int i = 0; i < Trees[idx]->Child.size(); i++)
        {
            mola(Trees[idx]->Child[i]->value);
        }
    }
}

int main()
{
    // Input
    for(int i = 0; i < 51; i++)
    {
        Tree* tTree = new Tree();
        tTree->value = i;
        Trees.push_back(tTree);
    }

    int n;
    int root;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        Tree* CurTree = Trees[i];
        int p;
        cin >> p;
        if(0 <= p && p <= 50)
        {
            Trees[p]->Child.push_back(CurTree);
        }
        if(p == -1)
        {
            root = i;
        }
    }
    cin >> x;

    // Logic
    mola(root);
    cout << sol;
}