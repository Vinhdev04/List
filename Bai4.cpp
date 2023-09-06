#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* PtrNode;

// Ham khoi tao danh sach  
void InitList(PtrNode* pHead) {
    *pHead = NULL;
}

// Hàm ki?m tra danh sách liên k?t có r?ng hay không
bool IsEmpty(PtrNode pHead) {
    return pHead == NULL;
}

// Hàm t?o m?t node m?i
PtrNode CreateNode(int value) {
    PtrNode newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Ham chen 1 node vao dau danh sach  
void InsertBeginning(PtrNode* pHead, PtrNode newNode) {
    if (IsEmpty(*pHead)) {
        *pHead = newNode;
    } else {
        newNode->next = *pHead;
        *pHead = newNode;
    }
}

// Ham chen 1 node vao cuoi danh  sach  
void InsertEnd(PtrNode* pHead, PtrNode newNode) {
    if (IsEmpty(*pHead)) {
        *pHead = newNode;
    } else {
        PtrNode current = *pHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Ham nhap danh sach lien ket  
void InputList(PtrNode* pHead) {
    InitList(pHead);
    int value;
    do {
        printf("Nhap gia tri (End = 0): ");
        scanf("%d", &value);
        if(value==0)
			break; 
        PtrNode newNode = CreateNode(value);
        InsertEnd(pHead, newNode);
        
    } while (true);
}

// Ham xuat danh sach lien ket  
void PrintList(PtrNode pHead) {
    PtrNode current = pHead;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Ham xoa 1 node trong danh sach  
void DeleteNode(PtrNode* pHead, PtrNode deletedNode) {
    if (IsEmpty(*pHead)) {
        printf("Danh sach rong, khong the xoa!\n");
        return;
    }
    if (*pHead == deletedNode) {
        *pHead = deletedNode->next;
        free(deletedNode);
        return;
    }
    PtrNode current = *pHead;
    while (current->next != deletedNode) {
        current = current->next;
    }
    current->next = deletedNode->next;
    free(deletedNode);
}

// Ham chen 1 node P vao danh sach  
void InsertNode(PtrNode* pHead, PtrNode previousNode, PtrNode newNode) {
    if (previousNode == NULL) {
        newNode->next = *pHead;
        *pHead = newNode;
    } else {
        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }
}

// Ham tim X trong danh sach  
PtrNode SearchValue(PtrNode pHead, int value) {
    PtrNode current = pHead;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Ham sap xep danh sach tang dan  
void SortList(PtrNode* pHead) {
    if (IsEmpty(*pHead)) {
        printf("Danh sach rong, khong the sap xep!\n");
        return;
    }
    PtrNode current = *pHead;
    while (current != NULL) {
        PtrNode minNode = current;
        PtrNode temp = current->next;
        while (temp != NULL) {
            if (temp->data < minNode->data) {
                minNode = temp;
            }
            temp = temp->next;
        }
        if (minNode != current) {
            int tempData = current->data;
            current->data = minNode->data;
            minNode->data = tempData;
        }
        current = current->next;
    }
}

int main() {
    PtrNode pHead = NULL;

    // Khoi tao danh sach lien ket  
    InitList(&pHead);

   
	InputList(&pHead);
	printf("\n\n\tDANH SACH VUA NHAP: \n"); 
	PrintList(pHead);
	
	
    // Tao mot node va chen vao dau danh sach  
    int value1 = 10;
    PtrNode newNode1 = CreateNode(value1);
    InsertBeginning(&pHead, newNode1);

    // Tao 1 node va chen vao cuoi danh sach  
    int value2 = 20;
    PtrNode newNode2 = CreateNode(value2);
}
