#include<stdio.h>

typedef int keyType;
typedef float otherType;

typedef struct{
	keyType key;
	otherType other;
} recordType;

void Swap(recordType &x, recordType &y){
	recordType tmp;
	tmp = x;
	x = y;
	y = tmp;
}

void BubbleSort(recordType a[], int n){
	int i, j;
	for(i = 0; i < n-2; i++){
		for(j = n-1; j >= i+1; j--){
			if(a[j].key < a[j-1].key){
				Swap(a[j], a[j-1]);
			}
		}
	}
}

main(){
	recordType a[100];
	int i, n;
	FILE* file = fopen("./number.txt", "r");
	fscanf(file, "%d", &n);
	//printf("%d", n);
	
	for(i = 0; i <= n-1; i++){
		fscanf(file, "%d", &a[i]);
	}
	printf("day so ban dau \n");
	for(i = 0; i <= n-1; i++ ){
		printf("%d  ", a[i]);
	}
	printf("\n");
	
	printf("day so sau khi BubbleSort \n");
	BubbleSort(a, n);
	for(i = 0; i <= n-1; i++ ){
		printf("%d  ", a[i]);
	}
}
