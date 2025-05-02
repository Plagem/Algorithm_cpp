#include <iostream>
#include <string.h>

using namespace std;

int main() {
  int arr[100001][4] = {0, };
  memset(arr, -1, sizeof(arr));
  long long size[100001];
  
  int R, C, N;
  cin >> R >> C >> N;
  
  for(int i = 0; i < N; i++) {
    int a, v, h;
    cin >> a >> v >> h;

    if(arr[a][0] > v || arr[a][0] == -1) arr[a][0] = v;
    if(arr[a][1] < v || arr[a][1] == -1) arr[a][1] = v;
    if(arr[a][2] > h || arr[a][2] == -1) arr[a][2] = h;
    if(arr[a][3] < h || arr[a][3] == -1) arr[a][3] = h;

    size[a] = (arr[a][1] - arr[a][0] + 1) * (arr[a][3] - arr[a][2] + 1);
  }

  int resultidx = 0;
  int resultsize = 0;
  for(int i = 0; i < 1000001; i++) {
    if(size[i] > resultsize) {
      resultidx = i;
      resultsize = size[i];
    }
  }

  cout << resultidx << " " << resultsize;
}

