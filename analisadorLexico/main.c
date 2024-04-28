#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lex.h"

#define MAX_LENGTH 100

int main()
{
	setlocale(LC_ALL, "Portuguese_Brasil");
	FILE *filePointer;
	filePointer = fopen("input.txt", "r");
	if (filePointer == NULL)
	{
		printf("ERRO! O arquivo não foi aberto!\n");
		return 0;
	}
	char dataToBeRead[MAX_LENGTH];
	while (fgets(dataToBeRead, MAX_LENGTH, filePointer) != NULL)
	{
		lexicalAnalyzer(dataToBeRead);
	}
	fclose(filePointer);
	return (0);
}
