#include <iostream>
#include <vector>
using namespace std;

inline int max(vector<vector<int>> bene, int sr, int sc, int er, int ec){
    int ret = 0;
    for(int i=sr; i<er; i++){
        for(int j=sc; j<ec; j++){
            ret = (ret > bene[i][j])? ret : bene[i][j];
        }
    }
    return ret;
}

int max_4(int a, int b, int c, int d){
    int max = a;
    if(max < b) max = b;
    if(max < c) max = c;
    if(max < d) max = d;
    return max;
}

int max_2(int a, int b){
    int max = a;
    if(max < b) max = b;
    return max;
}

int get_max(vector<vector<int>> bene, int sr, int sc, int er, int ec){
    if((er-sr)*(ec-sc) == 4){
        if(er-sr == 2){
            int a = max_2(bene[sr][sc], bene[sr][sc+1]) + max_2(bene[sr+1][sc], bene[sr+1][sc+1]); 
            int b = max_2(bene[sr][sc], bene[sr+1][sc]) + max_2(bene[sr][sc+1], bene[sr+1][sc+1]);
            return max_2(a, b);
        } else if(er-sr == 1){
            return max_2(bene[sr][sc], bene[sr][sc+1]) + max_2(bene[sr][sc+2], bene[sr][sc+3]);
        } else if(ec-sc == 1){
            return max_2(bene[sr][sc], bene[sr+1][sc]) + max_2(bene[sr+2][sc], bene[sr+3][sc]);
        }
    }
    int mr = (sr+er)/2;
    int mc = (sc+ec)/2;
    int a = max(bene, sr, sc, mr, mc);
    int b = max(bene, mr, sc, er, mc);
    int c = max(bene, mr, mc, er, ec);
    int d = max(bene, sr, mc, mr, ec);

    return max_4(max_2(a, b)+get_max(bene, sr, mc, er, ec), 
                 max_2(c, d)+get_max(bene, sr, sc, er, mc), 
                 max_2(a, d)+get_max(bene, mr, sc, er, ec), 
                 max_2(b, c)+get_max(bene, sr, sc, mr, ec));
}

int main() {
    int N;
    cin>>N;
    vector<vector<int>> benefit(N, vector<int>(N));
    for(int i=0; i<N*N; i++) cin>>benefit[i/N][i%N];

    cout<<get_max(benefit, 0, 0, N, N)<<"\n";
    return 0;
}