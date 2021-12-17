#include <stdio.h>

#define N 500
#define K 10000

//big matrix for line
//type for in and outdegree

typedef struct Vertex {
    int inDegree;
    int outDegree;
    int Deleted;
}Vertex;

// typedef struct SearchRst {
//     int P1;
//     int P2;
// }SearchRst;


int MP[N][N];
Vertex Vertexes[N];
//SearchRst Searched[K];
int V1s[K];
int V2s[K];

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

int IsAncestor(int* P1, int* P2){  
    int flag = 0;  
    if (MP[*P1][*P2] == 0) return 1;
    else {
        int j = 0;
        for (int i = 0; i < VertexNum && j != Vertexes[*P1].outDegree; i++)
        {
            if (i == P1) continue;
            if (MP[*P1][i] == 0) {
                j++;
                flag = IsAncestor(&i, P2);
            }
            if (flag) return 1;
        }
    }
    return flag;
}


int main(int argc, char* argv[]) {
    for (int i = 0; i < N; i++)
    {
        Vertexes[i].inDegree = Vertexes[i].outDegree = Vertexes[i].Deleted = 0;
        for (int j = 0; j < N; j++)
        {
            MP[i][j] = -1;
        }
    }
    scanf("%d%d%d", &VertexNum, &LineNum, &SearchedNum);

    for (int i = 0; i < LineNum; i++)
    {
        scanf("%d%d", &V1, &V2);
        Vertexes[V1].outDegree++;
        Vertexes[V2].inDegree++;
        MP[V1][V2] = 0;
    }

    for (int i = 0; i < SearchedNum; i++) scanf("%d%d", &V1s[i], &V2s[i]);
    

    totalDegree = LineNum;
    // judge if loop
    while (totalDegree)
    {
        toDeleted = -1;
        for (int i = 0; i < VertexNum; i++)
        {
            if (Vertexes[i].inDegree == 0 && !Vertexes[i].Deleted) {
                toDeleted = i;
                Vertexes[i].Deleted = 1;
                break;
            }
        }
        if (toDeleted == -1) break;
        else {
            cnt = 0;
            for (int j = 0; j < VertexNum && cnt != Vertexes[toDeleted].outDegree; j++)
            {
                if (MP[toDeleted][j] == 0) {
                    cnt++;
                    totalDegree--;
                    Vertexes[j].inDegree--;
                }
            }
        }
    }
    if (totalDegree) printf("-1\n");
    else {
        // judge if ancestor
        for (int i = 0; i < SearchedNum; i++)
        {
            if (IsAncestor(V1s + i, V2s + i)) printf("1\n");
            else if (IsAncestor(V2s + i, V1s + i)) printf("-1\n");
            else printf("0\n");
        }
    }

    return 0;
} 