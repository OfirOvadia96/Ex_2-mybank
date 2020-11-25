#include <stdio.h>
#include "myBank.h"
int main(){
char c = ' '; // the operetion we need to get from the user

while(c != 'E'){
	printf("\nTransation Type? ");
	scanf(" %c" , &c);

	switch(c){
		int x ; // use to check if we get valid number
		int n ; // use to get the number accounts
		double i ; // use for get interest 
	case 'O' :
		openAccount();
		break;
	
	case 'B' :
		printf("Account number? ");
		x = scanf("%d" , &n);
		if(x != 1 || n<900 || n>951){
			printf("invalid number");
		}
		else{
			balance(n);
		}
		break;
		
	case 'D' :
		printf("Account number? ");
		x = scanf("%d" , &n);
		if(x != 1 || n<900 || n>951){
			printf("invalid number\n");
		}
		else{
			deposite(n);
		}
		break;		
	
	case 'W' :

		printf("Account number? ");
		x = scanf("%d" , &n);
		if(x != 1 || n<900 || n>951){
			printf("invalid number\n");
		}
		else{
			withdrawal(n);
		}	
		break;
		
	case 'C' :

		printf("Account number? ");
		 x  = scanf("%d" , &n);
		if(x !=1 || n<900 || n>951){
			printf("invalid number\n");
		}
		else{
			closeAccount(n);
		}	
		break;
	
	case 'I' :
		printf("Interest rate? ");
		scanf("%lf" , &i);
		interest(i);
		break;
		
	case 'P' :
		printBank();
		break;
	
	case 'E':
		closeAllAndExit();
		break;
		
	default :
		printf("error! the operator is not correct");
	}
}
return 0;
}
