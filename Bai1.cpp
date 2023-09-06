#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct Node{
    int info;
    struct Node *pNext;
} Node;

typedef Node *PtrNode;

// Ham khoi tao danh sach  
void Init(PtrNode &pHead){
    pHead = NULL;
}

// Ham kiem tra rong  
bool IsEmpty(PtrNode pHead){
    return pHead == NULL;
}

// Ham tao 1 node  
PtrNode CreateNode(int x){
    PtrNode p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->pNext = NULL;
    return p;
}

// Ham them 1 node vao dau danh sach  
void InsertFirst(PtrNode &pHead, PtrNode pNew){
    if(IsEmpty(pHead)){
        pHead = pNew;
    }else{
        pNew->pNext = pHead;
        pHead = pNew;
    }
}

// Ham them 1 node  vao vi tri cuoi  danh sach  
void InsertAfter(PtrNode pHead, PtrNode pNew){
    PtrNode p = pHead;
    while(p->pNext != NULL){
        p = p->pNext;
    }
    p->pNext = pNew;
}

// Ham them 1 node  vao vi tri giua  
void Insert(PtrNode &pHead, int vitri, PtrNode newNode){
    int n = 0;
    PtrNode temp = pHead;
    while(temp != NULL){
        n++;
        temp = temp->pNext;
    }

    if(vitri < 1 || vitri > n ){
        printf("\nVi tri khong hop le!\n");
        return;
    }

    if(vitri == 1){
        InsertFirst(pHead, newNode);
        return;
    }

    temp = pHead;
    for(int i = 1; i < vitri - 1; i++){
        temp = temp->pNext; // temp = vitri-1
    }

    newNode->pNext = temp->pNext;
    temp->pNext = newNode;
}

// Ham xoa 1 node dau danh sach  
void DeleteFirst(PtrNode &pHead){
    if(IsEmpty(pHead)){
        printf("\nKhong the xoa !\n");
    }else{
        PtrNode p = pHead;
        pHead = p->pNext;
        free(p);
    }
}

// Ham xoa 1 node cuoi danh sach  
void DeleteAfter(PtrNode pHead){
    if(pHead == NULL || pHead->pNext == NULL){
        printf("\nKhong the xoa !\n");
    }else{
        PtrNode q = pHead->pNext;
        pHead->pNext = q->pNext;
        free(q);
    }
}

// Ham xoa - giai phong  
void ClearList(PtrNode &pHead){
    PtrNode p;
    while(pHead!= NULL){
        p = pHead;
        pHead = p->pNext;
        free(p);
    }
}

// Ham nhap du lieu  cho danh sách
void Input(PtrNode &pHead){
    int x;
    Init(pHead);
    do{
        printf("Nhap gia tri (End = 0): ");
        scanf("%d",&x);
        if(x==0)
            break;
        PtrNode pNew = CreateNode(x);
        InsertFirst(pHead, pNew);
    }while(true);
}

// Ham duyet  danh sach - xuat danh sách
void ShowList(PtrNode pHead){
    PtrNode p = pHead;
//    if(p == NULL){
//        printf("\nDanh sach bi rong !");
//        return; 
//    }
    while(p != NULL){
        printf("%4d\t",p->info);
        p = p->pNext;
    }
    printf("[NULL]\n"); 
}

// Ham tim kiem
PtrNode Search(PtrNode pHead,int x){
    PtrNode p = pHead;
    while(p->info != x && p!=NULL)
        p = p->pNext;
    return p;
}

// Ham sap xep tang
void Sort(PtrNode &pHead){
    PtrNode p,q,pmin;
    int min;
    for(p=pHead;p->pNext != NULL;p = p->pNext){
        min = p->info;
        pmin = p;
        for(q=p->pNext;q!=NULL;q=q->pNext){
            if(q->info<min){
                min = q->info;
                pmin=q;
            }
        }
        pmin->info = p->info;
        p->info = min;
    }
}

// Ham xac dinh node thu i
PtrNode NodePointer(PtrNode pHead,int i){
    PtrNode p = pHead;
    int vitri = 1;
    while(p!=NULL && vitri<i){
        p = p->pNext;
        vitri++;
    }
    return p;
}

// Ham xac dinh vi tri node p
int Position(PtrNode pHead,PtrNode p){
    int vitri = 1;
    PtrNode q = pHead;
    while(q!=NULL && q!=p){
        q = q->pNext;
        vitri++;
    }
    if(q==NULL)
        return -1;
    return vitri;
}

// Ham xac dinh nut truoc cua node p
PtrNode PreNode(PtrNode pHead,PtrNode p){
    PtrNode q;
    if(p==pHead)
        return NULL;
    q = pHead;
    while(q!=NULL && q->pNext!=p)
        q = q->pNext;
    return q;        
}

// Them 1 node co noi dung x
//void Place(PtrNode &pHead,int x){
//    PtrNode p,q;
//    q = NULL;
//    for(p=pHead; p!=NULL && x>p->info; p = p->pNext){
//        q = p;
//    }
//    if(q==NULL)
//        InsertFirst(pHead,x);
//    else
//        InsertAfter(q,x);
//}
int main(){
    PtrNode pHead = NULL;
    Input(pHead);
    printf("Danh sach vua nhap la: \n");
    ShowList(pHead);

    // Them node vao dau danh sach  
    int value1 = 10;
    PtrNode newNode1 = CreateNode(value1);
    InsertFirst(pHead, newNode1);
    printf("\nDanh sach sau khi them node vao dau la: \n");
    ShowList(pHead);

    // Them node vao cuoi danh sach  
    int value2 = 20;
    PtrNode newNode2 = CreateNode(value2);
    InsertAfter(pHead, newNode2);
    printf("\nDanh sach sau khi them node vao cuoi la: \n");
    ShowList(pHead);

    // Them node vao vi tri giua  
    int value3 = 30;
    int position = 2;
    PtrNode newNode3 = CreateNode(value3);
    Insert(pHead, position, newNode3);
    printf("\nDanh sach sau khi them node vao giua la: \n");
    ShowList(pHead);

    // Xoa node dau danh sach  
    DeleteFirst(pHead);
    printf("\nDanh sach sau khi xoa node dau la: \n");
    ShowList(pHead);

    // Xoa node cuoi danh sach  
    DeleteAfter(pHead);
    printf("\nDanh sach sau khi xoa node cuoi la: \n");
    ShowList(pHead);

    // Ham sort tang 
    Sort(pHead);
    printf("\nDanh sach sau khi sort tang la: \n");
    ShowList(pHead);
	
	
    // Thuc hien tim kiem  
    int searchValue = 3;
    PtrNode searchResult = Search(pHead, searchValue);
    if (searchResult == NULL) {
        printf("\nKhong tim thay gia tri %d trong danh sach\n", searchValue);
    } else {
        printf("\nTim thay gia tri %d tai vi tri %d trong danh sach\n", searchValue, Position(pHead, searchResult));
    }

    // Thuc hien xac dinh node thu  i
    int index = 2;
    PtrNode nodeIndex = NodePointer(pHead, index);
    if (nodeIndex == NULL) {
        printf("\nVi tri %d khong hop le\n", index);
    } else {
        printf("\nNode thu %d co gia tri la: %d\n", index, nodeIndex->info);
    }

    // Thuc hien xac dinh vi tri  node p
    PtrNode pNode = pHead->pNext;
    int pos = Position(pHead, pNode);
    if (pos == -1) {
        printf("\nKhong tim thay node trong danh sach\n");
    } else {
        printf("\nNode co gia tri %d nam o vi tri %d trong danh sach\n", pNode->info, pos);
    }

    // Thuc hien xac dinh node truoc  node p
    PtrNode preNode = PreNode(pHead, pNode);
    if (preNode == NULL) {
        printf("\nNode khong co node truoc no\n");
    } else {
        printf("\nNode truoc node co gia tri %d\n", preNode->info);
    }

	
    // Xoa danh sach - giai phong  
    ClearList(pHead);
    ShowList(pHead);

    return 0;
}

