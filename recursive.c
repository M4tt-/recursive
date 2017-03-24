/***************************************************************************************\
*																					   *
* Title: recursive.c														   		   *
* Author: M. Runyon																	   *
* Last Updated: March 23rd, 2017													   *
* Description: This code is just me playing around with recursive functions for fun.   *
*			   I never covered them formally as a student, but I think they're cool.   *
*																					   *				
\***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int numDig(int n){
	int count = 0;
	if(n!=0){
		++count;
		return count+numDig(n/10);
	}else{
		return count;
	}
}

int factorial(int n){
	if(n == 0)
		return 1;
	else{
		if(n-1 != 0)
			return factorial(n-1)*n;
		else
			return n;
	}
}
void printUp2N(int n){
	if(n > 0){
		printUp2N(n-1);
		printf("%d ", n);
	}
}
int sum2N(int n){
	if(n>0)
		return sum2N(n-1)+n;
	return 0;

}

void printIntArray(int array[], int length){
	if(length>0){
		printIntArray(array,length-1);
		printf("%d ", array[length-1]);
	}
}

int sumDig(int n){
	if (n != 0)
       return (n%10 + sumDig(n/10));
    else
       return 0;
}

int sum2Dig(int n){
	int nd = numDig(n);
	if(nd%2!=0 && nd>1){
		int rem = n%10;
		n = n/10;
		if (n != 0)
	       return  rem+(n%10)+((n/10)%10)*10 + sum2Dig(n/100);
	    else
	       return 0;
	}else if(nd%2!=0 && nd<=1)
		return n;
	else
		if (n != 0)
	       return (n%10)+((n/10)%10)*10 + sum2Dig(n/100);
	    else
	       return 0;
}

int main(void){

	printf("Testing numDig()...\n");
	printf("Case 1: Calling numDig(0)\n");
	printf("Expected Result: 0\n");
	printf("Actual Result:   %d\n\n", numDig(0));
	printf("Case 2: Calling numDig(6)\n");
	printf("Expected Result: 1\n");
	printf("Actual Result:   %d\n\n", numDig(6));
	printf("Case 3: Calling numDig(16)\n");
	printf("Expected Result: 2\n");
	printf("Actual Result:   %d\n\n", numDig(16));
	printf("Case 4: Calling numDig(314465730)\n");
	printf("Expected Result: 8\n");
	printf("Actual Result:   %d\n\n", numDig(31446573));
	printf("Case 5: Calling numDig(2161)\n");
	printf("Expected Result: 4\n");
	printf("Actual Result:   %d\n\n", numDig(2161));
	printf("\n");
	
	printf("Testing factorial() ... \n");
	printf("Case 1: Calling factorial(0).\n");
	printf("Expected Result: 1\n");
	printf("Actual Result:   %d\n",factorial(0));
	printf("\n");
	printf("Case 2: Calling factorial(1).\n");
	printf("Expected Result: 1\n");
	printf("Actual Result:   %d\n",factorial(1));
	printf("\n");
	printf("Case 3: Calling factorial(4).\n");
	printf("Expected Result: 24\n");
	printf("Actual Result:   %d\n",factorial(4));
	printf("\n");
	printf("Case 4: Calling factorial(5).\n");
	printf("Expected Result: 120\n");
	printf("Actual Result:   %d\n",factorial(5));
	printf("\n");
	printf("Case 5: Calling factorial(6).\n");
	printf("Expected Result: 720\n");
	printf("Actual Result:   %d\n",factorial(6));
	printf("\n\n");

	printf("Testing printUp2N() ... \n");
	printf("Case 1: Calling printUp2N(1).\n");
	printf("Expected Result: 1\n");
	printf("Actual Result:   ");
	printUp2N(1);
	printf("\n");
	printf("Case 2: Calling printUp2N(5).\n");
	printf("Expected Result: 1 2 3 4 5\n");
	printf("Actual Result:   ");
	printUp2N(5);
	printf("\n");
	printf("Case 3: Calling printUp2N(10).\n");
	printf("Expected Result: 1 2 3 4 5 6 7 8 9 10 \n");
	printf("Actual Result:   ");
	printUp2N(10);
	printf("\n\n");

	printf("Testing sum2N() ... \n");
	printf("Case 1: Calling sum2N(2).\n");
	printf("Expected Result: 3\n");
	printf("Actual Result:   %d\n", sum2N(2));
	printf("Case 2: Calling sum2N(4).\n");
	printf("Expected Result: 10\n");
	printf("Actual Result:   %d\n", sum2N(4));
	printf("Case 3: Calling sum2N(18).\n");
	printf("Expected Result: 171\n");
	printf("Actual Result:   %d\n", sum2N(18));
	printf("\n\n");

	int array1[6] = {1,2,3,4,5,6};
	int array2[9] = {1,2,2,3,2,1,5,6,2};
	int array3[1] = {1};
	int array4[2] = {1,1};
	printf("Testing printIntArray() ... \n");
	printf("Case 1: Calling printIntArray([1,2,3,4,5,6], 6).\n");
	printf("Expected Result: 1 2 3 4 5 6\n");
	printf("Actual Result:   ");
	printIntArray(array1,6);
	printf("\n");
	printf("Case 2: Calling printIntArray([1,2,2,3,2,1,5,6,2], 9).\n");
	printf("Expected Result: 1 2 2 3 2 1 5 6 2\n");
	printf("Actual Result:   ");
	printIntArray(array2,9);
	printf("\n");
	printf("Case 3: Calling printIntArray([1], 1).\n");
	printf("Expected Result: 1 \n");
	printf("Actual Result:   ");
	printIntArray(array3,1);
	printf("\n");
	printf("Case 4: Calling printIntArray([1,1], 2).\n");
	printf("Expected Result: 1 1 \n");
	printf("Actual Result:   ");
	printIntArray(array4,2);
	printf("\n");
	
	printf("Testing sumDig()...\n");
	printf("Case 1: Calling sumDig(0)\n");
	printf("Expected Result: 0\n");
	printf("Actual Result:   %d\n", sumDig(0));
	printf("Case 2: Calling sumDig(6)\n");
	printf("Expected Result: 6\n");
	printf("Actual Result:   %d\n", sumDig(6));
	printf("Case 3: Calling sumDig(36)\n");
	printf("Expected Result: 33\n");
	printf("Actual Result:   %d\n", sumDig(31446573));
	printf("Case 4: Calling sumDig(29465)\n");
	printf("Expected Result: 26\n");
	printf("Actual Result:   %d\n", sumDig(29465));
	
		
	printf("Testing sum2Dig()...\n");
	printf("Case 1: Calling sum2Dig(0)\n");
	printf("Expected Result: 0\n");
	printf("Actual Result:   %d\n\n", sum2Dig(0));
	printf("Case 2: Calling sum2Dig(6)\n");
	printf("Expected Result: 6\n");
	printf("Actual Result:   %d\n\n", sum2Dig(6));
	printf("Case 3: Calling sum2Dig(36)\n");
	printf("Expected Result: 36\n");
	printf("Actual Result:   %d\n\n", sum2Dig(36));
	printf("Case 4: Calling sum2Dig(2946)\n");
	printf("Expected Result: 75\n");
	printf("Actual Result:   %d\n\n", sum2Dig(2946));
	printf("Case 5: Calling sum2Dig(294644)\n");
	printf("Expected Result: 119\n");
	printf("Actual Result:   %d\n\n", sum2Dig(294644));
	printf("Case 6: Calling sum2Dig(29465)\n");
	printf("Expected Result: 80\n");
	printf("Actual Result:   %d\n", sum2Dig(29465));
	printf("\n\n");
	
	printf("\n");

	return 0;
}
