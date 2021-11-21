#include <iostream>

struct BSTNode {
    BSTNode* Parent = nullptr;
    BSTNode* lChild = nullptr;
    BSTNode* rChild = nullptr;

    int Data;
};


void BuildBinSearchTree(int Data, BSTNode* &CurrentNode, BSTNode* ParentNode) {
    if (CurrentNode == nullptr)
    {
        CurrentNode = new BSTNode;
        CurrentNode->Data = Data;
        CurrentNode->Parent = ParentNode;
        return;
    }
    else if (Data < CurrentNode->Data)
    {
        BuildBinSearchTree(Data, CurrentNode->lChild, CurrentNode);
    }
    else {
        BuildBinSearchTree(Data, CurrentNode->rChild, CurrentNode);
    }
}

BSTNode* SearchBST(int Data, BSTNode* Root) {
    if (Root == nullptr) return nullptr;
    else if (Data < Root->Data) return SearchBST(Data, Root->lChild);
    else if (Data > Root->Data) return SearchBST(Data, Root->rChild);
    else return Root;
}

int SearchAncestor(int ChildA, int ChildB, BSTNode* Root) {
    int i = 0;
    BSTNode* AncestorA[50000];
    int CounterA = 0;
    AncestorA[0] = SearchBST(ChildA, Root);
    while (AncestorA[i])
    {
        AncestorA[++i] = AncestorA[i]->Parent;
        CounterA++;
    }
    
    BSTNode* AncestorB = SearchBST(ChildB, Root);
    while (AncestorB)
    {
        for (int j = 0; j < CounterA; j++)
        {
            if (AncestorB->Data == AncestorA[j]->Data) return AncestorB->Data;
        }
        AncestorB = AncestorB->Parent;
    }
    
}
    
    

int main(int argc, char* argv[]) {
    int NodeNum;
    int SampleNum;
    int tmp;

    std::cin >> NodeNum >> SampleNum;

    int* Ancestor = new int[SampleNum];
    int ChildA;
    int ChildB;

    BSTNode* Root = nullptr;
    for (int i = 0; i < NodeNum; i++)
    {
        std::cin >> tmp;
        BuildBinSearchTree(tmp, Root, Root);
    }

    for (int i = 0; i < SampleNum; i++)
    {
        std::cin >> ChildA >> ChildB;
        *(Ancestor + i) = SearchAncestor(ChildA, ChildB, Root);
    }
    for (int i = 0; i < SampleNum; i++)
    {
        std::cout << *(Ancestor + i) << std::endl;
    }
    delete[] Ancestor;
    return 0;

}