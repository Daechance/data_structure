#include <stdio.h>

typedef struct infobook {
   int num;
   char book_name[20];
   int rent_day;
   int return_day;
}infobook;

void insert(infobook book[], int *n);
void Search_book(infobook book[], int n, int value, int select);
void print_Display(infobook book);
int main(void)
{
   int n=0, select, value;
   infobook book[20];

   while (1)
   {
      printf("\n 다음을 입력하시오. \n 1. 입력 \n 2. 검색 \n");
      scanf("%d", &select);

      if (select == 1) {
         insert(book, &n);
      }
      else if (select == 2) {
         printf("무엇으로 검색하시겠습니까? \n 1. 학번\n 2.대여일  \n3. 반납일");
         scanf("%d", &select);
         printf("값 입력: ");
         scanf("%d", &value);
         Search_book(book, n, value, select);
      }
      else {
         printf("해당수가 아닙니다 시스템 종료:");
         break;
      }
   }
   

}

void insert(infobook book[], int* n)
{
   printf("학번입력 : ");
   scanf("%d", &book[*n].num);
   printf("책이름입력 : ");
   scanf("%s", book[*n].book_name);
   printf("대여일 입력 : ");
   scanf("%d", &book[*n].rent_day);
   printf("반납일 입력 : ");
   scanf("%d", &book[*n].return_day);

   (*n)++;
}

void Search_book(infobook book[], int n, int value, int select)
{
   int i;
   switch (select)
   {
      case 1:
         for (i = 0; i <= n; i++) {
            if (book[i].num == value)
               print_Display(book[i]);
         }
         break;
      case 2:
         for (i = 0; i <= n; i++) {
            if (book[i].rent_day == value)
               print_Display(book[i]);
         }
         break;
      case 3:
         for (i = 0; i <= n; i++) {
            if (book[i].return_day == value)
               print_Display(book[i]);
         }
         break;
   }
}

void print_Display(infobook book)
{
   printf("\n\n------------------------------------------------\n");
   printf("학번        책이름      대여일    반납일\n");
   printf("%d %10s %10d %10d", book.num, book.book_name, book.rent_day, book.return_day);
   printf("\n------------------------------------------------\n\n");

}

//다음을 입력하시오.
// 1. 입력
// 2. 검색
//2
//무엇으로 검색하시겠습니까?
// 1. 학번
// 2.대여일
//3. 반납일1
//값 입력: 20190004
//
//
//------------------------------------------------
//학번        책이름       대여일    반납일
//20190004   자료구조   20220313   20220320
//------------------------------------------------
//
//
// 다음을 입력하시오.
// 1. 입력
// 2. 검색