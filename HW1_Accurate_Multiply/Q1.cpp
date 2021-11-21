#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 法一：通过二进制的位移来进行运算（暂未实现）

// 法二：分成若干个十进制相乘，最后相加

// 法三：直接string运算

string KillZeros (const string& num) {
    unsigned int counter = 0;
    while (num[counter] == '0')
    {
        counter++;
    }
    return num.substr(counter);
}

string StringPlus (string num1, string num2, int buffer = 0) {
    int tmp;

    if (num1.empty() && num2.empty())
    {
        return to_string(buffer);
    }
    else if (num1.empty())
    {
        tmp = (int)(num2.back() - '0') + buffer;
        num2.pop_back();
    }
    else if (num2.empty())
    {
        tmp = (int)(num1.back() - '0') + buffer;
        num1.pop_back();
    }
    else {
        tmp = (int)(num1.back() -'0') + (int)(num2.back() -'0') + buffer;
        num1.pop_back();
        num2.pop_back();
    }
    
    buffer = tmp / 10;
    tmp = tmp % 10;

    return StringPlus(num1, num2, buffer) + to_string(tmp);
}

string StringPly (string num, char bit, unsigned int digit, int buffer = 0) {
    string zeros = "";
    if (digit > 0)
    {  
        for (int i = 0; i < digit; i++)
        {
            zeros.append(to_string('0' - '0'));
        }
        digit = 0;
    }
    
    if (num.empty())
    {
        return to_string(buffer) + zeros;
    }
    int tmp;
    tmp = (int)(num.back() - '0') * (int)(bit - '0') + buffer;
    buffer = tmp / 10;
    tmp = tmp % 10;

    num.pop_back();
    return StringPly(num, bit, digit, buffer) + to_string(tmp) + zeros;
}

string MassyPly (string num1, string num2) {
    string res = "";
    int loop = num2.size();
    for (int i = 0; i < loop; i++)
    {
        res = StringPlus(res, StringPly(num1, num2.back(), i));
        num2.pop_back();
    }
    return res;
}

int main(int argc, char* argv[]) {
    string num1;
    string num2;
    vector<string> num;

    num.clear();

    unsigned long long i = 0;
    
    cin >> i;

    for (unsigned long long j = 0; j < i; j++)
    {
        cin >> num1 >> num2;
        num.push_back(num1);
        num.push_back(num2);
    }
    
    for (unsigned long long j = 0; j < i; j++)
    {
        cout << KillZeros(MassyPly(num[j * 2], num[j * 2 + 1])) << endl;
    }
    
    return 0;
}