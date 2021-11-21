#include <iostream>
using namespace std;

struct Node {
    char bracket;
    Node* next;
};


int main(int argc, char* argv[]) {
    int total = 0;
    string brackets[50];
    Node* stacks[50];
    Node* tmp;
    int Matched[50];

    cin >> total;

    for (int i = 0; i < total; i++)
    {
        cin >> brackets[i];
        stacks[i] = nullptr;
        Matched[i] = 1;
    }

    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < brackets[i].size() && Matched[i] != 0; j++)
        {
            switch (brackets[i][j])
            {
            case '(':
            case '{':
            case '[':
                tmp = new Node();
                tmp->bracket = brackets[i][j];
                tmp->next = stacks[i];
                stacks[i] = tmp;
                break;
            case ')':
                if (stacks[i] == nullptr || stacks[i]->bracket != '(')
                {
                    Matched[i] = 0;
                    break;
                }
                tmp = stacks[i];
                stacks[i] = tmp->next;
                delete tmp;
                break;
            case '}':
                if (stacks[i] == nullptr || stacks[i]->bracket != '{')
                {
                    Matched[i] = 0;
                    break;
                }
                tmp = stacks[i];
                stacks[i] = tmp->next;
                delete tmp;
                break;
            case ']':
                if (stacks[i] == nullptr || stacks[i]->bracket != '[')
                {
                    Matched[i] = 0;
                    break;
                }
                tmp = stacks[i];
                stacks[i] = tmp->next;
                delete tmp;
                break;
            default:
                throw;
                break;
            }
        }
        
    }
    
    for (int i = 0; i < total; i++)
    {
        cout << Matched[i] << endl;
        while (stacks[i] != nullptr)
        {
            tmp = stacks[i];
            stacks[i] = tmp->next;
            delete tmp;
        }
    }

    return 0;
}