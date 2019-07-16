struct DanhBa
{
    char hoten[25];
    int sdt;
    char email[50];
    char diachi[255];
};

struct Node
{
    DanhBa Data;
    Node * Next;
};
typedef Node * pNode;

struct List
{
    pNode pHead;
    pNode pTail;
};
typedef List * pList;