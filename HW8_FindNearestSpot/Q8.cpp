#include <iostream>
#include <stdio.h>
#include <math.h>

struct Point
{
    double x;
    double y;
    char point;
};

Point points[10000];
Point targets[10000];
double results[10000];

int main(int argc, char* argv[]) {
    unsigned int total;
    unsigned int to_search;
    std::cin >> total >> to_search;

    //scanf("%u%u", &total, &to_search);

    //double min;
    double tmp;
    for (int i = 0; i < total; i++)
    {
        std::cin >> points[i].x >> points[i].y >> points[i].point;
       // scanf("%lf%lf%c", &points[i].x, &points[i].y, &points[i].point);
    }
    for (int i = 0; i < to_search; i++)
    {
        std::cin >> targets[i].x >> targets[i].y;
        //scanf("%lf%lf", &targets[i].x, &targets[i].y);
    }
    for (int i = 0; i < to_search; i++)
    {
        results[i] = (targets[i].x - points[0].x) * (targets[i].x - points[0].x) + (targets[i].y - points[0].y) * (targets[i].y - points[0].y);
        results[i] = sqrt(results[i]);
        for (int j = 1; j < total; j++)
        {
            tmp = (targets[i].x - points[j].x) * (targets[i].x - points[j].x) + (targets[i].y - points[j].y) * (targets[i].y - points[j].y);
            tmp = sqrt(tmp);
            if (tmp < results[i])
            {
                results[i] = tmp;
            }
            
        }
        
    }
    for (int i = 0; i < to_search; i++)
    {
        printf("%.4f\n", results[i]);
    }
    
    
}