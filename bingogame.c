#include <stdio.h>
#include <stdlib.h>

#define max_size 5

void intro();
void Make_Bingo_board(int **ary);
void Print_input_zero(int **ary);

int main(void)
{	
	int i;
	int **ary = (int**)malloc(sizeof(int*) *max_size);
    
    for (int i = 0; i < max_size; i++)
        ary[i] = (int*)malloc(sizeof(int) *max_size); 

	Make_Bingo_board(ary);
	Print_input_zero(ary);

	return 0;
	
}

void intro()
{
	printf("행열 값을 0으로 바꿔 드립니다.\n");
	printf("-1 -1 입력시 종료\n\n");
}

void Make_Bingo_board(int **ary)
{	
	int check_num = 0;
	int check_ary[26] = {0};

	int i,j,row,col;

	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			check_num = rand() % 25 + 1;
			if(check_ary[check_num] == 0){
				ary[i][j] = check_num;
				check_ary[check_num] = 1;
			}else if(check_ary[check_num] == 1){
				j--;
				continue;
			}
		}
	}
}	

void Print_input_zero(int **ary)
{	
	int i, j, row, col;

	while(1){

		intro();
		for(i = 0; i < 5; i++){
				for(j = 0; j < 5; j++){
					printf("%d\t",ary[i][j]);
				}
				printf("\n\n");
		}

		scanf("%d %d",&row,&col);
		ary[row][col] = 0;

		if(row == -1 && col == -1) {
			printf("빙고게임 종료.");
			break;
		}

	}

}