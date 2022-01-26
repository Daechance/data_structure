#include <stdio.h>


int mystrlen(char str[])
{
	int i, count=0;

	while (str[count ++] != NULL);
	return count;

	/*
	for(i = 0; i < 100; i++){
		if(str[i] == '\0')
		break;
		if(str[i] != ' '){
			count++;
		}
	}
	
	return count;

	*/
}

char *mystrcpy(char dst[], char src[])
{
	int i = 0;

	while ((dst[i] = src[i ++]) != '\0');
    dst[i] = '\0';

	return dst;

	/*
	for(i = 0; i < 100; i++){
		if(dst[i] == '\0')
		break;
		dst[i] = src[i];
	}
	
	
	printf("src = %s",src);
	*/
}

int mystrcmp(char str1[],char str2[])
{
	int i = 0,j,s1_size=0,s2_size=0;

	while (str1[i] != '\0' && str2[i] != '\0') {
		if (str1[i] < str2[i]) return 1; // a b
		else if (str1[i] > str2[i]) return -1; // b a
		i ++; // a a 
	}

	if (str1[i] == '\0') return 1;
	return -1;

	/*
	for(i = 0; i < 100; i++){
		if(str1[i] == '\0')
		break;
		if(str1[i] != ' '){
			s1_size++;
		}
	}
	for(i = 0; i < 100; i++){
		if(str2[i] == '\0')
		break;
		if(str2[i] != ' '){
			s2_size++;
		}
	}

	if(s1_size == s2_size){
		printf("0");
		return 0;
	}else if(s1_size < s2_size){
		printf("-1");
		return -1;
	}else{
		printf("1");
		return 1;
	}
	*/
}

void My_strcat(char str1[], char str2[])
{
	int i = Mystrlen(str1), j = 0;

	while ((str1[i ++] = str2[j ++]) != '\0');
	str1[i] = '\0';

	return str1;
	
	/*
	int i, j = 0;
	int str1_size = Mystrlen(str1);

	for (i = str1_size, j = 0; str2[j] != '\0'; i ++, j ++)
		str1[i] = str2[j];

	printf("%s",str1);
	*/

}
int myindex(char str1[], char str2[])
{
	int i;

	for(i = 0; i < 100; i++){
		if(str1[i] == str2[i]){
			printf("%s",str2);
			break;
		}
	}

	return 0;
}
char *mystrtok(char *str1, char *deli)
{
	char *temp;
	static char *stored = NULL;
	int i;

	if (str1 == NULL) {
		if (stored == NULL) return NULL;
		temp = stored;
	}
	else
		stored = temp = str1;
	for (i = 0; stored[i] != '\0' && stored[i] != ' '; i ++);
	if (stored[i] == '\0') {
		stored = NULL;
		return temp;
	}
	stored[i] = '\0';
	stored = stored + i + 1;
	return temp;
}


char *mystrstr(char s1[],char s2[])
{
	int i,j;

	for(i = 0; i < mystrlen(s1) - mystrlen(s2) + 1; i++){
		for(j = 0; j < strlen(s2); j++){
			if(s1[i + j] != s2[j])
				break;	
		}
		if(j == strlen(s2))
			return s1 + i;
	}
	
	return NULL;
	
}