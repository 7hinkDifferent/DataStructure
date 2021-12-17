// #include <iostream>
// #include <stack>

// #define inf 1e20

// using namespace std;

// struct Point {
//     bool Walkable = true;
//     int Weight[8] = {-1, -1, -1, -1, -1, -1, -1, -1}; //-1 for out of range or not walkable
//     int Direction[8] = {1, 1, 1, 1, 1, 1, 1, 1};// 1 for not tried, 0 for tried or out of range
// };

// Point map[199][199];

// struct xy {
//     int x;
//     int y;
// };


// struct Info
// {
//     int steps;
//     stack<xy> walked;
// };


// int main(int argc, char* argv[]) {
//     for (int i = 0; i < 199; i++)
//     {
//         for (int j  = 0; j < 199; j++)
//         {
//             if (i >= 198 || j >= 199) map[i][j].Direction[0] = 0;
//             if (i >= 199 || j >= 198) map[i][j].Direction[0] = 0;
//             if (i <= 0 || j <= 198) map[i][j].Direction[0] = 0;
//             if (i <= 1 || j <= 199) map[i][j].Direction[0] = 0;
//             if (i <= 1 || j <= 0) map[i][j].Direction[0] = 0;
//             if (i <= 0 || j <= 1) map[i][j].Direction[0] = 0;
//             if (i >= 199 || j <= 1) map[i][j].Direction[0] = 0;
//             if (i >= 198 || j <= 0) map[i][j].Direction[0] = 0;
            
//         }
        
//     }

//     int x_final;
//     int y_final;
//     cin >> x_final >> y_final;

//     int num = 0;
//     cin >> num;
//     int xn;
//     int yn;

//     for (int i = 0; i < num; i++)
//     {
//         cin >> xn >> yn;
//         map[xn][yn].Walkable = false;
//     }
    
//     Info info;
//     info.walked.empty();

//     do {
        
//     }while (!info.walked.empty());
    
    
// }


#include <iostream>
#include <queue>

using namespace std;

typedef struct Point{
    int x;
    int y;
    int steps;
    Point& operator = (Point& aPoint) {
        if (this == &aPoint) return *this;
        x = aPoint.x;
        y = aPoint.y;
        steps = aPoint.steps;
        return *this;
    };
};

int map[199][199]; // -1 for forbidden point, 0 for not visit, else for steps

/*
1 for x + 2, y + 1;
2 for x + 1, y + 2;
3 for x - 1, y + 2;
4 for x - 2, y + 1;
5 for x - 2, y - 1;
6 for x - 1, y - 2;
7 for x + 1, y - 2;
8 for x + 2, y - 1;
*/
bool CanWalk(Point aPoint, int Dir) {
    switch (Dir)
    {
    case 1:
        if (aPoint.x >= 198 || aPoint.y >= 199) return false;
        if (map[aPoint.x + 2][aPoint.y + 1] == -1) return false;
        return true;
        break;
    case 2:
        if (aPoint.x >= 199 || aPoint.y >= 198) return false;
        if (map[aPoint.x + 1][aPoint.y + 2] == -1) return false;
        return true;
        break;
    case 3:
        if (aPoint.x <= 0 || aPoint.y >= 198) return false;
        if (map[aPoint.x - 1][aPoint.y + 2] == -1) return false;
        return true;
        break;
    case 4:
        if (aPoint.x <= 1 || aPoint.y >= 199) return false;
        if (map[aPoint.x - 2][aPoint.y + 1] == -1) return false;
        return true;
        break;
    case 5:
        if (aPoint.x <= 1 || aPoint.y <= 0) return false;
        if (map[aPoint.x - 2][aPoint.y - 1] == -1) return false;
        return true;
        break;
    case 6:
        if (aPoint.x <= 0 || aPoint.y <= 1) return false;
        if (map[aPoint.x - 1][aPoint.y - 2] == -1) return false;
        return true;
        break;
    case 7:
        if (aPoint.x >= 199 || aPoint.y <= 1) return false;
        if (map[aPoint.x + 1][aPoint.y - 2] == -1) return false;
        return true;
        break;
    case 8:
        if (aPoint.x >= 198 || aPoint.y <= 0) return false;
        if (map[aPoint.x + 2][aPoint.y - 1] == -1) return false;
        return true;
        break;
    default:
        return false;
        break;
    }
}


queue<Point> tmp;

int x_final;
int y_final;
int num;
int tmp_x;
int tmp_y;

Point last{100, 100, 0};
Point goodnext{100, 100, 0};

int main(int argc, char* argv[]) {
    for (int i = 0; i < 199; i++)
    {
        for (int j = 0; j < 199; j++)
        {
            map[i][j]=0;
        }
        
    }
    cin >> x_final >> y_final;
    x_final += 100;
    y_final += 100;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp_x >> tmp_y;
        tmp_x = tmp_x + 100;
        tmp_y = tmp_y + 100;
        map[tmp_x][tmp_y] = -1;
    }
    map[100][100]= -1;
    tmp.push(last);
    do {
        last = tmp.front();
        if(last.x == x_final && last.y == y_final) {
            map[x_final][y_final] = last.steps;
            break;
        }
        tmp.pop();
        if(CanWalk(last, 1)) {
            if (last.steps < map[last.x + 2][last.y + 1] + 1 || map[last.x + 2][last.y + 1] == 0) {
                map[last.x + 2][last.y + 1] = last.steps + 1;
                goodnext.x = last.x + 2;
                goodnext.y = last.y + 1;
                goodnext.steps = map[last.x + 2][last.y + 1];
                tmp.push(goodnext);
            }
        };
        if(CanWalk(last, 2)) {
            if (last.steps < map[last.x + 1][last.y + 2] + 1 || map[last.x + 1][last.y + 2] == 0) {
                map[last.x + 1][last.y + 2] = last.steps + 1;
                goodnext.x = last.x + 1;
                goodnext.y = last.y + 2;
                goodnext.steps = map[last.x + 1][last.y + 2];
                tmp.push(goodnext);
            }
        };
        if(CanWalk(last, 3)) {
            if (last.steps < map[last.x - 1][last.y + 2] + 1 || map[last.x - 1][last.y + 2] == 0) {
                map[last.x - 1][last.y + 2] = last.steps + 1;
                goodnext.x = last.x - 1;
                goodnext.y = last.y + 2;
                goodnext.steps = map[last.x - 1][last.y + 2];
                tmp.push(goodnext);
            }
        };
        if(CanWalk(last, 4)) {
            if (last.steps < map[last.x - 2][last.y + 1] + 1 || map[last.x - 2][last.y + 1] == 0) {
                map[last.x - 2][last.y + 1] = last.steps + 1;
                goodnext.x = last.x - 2;
                goodnext.y = last.y + 1;
                goodnext.steps = map[last.x - 2][last.y + 1];
                tmp.push(goodnext);
            }
        };
        if(CanWalk(last, 5)) {
            if (last.steps < map[last.x - 2][last.y - 1] + 1 || map[last.x - 2][last.y - 1]) {
                map[last.x - 2][last.y - 1] = last.steps + 1;
                goodnext.x = last.x - 2;
                goodnext.y = last.y - 1;
                goodnext.steps = map[last.x - 2][last.y - 1];
                tmp.push(goodnext);
            }
        };
        if(CanWalk(last, 6)) {
            if (last.steps < map[last.x - 1][last.y - 2] + 1 || map[last.x - 1][last.y - 2] == 0) {
                map[last.x - 1][last.y - 2] = last.steps + 1;
                goodnext.x = last.x - 1;
                goodnext.y = last.y - 2;
                goodnext.steps = map[last.x - 1][last.y - 2];
                tmp.push(goodnext);
            }
        };
        if(CanWalk(last, 7)) {
            if (last.steps < map[last.x + 1][last.y - 2] + 1 || map[last.x + 1][last.y - 2] == 0) {
                map[last.x + 1][last.y - 2] = last.steps + 1;
                goodnext.x = last.x + 1;
                goodnext.y = last.y - 2;
                goodnext.steps = map[last.x + 1][last.y - 2];
                tmp.push(goodnext);
            }
        };
        if(CanWalk(last, 8)) {
            if (last.steps < map[last.x + 2][last.y - 1] + 1 || map[last.x + 2][last.y - 1] == 0) {
                map[last.x + 2][last.y - 1] = last.steps + 1;
                goodnext.x = last.x + 2;
                goodnext.y = last.y - 1;
                goodnext.steps = map[last.x + 2][last.y - 1];
                tmp.push(goodnext);
            }
        };
    }while(!tmp.empty());

    if (map[x_final][y_final] == 0) cout << "fail" << endl;
    else cout << map[x_final][y_final] << endl;
    
    return 0;
}