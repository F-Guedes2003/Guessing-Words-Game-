/*) Faça um subprograma que receba uma string por
parâmetro e troca todas suas consoantes por
asterisco (*), acessando os elementos por meio de
um ponteiro. A nova string deverá ser impressa no
programa principal.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getWord(char *string){
	printf("Word: ");
	gets(string);
	
	//tornando as letras da string todas minusculas
	strlwr(string);
}

void encryptWord(char *word){
	int i, len = strlen(word);
	
	//Percorre a palavra fonte para substituir as consoantes por *
	for(i = 0; i < len; i++){
		if(*word != 'a' && *word != 'e' && *word != 'i' && *word != 'o' && *word != 'u')
			*word = '*';
		word++;
	}
}

char *allocateWordMemory(char *sourceWord){
	return malloc((strlen(sourceWord) + 1) * sizeof(char));
}

int main(){
	char sourceWord[255], *userGuess, *encryptedWord;
	int pontuation = 0;

	while(1){
		//Recebe a palavra que deverá ser advinhada
		getWord(sourceWord);
		
		//Alocando a quantidade necessária de memória para as palavras
		encryptedWord = allocateWordMemory(sourceWord); 
		userGuess = allocateWordMemory(sourceWord);
		
		//Copia a palavra fonte para a variável da palavra encriptada
		strcpy(encryptedWord, sourceWord);
	
		//Criptografa a palavra que foi digitada
		encryptWord(encryptedWord);
		system("cls"); //Limpa o prompt para que o usuário não possa ver a palavra inteira no momento de advinhar
	
		//Printa a palavra encriptada
		printf("Encrypted Word: %s\n", encryptedWord);
		
		getWord(userGuess);
		
		if(strcmp(userGuess, sourceWord) == 0){
			pontuation++;
			printf("Você acertou a resposta!\nSua pontuação: %d\n\n", pontuation);
		}
		else
			printf("Você errou a resposta!\n\n");
	}
}