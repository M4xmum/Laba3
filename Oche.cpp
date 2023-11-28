#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


struct node
{
	char inf[256];  // �������� ����������
	struct node* next; // ������ �� ��������� ������� 
	struct node* prev;
};


struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� �������� ������
int dlinna = 0;

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];
	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // �������� ������ ��� ����� ������� ������
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	printf("������� �������� �������: \n");   // ������ ������
	scanf("%s", s);
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);
	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}

/* ���������������� ���������� � ������ �������� (� �����)*/
void spstore(void)
{
	struct node* p = NULL;
	struct node* struc = head;
	struct node* prev = NULL;
	p = get_struct();
	if (head == NULL && p != NULL) {
		head = p;
		last = p;
	}

	else if (head != NULL && p != NULL) {
		struc = last;
		last->next = p;
		last = p;
		p->prev = struc;
	}
	return;
}


/* �������� ����������� ������. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		printf("��� - %s\n", struc->inf);
		struc = struc->next;
	}
	return;
}


/* �������� �������� �� �����������. */
void del()
{
	struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������
	struct node* prev = NULL;// ��������� �� �������������� ���������� �������

	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		printf("������ ����\n");
		return;
	}

	head = struc->next; // ������������� ������ �� ��������� �������
	free(struc);  // ������� ������ �������
	struc = head; // ������������� ��������� ��� ����������� ������



}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	char dele[256];
	while (1) {
		printf("\n������� ����� ��������:\n1)�������� ��. � �������    2)������� ������� �� �������    3)����������� �������     4)�����\n");
		scanf("%d", &n);
		switch (n) {
		case 1:
			spstore();
			break;
		case 2:
			del();
			break;
		case 3:
			review();
			break;
		case 4:
			return 0;
		}
	}
	_getch();
}