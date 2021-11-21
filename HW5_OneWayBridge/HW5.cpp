#include <iostream>

using namespace std;

struct Person {
    unsigned int Number;
    unsigned int Weight;
    unsigned int TimeOnBridge;
    unsigned int TimeAcrossBridge;
    float Speed;
    float Distance;
};

int main(int argc, char* argv[]) {
    //处理输入 （尝试用简单的数组来储存数据）
    unsigned int TotalNum;
    unsigned int MaxWeight;
    Person Persons[100];
    unsigned int WeightOnBridge = 0;
    unsigned int SafeAcrossNum = 0;
    unsigned int Time = 0;

    bool IsSafe = true;

    cin >> TotalNum >> MaxWeight;

    for (unsigned int i = 0; i < TotalNum; i++)
    {
        cin >> Persons[i].Weight >> Persons[i].TimeOnBridge >> Persons[i].TimeAcrossBridge;
        Persons[i].Number = i;
        Persons[i].Distance = 0;
        Persons[i].Speed = 1. / (float)Persons[i].TimeAcrossBridge;
    }


    for (unsigned int i = 0; i < TotalNum; i++)
    {
        for (unsigned int j = SafeAcrossNum; j < i; j++)
        {
            Persons[j].Distance += Persons[j].Speed * (Persons[i].TimeOnBridge - Time);
            Persons[j].Distance = (j > SafeAcrossNum &&  Persons[j].Distance > Persons[j - 1].Distance) ? Persons[j - 1].Distance : Persons[j].Distance;
            if (Persons[j].Distance >= 1.)
            {
                SafeAcrossNum++;
                WeightOnBridge -= Persons[j].Weight;
            }
                    
        }
        Time = Persons[i].TimeOnBridge;
        WeightOnBridge += Persons[i].Weight;
        if (WeightOnBridge > MaxWeight)
        {
            cout << i + 1;
            IsSafe = false;
            break;
        }
        
    }
    if (IsSafe)
    {
        cout << "safe";
    }
    
    return 0;

    //先更新数据，再每一个人上去
    //判断
}