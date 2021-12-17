#include <iostream>

#define N 500
#define M 125000
#define K 10000

using namespace std;

//big matrix for line
//type for in and outdegree

struct Vertex {
    int inDegree = 0;
    int outDegree = 0;
    bool Deleted = false;
};

struct SearchRst {
    int P1;
    int P2;
    int Rst;
};


int MP[N][N];
Vertex Vertexes[N];
SearchRst Searched[K];

// to delete
int totalDegree = 0;
int toDeleted;
//int DeletedId[N];

int VertexNum;
int LineNum;
int SearchedNum;

int V1;
int V2;

int cnt = 0;

bool IsAncestor(int P1, int P2){  
    bool flag = false;  
    if (MP[P1][P2] >= 0) return true;
    else {
        int j = 0;
        for (int i = 0; i < VertexNum && j != Vertexes[P1].outDegree; i++)
        {
            if (i == P1) continue;
            if (MP[P1][i] >= 0) {
                j++;
                flag = IsAncestor(i, P2);
            }
            if (flag) return true;
        }
    }
    return flag;
}


int main(int argc, char* argv[]) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            MP[i][j] = -1;
        }
    }
    cin >> VertexNum >> LineNum >> SearchedNum;

    for (int i = 0; i < LineNum; i++)
    {
        cin >> V1 >> V2;
        Vertexes[V1].outDegree++;
        Vertexes[V2].inDegree++;
        MP[V1][V2] = V2;
    }

    for (int i = 0; i < SearchedNum; i++)
    {
        cin >> Searched[i].P1 >> Searched[i].P2;
    }
    

    totalDegree = LineNum;
    // judge if loop
    while (totalDegree)
    {
        toDeleted = -1;
        for (int i = 0; i < VertexNum; i++)
        {
            if (Vertexes[i].inDegree == 0 && !Vertexes[i].Deleted) {
                toDeleted = i;
                Vertexes[i].Deleted = true;
                break;
            }
        }
        if (toDeleted == -1) break;
        else {
            cnt = 0;
            for (int j = 0; j < N && cnt != Vertexes[toDeleted].outDegree; j++)
            {
                if (MP[toDeleted][j] == j) {
                    cnt++;
                    totalDegree--;
                    Vertexes[j].inDegree--;
                }
            }
        }
    }
    if (totalDegree) cout << -1 << endl;
    else {
        // judge if ancestor
        for (int i = 0; i < SearchedNum; i++)
        {
            if (IsAncestor(Searched[i].P1, Searched[i].P2)) cout << 1 << endl;
            else if (IsAncestor(Searched[i].P2, Searched[i].P1)) cout << -1 << endl;
            else cout << 0 << endl;
        }
    }

    return 0;
} 