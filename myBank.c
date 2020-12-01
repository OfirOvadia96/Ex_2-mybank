#include "myBank.h"
#include <stdio.h>
#define OPEN 1
#define CLOSE 0
#define STATUS 2
#define ACCOUNTS 50
#define fixLocation 901
double Bank [ACCOUNTS][STATUS];

void openAccount(){
int availability = -1;
 for(int i=0; i < ACCOUNTS; i++){
	if(Bank[i][0] == CLOSE){
	availability = i;
	break;
	}
 }
 if(availability ==-1){
	printf("There is not enough space to open a new account");
 }
 else{
 	double number = 0;
	printf("Please enter amount for deposit: ");
	scanf( "%lf" , &number);
	if(number <=0){
	printf("Failed to read the amount");
	return;
	}
	else{
	number = number*100;
	number = (int)number;
	number = (double)number/100;
	Bank[availability][0] = OPEN;
	Bank[availability][1] = number;
	int numberAccount = availability+fixLocation;
	printf("New account number is: %d \n" , numberAccount);
	}
   }	
}

void balance(int numberAccount){
if(Bank[numberAccount-fixLocation][0] == CLOSE){
	printf("This account is closed");	
  }
else{
	double money = Bank[numberAccount-fixLocation][1];
	printf("The balance of account number %d is: %0.2lf \n" , numberAccount , money);
  }
}

void deposite(int numberAccount){
 if(numberAccount > 950 || numberAccount < 901){
printf("invalid number");
 }
 else if(Bank[numberAccount-fixLocation][0] ==CLOSE){
printf("This account is close");
 }
 else{
double sum = 0;
printf("Please enter amount for deposit: ");
scanf("%lf" , &sum);
if(sum < 0){
printf("Invalid number!");
return;
}
   if(sum != 0){//stores the number up to two digits after the dot
	sum = sum*100;
	sum = (int)sum;
	sum = (double) sum/100;
	}
Bank[numberAccount-fixLocation][1] = Bank[numberAccount-fixLocation][1] + sum;
printf("The new balance is: %0.2lf " ,Bank[numberAccount-fixLocation][1]);
 }
}

void withdrawal(int numberAccount){
if(numberAccount > 950 || numberAccount < 901){
printf("Invalid number");
}
else if(Bank[numberAccount-fixLocation][0] == CLOSE){
printf("This account is closed");
}
else{
	double amount = 0;
	printf("Please enter the amount to withdraw: ");
	scanf("%lf" , &amount);
	if(amount < 0){
	printf("Invalid number!");
	return;
	}
	if(amount !=0){ //stores the number up to two digits after the dot
	amount = amount*100;
	amount = (int)amount;
	amount = (double)amount/100;
	}
	if(amount > Bank[numberAccount-fixLocation][1]){
	printf("Cannot withdraw more than the balance");
  	}
  	else{
  	Bank[numberAccount-fixLocation][1] = Bank[numberAccount-fixLocation][1] - amount;
  	printf("The new balance is: %0.2lf" ,Bank[numberAccount-fixLocation][1] );
  	}
 }
}

void closeAccount(int numberAccount){
if(numberAccount < 901 || numberAccount > 950){
printf("Invalid number");
}
else if(Bank[numberAccount-fixLocation][0] ==CLOSE){
 printf("This account is already closed");
 }
 else{ //Reset the location in the array that represents the account
 	Bank[numberAccount-fixLocation][1] =0;
 	Bank[numberAccount-fixLocation][0] =CLOSE;
 }
}

void interest(double n){
 if(n < 1 || n > 100 ){
	printf("Failed to read the interest rate");
 }
 else{
 n = n/100;
 for(int i=0; i<ACCOUNTS; i++){
 	if(Bank[i][0] ==OPEN){
  	Bank[i][1] = Bank[i][1] + Bank[i][1]*n;
  	Bank[i][1] = Bank[i][1]*100;
  	Bank[i][1] = (int)Bank[i][1];
  	Bank[i][1] = (double)Bank[i][1]/100;
  			}
  		}
 	}
}

void printBank(){
for(int i=0; i<ACCOUNTS; i++){
if(Bank[i][0] == OPEN){ //print only if the account is open
printf("The amount in account %d is: " , i+fixLocation);
printf("%0.2lf \n" , Bank[i][1]);
 	}
   }
}

void closeAllAndExit(){
 for(int i=0; i<ACCOUNTS; i++){ //Restets the bank (array)
 Bank[i][0] = CLOSE;
 Bank[i][1] = 0;
 }
}






