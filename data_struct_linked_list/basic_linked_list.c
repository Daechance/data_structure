#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * link;
}Node;

typedef struct List
{
	Node* head;
	Node* cur;
	Node* before;
}List;

void init(List *list);
void insert_data(List* list, int num);
void Display(List* list);
int Delete_data(List* list, int num);
void my_sort_data(List* list);

int main(void)
{
	Node* list = malloc(sizeof(Node));
	init(list);
	
	int selet = 0, num = 0;

	while (selet != 4)
	{
		printf("\n1�߰�\n2����\n3���\n4����\n");
		scanf_s("%d", &selet);
		switch (selet)
		{
		case 1:
			printf("�߰��� ������");
			scanf_s("%d", &num);
			insert_data(list, num);
			break;

		case 2:
			printf("������ ������");
			scanf_s("%d", &num);
			Delete_data(list, num);
			Display(list);
			break;

		case 3:
			Display(list);
			break;

		case 4:
			break;
		}
	}
}

void init(List* list)
{
	list->head = NULL;
	list->cur = NULL;
	list->before = NULL;
}

void insert_data(List* list, int num)
{
	Node* new_node = malloc(sizeof(Node));
	new_node->data = num;
	new_node->link = list->head; // ����� ����Ŵ
	list->head = new_node; //�ٽ� ����� �� ��带 ����Ŵ
}

void Display(List* list)
{
	list->cur = list->head;
	if (list->cur == NULL)
	{
		printf("�ƹ��͵� ���� �̱��");
	}
	else
	{
		while (list->cur->link != NULL)
		{
			printf("%d->", list->cur->data);
			list->cur = list->cur->link;
		}
		printf("%d", list->cur->data);
	}
}

int Delete_data(List *list,int num)
{
	if (list->head == NULL) 
	{
		printf("���Ḯ��Ʈ�� �����ϴ�.");
	}
	else
	{
		list->cur = list->head;
		while (list->cur != NULL) //Ž��
		{
			if (list->cur->data == num) //�����Ͱ� ���� ��쿡
			{
				if (list->cur == list->head) //������ �����Ͱ� ó���� ������
				{
					list->head = list->head->link; //��� ����ĭ �̵�
				}
				else
				{
					list->before->link = list->cur->link; //�߰��̳� ���� �ִٸ� cur �� �ǳʶٰ� cur �� ����ĭ���� 
				}
				free(list->cur);
				return 1;
			}
			else//��ã���� ��ĭ�� Ž��
			{
				list->before = list->cur;
				list->cur = list->cur->link;
			}
		}
	}
}

void my_sort_data(List* list)
{
	list->cur = list->head;
	list->before = list->head;
	
	if (list->cur == NULL)
	{
		
	}
}