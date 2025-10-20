#include<iostream>
#include<vector>

using namespace std;

int N,M;
vector<int> vec;

void func(int cnt) {
    // M개 다 뽑았으면 출력
    if (vec.size() == M) {
        for (int i = 0; i < M; i++) cout << vec[i] << " ";
        cout << "\n";
        return; 
    }

    // cnt..N 중에서 하나를 고르고 내려감
    for (int i = cnt; i <= N; i++) {
        vec.push_back(i);   // i 선택
        func(i + 1);        // 다음은 i보다 큰 수부터만 고른다(오름차순/중복방지)
        vec.pop_back();     // i 선택을 되돌리고 다음 후보(i+1) 시도
    }
}

int main() {
   cin >> N >> M;
   func(1);
}
