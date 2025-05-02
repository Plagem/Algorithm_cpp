#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<vector<string>>> num = {
    {
        {"#", "#", "#"},
        {"#", "*", "#"},
        {"#", "*", "#"},
        {"#", "*", "#"},
        {"#", "#", "#"}
    },
    {
        {"*", "*", "#"},
        {"*", "*", "#"},
        {"*", "*", "#"},
        {"*", "*", "#"},
        {"*", "*", "#"}
    },
    {
        {"#", "#", "#"},
        {"*", "*", "#"},
        {"#", "#", "#"},
        {"#", "*", "*"},
        {"#", "#", "#"}
    },
    {
        {"#", "#", "#"},
        {"*", "*", "#"},
        {"#", "#", "#"},
        {"*", "*", "#"},
        {"#", "#", "#"}
    },
    {
        {"#", "*", "#"},
        {"#", "*", "#"},
        {"#", "#", "#"},
        {"*", "*", "#"},
        {"*", "*", "#"}
    },
    {
        {"#", "#", "#"},
        {"#", "*", "*"},
        {"#", "#", "#"},
        {"*", "*", "#"},
        {"#", "#", "#"}
    },
    {
        {"#", "#", "#"},
        {"#", "*", "*"},
        {"#", "#", "#"},
        {"#", "*", "#"},
        {"#", "#", "#"}
    },
    {
        {"#", "#", "#"},
        {"*", "*", "#"},
        {"*", "*", "#"},
        {"*", "*", "#"},
        {"*", "*", "#"}
    },
    {
        {"#", "#", "#"},
        {"#", "*", "#"},
        {"#", "#", "#"},
        {"#", "*", "#"},
        {"#", "#", "#"}
    },
    {
        {"#", "#", "#"},
        {"#", "*", "#"},
        {"#", "#", "#"},
        {"*", "*", "#"},
        {"#", "#", "#"}
    },
};

bool compare (vector<vector<string>> org, vector<vector<string>> comp) { // 둘 다 arr[5][3] 형태이다.
    for(int row = 0; row < 5; row++) {
        for (int column = 0; column < 3; column++) {
            if ((org[row][column] == "#") && (comp[row][column] == "*"))
                return false;
        }
    }
    return true;
}

int main () {
    vector<vector<string>> tcomp;
    vector<vector<vector<string>>> comp;
    int N;
    cin >> N;
    for(int i = 0; i < 5; i++) {
        string temp;
        vector<string> vtemp;
        cin >> temp;
        for(int j = 0; j < 4*N-1; j++) {
            string st(1, temp[j]);
            vtemp.push_back(st);
        }
        tcomp.push_back(vtemp);
    }

    for(int i = 0; i < N; i++) {
        vector<vector<string>> tempnum;
        for(int j = 0; j < 5 ; j++) {
            
        }
    }
}