#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structrue.h"
#define CONSOLE_WIDTH 80
#define SOURCE_PATH "danhba.txt"
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
    int stt = 0;
    for (pNode i = l.pHead; i ; i=i->Next)
    {
        stt++;
        printf("\nDanh ba thu %d",stt);
        XuatChiTietDanhBa(i->Data);
    }
    if(l.pHead == NULL)
    {
        printf("\nDanh ba rong!\n");
    }
    
}
//--------------- Tim SDT --------------------//

void TimSDT(List l, int sdt_cantim)
{
    pNode p = l.pHead;
    while (p && p->Data.sdt != sdt_cantim)
    {
        p=p->Next;
    }
    if(p)
    {
        XuatChiTietDanhBa(p->Data);
    }
    else
    {
        printf("\nKhong tim thay!\n");
    }
    
}


//------------------------------------------//
//---------------Sua sdt--------------------//
pNode TimX(List l, int sdt_cantim)
{
    pNode p = l.pHead;
    while (p && p->Data.sdt != sdt_cantim)
    {
        p=p->Next;
    }
    return p;
}
void SuaSDT(List &l, int sua_sdt)
{
    DanhBa x;
    pNode p = TimX(l,sua_sdt);
    printf("\nNhap cac thong tin moi: \n");
    printf("\nSo dien thoai: %d --->>>",p->Data.sdt);
    scanf("%d",p->Data.sdt);
    printf("\nHo va ten: %s --->>>",p->Data.hoten);
    fflush(stdin);
    fgets(p->Data.hoten,25,stdin);
    printf("\nEmail: %s --->>>",p->Data.email);
    fflush(stdin);
    fgets(p->Data.email,50,stdin);
    printf("\nDia chi: %s --->>>",p->Data.diachi);
    fflush(stdin);
    fgets(p->Data.diachi,255,stdin);
}
//------------------------------------------//
int DoDaiDS(List l)
{
    int dem = 0;
    for (pNode i = l.pHead; i ; i=i->Next)
    {
        dem++;
    }
    return dem;
}
//--------------ghi ds vao file -------------//
void GhiDSvaoFile(List &l)
{
    FILE *f = fopen(SOURCE_PATH, "w");
    int n = DoDaiDS(l);
    fprintf(f, "%d\n", n);
    for (pNode  temp=l.pHead; temp; temp=temp->Next)
    {
        fprintf(f, "%s", temp->Data.hoten);
        fprintf(f, "%d", temp->Data.sdt);
        fprintf(f, "\n%s", temp->Data.email);
        fprintf(f, "%s", temp->Data.diachi);
    }
    fclose(f);
}

//------------------------------------------//
//-----------Load file----------------------//

void LoadFile(List &l)
{
    FILE *f = fopen(SOURCE_PATH, "r");
    int dodaids;
    fscanf(f, " %d ", &dodaids);
    int i=0;
    DanhBa temp;
    char buffer[256];
    while (i < dodaids)
    {
         if (fgets(buffer, 256, f))
        {

            strcpy(temp.hoten, buffer);
        }
        fscanf(f, " %d ", &temp.sdt);
        if (fgets(buffer, 256, f))
        {

            strcpy(temp.email, buffer);
        }
        if (fgets(buffer, 256, f))
        {

            strcpy(temp.diachi, buffer);
        }
        pNode temp_node = TaoNode(temp);
        ThemCuoi(l, temp_node);
        i++;
    };
    printf("%d danh ba da duoc doc\n", DoDaiDS(l));
    fclose(f);
};
//------------------------------------------//
//-----------Back up file ------------------//


//-----------------------------------------//
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
        printf("\nChon 1 trong cac chuc nang tren: ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            {
                char tieptuc;
                Input(l);
                printf("\nBan co muon ghi vao file txt?(y/n):\t");
                fflush(stdin);
                scanf("%c", &tieptuc);
                if(tieptuc == 'y')
                {
                    GhiDSvaoFile(l);
                    break;
                }
                else
                {
                    break;
                }
                
            }
            break;
        case 2:
            {
                int task;
                XuatDanhBa(l);
                if(l.pHead==NULL)
                {
                    char tieptuc_tao;
                    printf("\nBan co muon tao danh ba moi?(y/n)\n");
                    fflush(stdin);
                    scanf("%c", &tieptuc_tao);
                    if(tieptuc_tao == 'y')
                    {
                        char tieptuc_ghi;
                        Input(l);
                        printf("\nBan co muon ghi vao file txt?(y/n):\t");
                        fflush(stdin);
                        scanf("%c", &tieptuc_ghi);
                        if(tieptuc_ghi == 'y')
                        {
                            GhiDSvaoFile(l);
                            printf("Nhap ENTER de tiep tuc\n");
                            getchar();
                            break;
                        }
                        else
                        {
                            break;
                        }
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
                            int sua_sdt;
                            printf("\nNhap sdt cua danh ba can sua: ");
                            scanf("%d",&sua_sdt);
                            SuaSDT(l,sua_sdt);
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
                int sdt;
                printf("\nNhap sdt can tim: ");
                scanf("%d",&sdt);
                TimSDT(l,sdt);
            }
            break;
        case 4:
            {
                LoadFile(l);
            }
            break;
        case 5:
            {
                char ch, source_file[20], target_file[20];
                FILE *source, *target;
                
                printf("Enter name of file to copy\n");
                fflush(stdin);
                fgets(source_file,20,stdin);
                
                source = fopen(source_file, "r");
                
                if (source == NULL)
                {
                    printf("Press any key to exit...\n");
                }
                
                printf("Enter name of target file\n");
                fflush(stdin);
                fgets(target_file,20,stdin);
                
                target = fopen(target_file, "w");
                
                if (target == NULL)
                {
                    fclose(source);
                    printf("Press any key to exit...\n");
                }
                
                while ((ch = fgetc(source)) != EOF)
                    fputc(ch, target);
                
                printf("File copied successfully.\n");
                
                fclose(source);
                fclose(target);
            }
            break;
        }
        
    } while (n);

}