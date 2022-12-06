//Infix to Postfix using Stack
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 20
int Top=-1;
char stack[MAX];

void push(char value){
	if(Top==MAX-1){
		printf("STACK OVERFLOW!!\n");
	}
	else{
		Top++;
		stack[Top]=value;
	}
}

char pop(){
	if(Top==-1){
		printf("STACK IS EMPTY!!\n");
	}
	else{
		char item=stack[Top];
		Top--;
		return item;
	}
}

int is_operator(char op){
	if(op=='^' || op=='*' || op=='/' || op=='+' || op=='-'){
		return 1;
	}
	else{
		return 0;
	}
}

int precedence(char symbol){
	if(symbol=='^'){
		return 3;
	}
	else if(symbol=='*' || symbol=='/'){
		return 2;
	}
	else if(symbol=='+' || symbol=='-'){
		return 1;
	}
	else{
		return 0;
	}
}

int Infix_Edit(char array[30]){
	int i,j;
	char temp[100];
	for(i=0;i<strlen(array)-1;i++){
		if(array[i]=='('){
			array[i]=')';
		}
		else if(array[i]==')'){
			array[i]='(';
		}
		else{
			continue;
		}
	}
	printf("\nNow, infix Expression: ");
	puts(array);
}

void reverse(char array[]){
	int i,j;
	char temp[100];
	for(i=strlen(array)-1,j=0;i+1!=0;--i,++j) {
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
}
int Infix_to_Prefix(char infix[], char prefix[]){
	Infix_Edit(infix);
	reverse(infix);
	printf("\nReversed Expression: ");
	puts(infix);
	int i=0,j=0;
	char x;
	push('(');
	strcat(infix, ")");
	char item=infix[i];
	while(item !=NULL){
		if(item=='('){
			push(item);
		}
		else if(isdigit(item) || isalpha(item)){
			prefix[j]=item;
			j++;
		}
		else if(is_operator(item)==1){
		    x=pop();
		    while(is_operator(x)==1 && precedence(x)>=precedence(item)){
		    	prefix[j]=x;
		    	j++;
		    	x=pop();
			}
			push(x);
			push(item);
		}
		else if(item==')'){
			x=pop();
			while(x!= '('){
				prefix[j]=x;
				j++;
				x=pop();
			}
		}
		else{
			printf("\nINVALID INFIX EXPRESSION!!!!!!\n\n");
			getchar();
			exit(1);
		}
		i++;
		item=infix[i];
	}
	if(Top>0){
	    printf("\nINVALID INFIX EXPRESSION!!!!!!\n\n");
		getchar();
		exit(1);
	}
	prefix[j]='\0';
} 

int main(){
	char infix[MAX], prefix[MAX];
	//Infix expression should contains single letter variable and single digit constant only.
	printf("Enter Infix Expression: ");
	gets(infix);
	
	Infix_to_Prefix(infix, prefix);
	printf("Prefix Expression: ");
	puts(prefix); 
	reverse(prefix);
	printf("\nFinal Prefix Expression: ");
	puts(prefix);
	return 0;
}    
