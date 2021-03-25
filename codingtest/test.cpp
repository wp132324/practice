#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int M, N;
        cin>>M>>N;
        int r, c;
        vector<vector<int>> map(M, vector<int>(N));
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++) {
                cin>>map[i][j];
                if(map[i][j] == 3){
                    r = i;
                    c = j;
                }
            }
        }

        bool check_key = false, check_gold = false, check_open = false;
        vector<vector<bool>> visit(M, vector<bool>(N));
        queue<int> nextr, nextc;
        nextr.push(r);
        nextc.push(c);
        while(!nextr.empty()){
            int pr = nextr.front();
            int pc = nextc.front();
            nextr.pop();
            nextc.pop();
            visit[pr][pc] = true;
            
            if(map[pr][pc] == 2) check_gold = true;
            else if(map[pr][pc] == 4) check_key = true;
            if(check_key && check_gold) {
                check_open = true;
                break;
            }

            int move[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            for(int i=0; i<4; i++){
                int nr = pr+move[i][0];
                int nc = pc+move[i][1];     
                if(0<=nr && nr<M && 0<=nc && nc<N && map[nr][nc]!=1 && visit[nr][nc]==false){
                    nextr.push(nr);
                    nextc.push(nc);
                }            
            }
        }
        if(check_open) cout<<"1\n";
        else cout<<"0\n";
    }

    return 0;
}