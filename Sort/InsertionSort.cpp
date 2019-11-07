#include<stdio.h>

typedef int keyType;
typedef float otherType;

typedef struct{
	keyType key;
	otherType other;
}recordType;

void Swap(recordType &x, recordType &y){
	recordType tmp;
	tmp = x;
	x = y;
	y = tmp;
}

void InsertionSort(recordType a[], int n){
	int i, j;
	for(i = 1; i <= n-1; i++){
		j = i;
		while((j > 0) && (a[j].key < a[j-1].key)){
			Swap(a[j], a[j-1]);
			j--;
		}
	}
}

main(){
	recordType a[100];
	int i, n;
	FILE *file = fopen("./number.txt", "r");
	fscanf(file, "%d", &n);
	for(i = 0; i <= n-1; i++){
		fscanf(file, "%d", &a[i]);
	}
	printf("day so ban dau \n");
	for(i = 0; i <= n-1; i++){
		printf("%d  ", a[i]);
	}
	printf("\n");
	
	InsertionSort(a, n);
	for(i = 0; i <= n-1; i++) {
		printf("%d ", a[i]);
	}
}
