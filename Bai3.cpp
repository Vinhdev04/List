#include"stdio.h"
#include"stdlib.h"


struct Student {
	char maSV[8];
	char hoTen[30];
	float diemTB;
	struct Student* pNext;
};
typedef struct Student* PtrNode;

PtrNode CreateStudent(){
	PtrNode newNode = (PtrNode)malloc(sizeof(struct Student));
	printf("Nhap ma SV: ");
	scanf("%s",newNode->maSV);
	printf("Nhap Ten SV: ");
	fflush(stdin);
	gets(newNode->hoTen);
	printf("Nhap diem TB: ");
	scanf("%f",&(newNode->diemTB));
	newNode->pNext = NULL;
	return newNode;
}

void InsertStudent(PtrNode* pHead,PtrNode newNode){
	if(*pHead == NULL){
		*pHead = newNode;
	}else{
		PtrNode temp = *pHead;
		while(temp->pNext != NULL){
			temp = temp->pNext;
		}
		temp->pNext = newNode;
	}
}

void InputList(PtrNode* pHead){
	int n;
	printf("Nhap so sinh vien: ");
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		PtrNode newNode = CreateStudent();
		InsertStudent(pHead,newNode);
	}
}

void ShowList(PtrNode pHead){
	PtrNode temp = pHead;
	while(temp != NULL){
		printf("Ma SV: %s\n",temp->maSV);
		printf("Ho Ten: %s\n",temp->hoTen);
		printf("Diem TB: %.1f\n",temp->diemTB);
		temp = temp->pNext;
	}
}

int Count(PtrNode pHead){
	int count = 0;
	PtrNode temp = pHead;
	while(temp!=NULL){
		count++;
		temp = temp->pNext;
	}
	return count;
}

PtrNode Max(PtrNode pHead){
	PtrNode maxNode = NULL;
	float maxValue = -1;
	PtrNode temp = pHead;
	while(temp!=NULL){
		if(temp->diemTB>maxValue){
			maxValue = temp->diemTB;
			maxNode = temp;
		}
		temp = temp->pNext;
	}
	return maxNode;
}
int main(){
	PtrNode pHead = NULL;

	InputList(&pHead);
	printf("\n\n\tDANH SACH SINH VIEN VUA NHAP: \n");
	ShowList(pHead);
	
	int nodeCount = Count(pHead);
	printf("\nSo luong sinh vien: %d\n",nodeCount);
	return 0;
}
