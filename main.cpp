#include <stdio.h>
#include <conio.h>
#include "data_structrue.h"
#define CONSOLE_WIDTH 80
// Ham khoi tao list
void InitList(List &l)
{
    l.pHead = l.pTail = NULL;
}

pNode TaoNode(DanhBa x)
{
    pNode p = new Node;
    p->Data = x;
    p->Next = NULL;
    return p;
}
void NhapDanhBa(DanhBa &x)
{
    printf("\nNhap so dien thoai: ");
    scanf("%d",&x.sdt);
    printf("\nNhap ho va ten: ");
    fflush(stdin);
    fgets(x.hoten,25,stdin);
    printf("\nNhap email: ");
    fflush(stdin);
    fgets(x.email,50,stdin);
    printf("\nNhap dia chi: ");
    fflush(stdin);
    fgets(x.diachi,255,stdin);

}
void ThemCuoi(List &l, pNode p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;    
    }
    else
    {
        l.pTail->Next = p;
        l.pTail = p;
    }
}
//------------------- Xoa ---------------//

void XoaDau(List &l)
{
	if (!l.pHead)
		return;
	pNode delete_node = l.pHead;

	l.pHead = delete_node->Next;

	if (delete_node == l.pTail)
		l.pTail = NULL;
	delete delete_node;

}

void XoaCuoi(List &l)
{
	if (!l.pHead)
		return;
	pNode delete_node = l.pTail;

	if (delete_node == l.pHead)
	{
		l.pHead = NULL;
		l.pTail = NULL;
	}
	else
	{
		pNode  i;
		for (i= l.pHead; i->Next != l.pTail; i=i->Next);

		i->Next=NULL;
		l.pTail = i;
	}
	delete delete_node;
}
void XoaSDT(List &l, pNode sdt_canxoa)
{
    pNode delete_node = sdt_canxoa->Next;
    sdt_canxoa->Next= delete_node->Next;
    delete_node->Next = NULL;
    delete delete_node;
}
void XoaDanhBa(List &l,int del_sdt)
{
    if(!del_sdt)
        return;
    else if (del_sdt == l.pHead->Data.sdt)
        XoaDau(l);
    else if(del_sdt == l.pTail->Data.sdt)
        XoaCuoi(l);
    else
    {
        pNode i=l.pHead;
		while (i && i->Data.sdt != del_sdt)
			i = i->Next;
		if (i)
			XoaSDT(l, i);
    }
}



//---------------------------------------//
void XuatChiTietDanhBa(DanhBa x)
{
    printf("\n");
    printf("\n|------------------------------------------------------------------| ");
    printf("\nHo va Ten: %s",x.hoten);
    printf("So dien thoai: %d",x.sdt);
    printf("\nEmail: %s",x.email);
    printf("Dia chi: %s",x.diachi);
    printf("|------------------------------------------------------------------/");
    printf("\n");

}
void Input(List &l)
{
    int n;
    printf("\nBan muon nhap bao nhieu danh ba?\n");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        DanhBa bd;
        printf("\nMoi ban nhap danh ba thu %d: ",i);
        NhapDanhBa(bd);
        pNode p= TaoNode(bd);
        ThemCuoi(l,p);
    }
}

void XuatDanhBa(List l)
{
    printf("\n Danh ba: \n");
    for (pNode i = l.pHead; i ; i=i->Next)
    {
        printf("Danh ba thu %d",i);
        XuatChiTietDanhBa(i->Data);
    }
    if(l.pHead == NULL)
    {
        printf("\nDanh ba rong!\n");
    }
    
}
int main()
{
    List l;
    int n;
    InitList(l);
    DanhBa x;
    do
    {
        printf("___________________________________________\n");
        printf("*|        Quan Ly Danh Ba                    |* \n");
        printf("---------****************************------\n");
        printf("|         1. Tao danh ba \n");
        printf("------------------------------------------**\n");
        printf("|         2. Xuat danh ba \n");
        printf("------------------------------------------**\n");
        printf("|         3. Tim danh ba theo sdt \n");
        printf("------------------------------------------**\n");
        printf("|         4. Load file \n");
        printf("------------------------------------------**\n");
        printf("|         5. Backup \n");
        printf("------------------------------------------**\n");
        printf("\nChon 1 trong các chuc nang tren: ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            {
                
                Input(l);
                
            }
            break;
        case 2:
            {
                int task;
                XuatDanhBa(l);
                if(l.pHead==NULL)
                {
                    char tiep_tuc;
                    printf("\nBan co muon tao danh ba moi?(y/n)\n");
                    fflush(stdin);
                    scanf("%c", &tiep_tuc);
                    if(tiep_tuc == 'y')
                    {
                        Input(l);
                    }
                    else
                        break;
                }
                else
                {
                    
                    printf("\n1.Xoa 1 danh ba theo so dien thoai");
                    printf("\n2.Sua 1 danh ba");
                    printf("\n3.Quay lai");
                    printf("\nChon 1 trong cac lenh tren: ");
                    scanf("%d",&task);
                    switch (task)
                    {
                    case 1:
                        {
                            int Del_sdt;
                            printf("\nNhap sdt can xoa: ");
                            scanf("%d",&Del_sdt);
                            XoaDanhBa(l,Del_sdt);
                        }
                        break;
                    case 2:
                        {

                        }
                        break;
                    case 3:
                        break;
                    }
                }
            }
            break;
        case 3:
            {

            }
            break;
        case 4:
            {

            }
            break;
        case 5:
            {

            }
            break;
        }
        
    } while (n);
    
    

    //1.tao danh ba
    //1.1-input
    //1.1-output 
    //1.1.1--input vao file txt
    //2xuat danh ba
    XuatDanhBa(l);
    //2.1-sua danh ba
    //2.2-xoa danh ba
    //3.load file
    //4.backup file

}