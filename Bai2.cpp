#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdbool.h"

struct Student {
    char id[9];
    char name[31];
    float gpa;
    struct Student* next;
};

typedef struct Student* PtrNode;

void Init(PtrNode &pHead){
    pHead = NULL;
}

bool IsEmpty(PtrNode pHead){
    return (pHead==NULL);
}

PtrNode CreateStudent() {
    PtrNode newNode = (PtrNode)malloc(sizeof(struct Student));
    printf("Nhap ma sinh vien: ");
    scanf("%s", newNode->id);
    printf("Nhap ho ten: ");
    scanf(" %[^\n]s", newNode->name);
    printf("Nhap diem trung binh: ");
    scanf("%f", &(newNode->gpa));
    newNode->next = NULL;
    return newNode;
}

void InsertStudent(PtrNode* pHead, PtrNode newNode) {
    if (*pHead == NULL) {
        *pHead = newNode;
    } else {
        PtrNode temp = *pHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void InputList(PtrNode* pHead) {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        PtrNode newNode = CreateStudent();
        InsertStudent(pHead, newNode);
    }
}

void OutputList(PtrNode pHead) {
    PtrNode temp = pHead;
    while (temp != NULL) {
        printf("Ma sinh vien: %s\n", temp->id);
        printf("Ho ten: %s\n", temp->name);
        printf("Diem trung binh: %.1f\n", temp->gpa);
        temp = temp->next;
    }
}

int Count(PtrNode pHead) {
    int count = 0;
    PtrNode temp = pHead;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

PtrNode Max(PtrNode pHead) {
    PtrNode maxNode = NULL;
    float maxValue = -1;
    PtrNode temp = pHead;
    while (temp != NULL) {
        if (temp->gpa > maxValue) {
            maxValue = temp->gpa;
            maxNode = temp;
        }
        temp = temp->next;
    }
    return maxNode;
}

PtrNode SearchX(PtrNode pHead, float x) {
    PtrNode temp = pHead;
    while (temp != NULL) {
        if (temp->gpa == x) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void ShowEven(PtrNode pHead) {
    PtrNode temp = pHead;
    while (temp != NULL) {
        if ((int)temp->gpa % 2 == 0) {
            printf("Ma sinh vien: %s\n", temp->id);
            printf("Ho ten: %s\n", temp->name);
            printf("Diem trung binh: %.1f\n", temp->gpa);
        }
        temp = temp->next;
    }
}

double AvgOdd(PtrNode pHead) {
    int count = 0;
    float sum = 0;
    PtrNode temp = pHead;
    while (temp != NULL) {
        if ((int)temp->gpa % 2 != 0) {
            count++;
            sum += temp->gpa;
        }
        temp = temp->next;
    }
    if (count == 0) {
        return 0;
    }
    return sum / count;
}

void SortList(PtrNode* pHead) {
    if (*pHead == NULL || (*pHead)->next == NULL) {
        return;
    }
    PtrNode current, index;
    float tempGPA;
    char tempID[9];
    char tempName[31];
    current = *pHead;
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->gpa > index->gpa) {
                tempGPA = current->gpa;
                strcpy(tempID, current->id);
                strcpy(tempName, current->name);
                current->gpa = index->gpa;
                strcpy(current->id, index->id);
                strcpy(current->name, index->name);
                index->gpa = tempGPA;
                strcpy(index->id, tempID);
                strcpy(index->name, tempName);
            }
            index = index->next;
        }
        current = current->next;
    }
}

void AddStudent(PtrNode* pHead) {
    PtrNode newNode = CreateStudent();
    InsertStudent(pHead, newNode);
}

void DeleteStudent(PtrNode* pHead, char* id) {
    if (*pHead == NULL) {
        return;
    }
    if (strcmp((*pHead)->id, id) == 0) {
        PtrNode temp = *pHead;
        *pHead = (*pHead)->next;
        free(temp);
        return;
    }
    PtrNode current = *pHead;
    while (current->next != NULL) {
        if (strcmp(current->next->id, id) == 0) {
            PtrNode temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

int main() {
    PtrNode pHead = NULL;

    Init(pHead);
    IsEmpty(pHead);
    InputList(&pHead);

    printf("\n\n\tDANH SACH SINH VIEN:\n");
    OutputList(pHead);

    int nodeCount = Count(pHead);
    printf("\nSo luong sinh vien: %d\n", nodeCount);

    PtrNode maxNode = Max(pHead);
    if (maxNode != NULL) {
        printf("\nSINH VIEN CO DIEM TRUNG BINH CAO NHAT:\n");
        printf("\nMA SINH VIEN: %s\n", maxNode->id);
        printf("\nHO TEN : %s\n", maxNode->name);
        printf("\nDIEM TRUNG BINH: %.1f\n", maxNode->gpa);
    }

    float x;
    printf("NHAP DIEM TRUNG BINH X CAN TIM: ");
    scanf("%f", &x);
    PtrNode xNode = SearchX(pHead, x);
    if (xNode != NULL) {
        printf("\nSINH VIEN CO DIEM TRUNG BINH X:\n");
        printf("\nMA SINH VIEN: %s\n", xNode->id);
        printf("\nHO TEN: %s\n", xNode->name);
        printf("\nDIEM TRUNG BINH: %.1f\n", xNode->gpa);
    } else {
        printf("Khong tim thay sinh vien co diem trung binh x\n");
    }

    printf("\nSINH VIEN CO DIEM TRUNG BINH CHAN:\n");
    ShowEven(pHead);

    double avgOdd = AvgOdd(pHead);
    printf("\nGIA TRI TBC DIEM TRUNG BINH SINH VIEN LE: %.1f\n", avgOdd);

    SortList(&pHead); 
    AddStudent(&pHead);
	printf("\n\n\tDANH SACH SAU KHI THEM: \n");
	OutputList(pHead); 

    char idToDelete[9];
    printf("Nhap ma sinh vien muon xoa: ");
    scanf("%s", &idToDelete);
    DeleteStudent(&pHead, idToDelete);
    printf("\nDANH SACH SINH VIEN SAU KHI XOA: \n");
	OutputList(pHead); 

    return 0;
}

