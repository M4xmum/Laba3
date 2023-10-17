#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


struct node
{
	char inf[256];  // �������� ����������
	int prioritet;
	struct node* next; // ������ �� ��������� ������� 
};


struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� �������� ������
int dlinna = 0;



// ������� ���������� ��������, ��������� ������
void spstore(void), review(void), del(char* name);

char find_el[256];
struct node* find(char* name); // ������� ���������� ��������
struct node* get_struct(void); // ������� �������� ��������



struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];
	int prior = 0;
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
	int prior = 0;
	int k = 0;
	struct node* p = NULL;
	p = get_struct();
	printf("������� ��������� �������(�� ������ ����): \n");   // ������ ������
	scanf("%d", &prior);
	if (prior < 0)
	{
		while (prior < 0) {
			printf("������ �� ���� �����������, ��������� ����\n");
			scanf("%d", &prior);
		}
	}
	p->prioritet = prior;

	struct node* struc = head;
	struct node* prev = NULL;
	if (head != NULL) {
		dlinna = 0;
		while (struc) {
			if ((prior < struc->prioritet) && (struc == head)) {
				prev = struc;
				head = p;
				p->next = prev;
				return;
			}
			if ((prior == struc->prioritet) && (struc == head)) {
				if (struc->next == NULL) {
					last->next = p;
					last = p;
					return;
				}
				p->next = struc->next;
				struc->next = p;
				return;
			}

			if (prior >= struc->prioritet && struc->next == NULL) {
				last->next = p;
				last = p;
				return;
			}
			if (prior >= struc->prioritet && struc->next != NULL) {
				dlinna++;
			}
			else
				break;

			struc = struc->next;
		}
		if (dlinna != 0) {
			k = 0;
			struc = head;
			while (struc) {
				k++;
				if (dlinna == k && struc->next != NULL) {
					p->next = struc->next;
					struc->next = p;
					return;
				}


				struc = struc->next;
			}
		}
	}



	if (head == NULL && p != NULL)	// ���� ������ ���, �� ������������� ������ ������
	{

		head = p;
		last = p;
	}

	else if (head != NULL && p != NULL && head == last) // ������ ��� ����, �� ��������� � �����
	{

		last->next = p;
		last = p;
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
		printf("��� - %s, ��������� - %d\n", struc->inf, struc->prioritet);
		struc = struc->next;
	}
	return;
}




/* ����� �������� �� �����������. */
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	printf("������� �� ������\n");
	return NULL;
}

/* �������� �������� �� �����������. */
void del(char* name)
{
	struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������
	struct node* prev = NULL;// ��������� �� �������������� ���������� �������
	int flag = 0;      // ��������� ���������� ���������� �������� � ������

	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		printf("������ ����\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0) // ���� ��������� ������� - ������
	{
		flag = 1;
		head = struc->next; // ������������� ������ �� ��������� �������
		free(struc);  // ������� ������ �������
		struc = head; // ������������� ��������� ��� ����������� ������
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}

	while (struc) // ������ �� ������ � ����� ���������� ��������
	{
		if (strcmp(name, struc->inf) == 0) // ���� �����, ��
		{
			flag = 1;         // ���������� ���������
			if (struc->next)  // ���� ��������� ������� �� ��������� � ������
			{
				prev->next = struc->next; // ������ ���������
				free(struc);		    // �������  �������
				struc = prev->next; // ������������� ��������� ��� ����������� ������
			}
			else			// ���� ��������� ������� ��������� � ������
			{
				prev->next = NULL; // �������� ��������� ��������������� ��������
				free(struc);	// �������  �������
				return;
			}
		}
		else
		{
			prev = struc; // ������������� ��������� ��� ����������� ������
			struc = struc->next;
		}
	}

	if (flag == 0)				// ���� ���� = 0, ������ ������ ������� �� ������
	{
		printf("������� �� ������\n");
		return;
	}


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
			printf("������� ���������� ���������� ��������:");
			scanf("%s", dele);
			del(dele);
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