#include <iostream>
#include <vector>
using namespace std;

int n, r, q;

struct Node
{
    int idx;
    vector<Node*> childs;
};

vector<int> inputs[100001];
int dp[100001];


int findChild(Node* node)
{
    if(dp[node->idx] == 0)
    {
        int childsNum = 1;

        for(auto child : node->childs)
        {
            childsNum += findChild(child);
        }

        dp[node->idx] = childsNum;
    } 

    return dp[node->idx];
}

void makeTree(Node* current, int parent)
{
    for(int child : inputs[current->idx])
    {
        if(child != parent)
        {
            Node* tNode = new Node();
            tNode->idx = child;
            makeTree(tNode, current->idx);
            current->childs.push_back(tNode);
        }
    }

}

int main()
{  
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> r >> q;

    for(int i = 0; i < n-1; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        inputs[t1].push_back(t2);
        inputs[t2].push_back(t1);
    }

    Node* rootNode = new Node();
    rootNode->idx = r;

    makeTree(rootNode, -1);

    findChild(rootNode);
    
    for(int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        cout << dp[t] << "\n";
    }
}