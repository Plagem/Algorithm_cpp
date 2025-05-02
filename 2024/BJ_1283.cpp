#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::vector<std::string> keys;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::string key;
        getline(std::cin, key);
        keys.push_back(key);
    }
    //여기까지 입력

    
}