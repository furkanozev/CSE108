#include <stdio.h>
#include <string.h>
void replace_word (FILE* fname, char* wsrc, char* wdest)
{
	char arr[1000];
	while(fscanf(fname,"%s",arr)!=EOF){
		
		if(strcmp(wsrc,arr)==0){
			strcpy(arr,wdest);
		}
		printf("%s ",arr);
		fprintf(fname,"%s",arr);
	}
}

int main()
{
	FILE* input= fopen("file.txt","rw");
	char wsrc[20], wdest[20];
	printf("\n Enter the wsrc: ");
	scanf("%s", wsrc);
	printf("\n Enter the wdest: ");
	scanf("%s", wdest);
	replace_word(input, wsrc, wdest);
}