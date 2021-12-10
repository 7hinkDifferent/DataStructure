#include <iostream>
#include <vector>
#include <queue>

#define MAXOP 100000
#define MAXDEM 5

using namespace std;

struct Point {
    int Data[MAXDEM];
};

struct Manhattan {
    int Id;
    long long Distance;
};

struct cmp_bigheap {
    bool operator () (Manhattan& a, Manhattan& b) const {
        return a.Distance < b.Distance;  
    }
};

struct cmp_smallheap {
     bool operator () (Manhattan& a, Manhattan& b) const {
        return a.Distance > b.Distance;  
    }
};


priority_queue<Manhattan, vector<Manhattan>, cmp_smallheap > SmallHeap[32];
priority_queue<Manhattan, vector<Manhattan>, cmp_bigheap > BigHeap[32];
int op;
int sign;
Manhattan dis;
int totalop;
int deleted = 0;
int rest = 0;
int dem;
Point tmp;
long long ans[MAXOP] = {0};

// for delete the id;
int num_op = 0;
int deleted_id[MAXOP / 2][2];

int main() {
    cin >> totalop >> dem;
    for (int i = 0; i < totalop; i++)
    {
        cin >> op;
        ans[i] = 0;
        if (op)
        {
            cin >> num_op;
            deleted_id[deleted][0] = num_op;
            deleted_id[deleted][1] = 0;
            deleted++;
            rest--;
            for (int k = 0; k < 1 << dem; k++)
            {
                for (int n = 0; n < deleted; n++)
                {
                    if (deleted_id[n][1] >= 1 << (dem + 1)) continue;
                    if (BigHeap[k].top().Id == deleted_id[n][0]) {
                        BigHeap[k].pop();
                        deleted_id[n][1]++;
                        n = -1;
                        continue;
                    }
                    if (SmallHeap[k].top().Id == deleted_id[n][0]) {
                        SmallHeap[k].pop();
                        deleted_id[n][1]++;
                        n = -1;
                        continue;
                    }
                }
                
                if (rest >= 2 ) {
                    if (ans[i] < BigHeap[k].top().Distance - SmallHeap[k].top().Distance) ans[i] = BigHeap[k].top().Distance - SmallHeap[k].top().Distance;
                }
            }
        }
        else {
            rest++;
            for (int j = 0; j < dem; j++)
            {
                cin >> tmp.Data[j];
            }
            dis.Id = i + 1;
            for (int k = 0; k < 1 << dem; k++)
            {
                dis.Distance = 0;
                for (int l = 0; l < dem; l++)
                {
                    sign = k & (1 << l);
                    if (sign) dis.Distance += tmp.Data[l];
                    else dis.Distance -= tmp.Data[l];
                }
                SmallHeap[k].push(dis);
                BigHeap[k].push(dis);
                if (ans[i] < BigHeap[k].top().Distance - SmallHeap[k].top().Distance) ans[i] = BigHeap[k].top().Distance - SmallHeap[k].top().Distance;
            }
        }
        
        // if (rest >= 2) {
        //     for (int m = 0; m < 1 << dem; m++)
        //     {
        //         while (true) {
        //             isdeleted = false;
        //             for (int n = 0; n < deleted; n++)
        //             {
        //                 if (deleted_id[n][1] >= 1 << (dem + 1)) continue;
        //                 isdeleted = BigHeap[m].top().Id == deleted_id[n][0];
        //                 if (isdeleted) {
        //                     BigHeap[m].pop();
        //                     deleted_id[n][1]++;
        //                     n = -1;
        //                     continue;
        //                 }
        //                 isdeleted = SmallHeap[m].top().Id == deleted_id[n][0];
        //                 if (isdeleted) {
        //                     SmallHeap[m].pop();
        //                     deleted_id[n][1]++;
        //                     n = -1;
        //                     continue;
        //                 }
        //             }
        //             if (!isdeleted) break;
        //         }
        //         if (ans[i] < BigHeap[m].top().Distance - SmallHeap[m].top().Distance) ans[i] = BigHeap[m].top().Distance - SmallHeap[m].top().Distance;
        //     }
        // }
        
    }

    for (int i = 0; i < totalop; i++)
    {
        cout << ans[i] << endl;
    }
    


    return 0;
}