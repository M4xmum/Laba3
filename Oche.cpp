#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


struct node
{
	char inf[256];  // полезная информация
	struct node* next; // ссылка на следующий элемент 
	struct node* prev;
};


struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];
	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	scanf("%s", s);
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);
	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента (в конец)*/
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


/* Просмотр содержимого списка. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("Имя - %s\n", struc->inf);
		struc = struc->next;
	}
	return;
}


/* Удаление элемента по содержимому. */
void del()
{
	struct node* struc = head; // указатель, проходящий по списку установлен на начало списка
	struct node* prev = NULL;// указатель на предшествующий удаляемому элемент

	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		printf("Список пуст\n");
		return;
	}

	head = struc->next; // установливаем голову на следующий элемент
	free(struc);  // удаляем первый элемент
	struc = head; // устанавливаем указатель для продолжения поиска



}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	char dele[256];
	while (1) {
		printf("\nВведите номер операции:\n1)Добавить эл. в очередь    2)Удалить элемент из очереди    3)Просмотреть очередь     4)Выйти\n");
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