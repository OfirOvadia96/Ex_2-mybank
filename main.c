#include <stdio.h>
#include "myBank.h"
int main(){
char c = ' '; // the operetion we need to get from the user

while(c != 'E'){
	printf("\nPlease choose a transaction type: ");
	printf("\n O-Open Account");
	printf("\n B-Balance Inquiry");
	printf("\n D-Deposit");
	printf("\n W-Withdrawal");
	printf("\n C-Close Account");
	printf("\n I-Interest");
	printf("\n P-Print");
	printf("\n E-Exit\n");
	scanf(" %c" , &c);

	switch(c){
		int x ; // use to check if we get valid number
		int n ; // use to get the number accounts
		double i ; // use for get interest 
	case 'O' :
		openAccount();
		break;
	case 'B' :
		printf("Please enter account number: ");
		x = scanf("%d" , &n);
		if(x != 1 || n<901 || n>950){
			printf("Failed to read the account number");
		}
		else{
			balance(n);
		}
		break;
		
	case 'D' :
		printf("Please enter account number: ");
		x = scanf("%d" , &n);
		if(x != 1 || n<901 || n>950){
			printf("Failed to read the account number\n");
		}
		else{
			deposite(n);
		}
		break;		
	
	case 'W' :

		printf("Please enter account number: ");
		x = scanf("%d" , &n);
		if(x != 1 || n<901 || n>950){
			printf("Failed to read the account number\n");
		}
		else{
			withdrawal(n);
		}	
		break;
		
	case 'C' :

		printf("Please enter account number: ");
		 x  = scanf("%d" , &n);
		if(x !=1 || n<901 || n>950){
			printf("invalid number\n");
		}
		else{
			closeAccount(n);
		}	
		break;
	
	case 'I' :
		printf("Please enter interest rate: ");
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
		printf("Invalid transaction type");
	}
}
return 0;
}
