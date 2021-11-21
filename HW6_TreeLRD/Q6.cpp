#include <iostream>

int BinTreeDLR[30000];
int BinTreeLDR[30000];
int BinTreeLRD[30000];

// void ConvertDLRandLDRtoLRD(int* BinTreeDLR, int* BinTreeLDR, int* BinTreeLRD, int left, int right) {
//     if (left >= right) return;
//     int root = left;
//     *(BinTreeLRD + right) = *BinTreeDLR;
//     while (*(BinTreeDLR) != *(BinTreeLRD + root)) root++;
    
//     // build left subtree
//     if (root > left)
//     {
        
//     }
    
    
// }

void ConvertDLRandLDRtoLRD(int DLR1, int DLR2, int LDR1, int LDR2, int LRD1, int LRD2) {
    if(DLR1 > DLR2) return;

    int rootLDR = LDR1;
    
    while (BinTreeDLR[DLR1] != BinTreeLDR[rootLDR]) rootLDR++;
    BinTreeLRD[LRD2] = BinTreeDLR[DLR1];

    // building left tree
    if (rootLDR > LDR1) ConvertDLRandLDRtoLRD(DLR1 + 1, DLR2 - (LDR2 - rootLDR), LDR1, rootLDR - 1, LRD1, LRD2 - (LDR2 - rootLDR) - 1);
    
    // building right tree
    if (rootLDR < LDR2) ConvertDLRandLDRtoLRD(DLR1 + 1 + (rootLDR - LDR1), DLR2, rootLDR + 1, LDR2, LRD1 + (rootLDR - LDR1), LRD2 - 1);
    
}


int main(int argc, char* argv[]) {
    int TreeNum;
    int TreeNodeNum;

    std::string buffer = "";


    std::cin >> TreeNum;
    for (int i = 0; i < TreeNum; i++)
    {
        std::cin >> TreeNodeNum;
        for (int j = 0; j < TreeNodeNum; j++)
        {
            std::cin >> BinTreeDLR[j];
        }
        for (int j = 0; j < TreeNodeNum; j++)
        {
            std::cin >> BinTreeLDR[j];
        }
        ConvertDLRandLDRtoLRD(0, TreeNodeNum - 1, 0, TreeNodeNum - 1, 0, TreeNodeNum - 1);
        for (int j = 0; j < TreeNodeNum; j++)
        {
            buffer += std::to_string(BinTreeLRD[j]);
            if (j != TreeNodeNum - 1) buffer += " ";
            else buffer += "\n";
        }
        
    }
    std::cout << buffer;
    return 0;
}