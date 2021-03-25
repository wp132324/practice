#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<int> step(N);
    for(int i=0; i<N; i++) cin>>step[i];

    int max_loop = 1;
    vector<bool> visit(N);
    vector<int> count(N);
    while(true){
        int s = -1;
        for(int i=0; i<N; i++) {
            if(!visit[i]) {
                s = i;
                break;
            }
        }
        if(s == -1) break;

        vector<bool> now_visit(N);
        int p = s;
        int cnt = 1;
        while(true){
            if(visit[p]){
                if(!now_visit[p]) break;
                max_loop = (max_loop > cnt - count[p])? max_loop : cnt - count[p];
                break;
            }
            count[p] = cnt++;
            visit[p] = true;
            now_visit[p] = true;
            p += step[p];
        }
    }
    cout<<max_loop<<"\n";
    return 0;
}