#include<stdio.h>

typedef int keyType;
typedef float otherType;

typedef struct{
	keyType key;
	otherType other;
} recordType;

//Swap function

void Swap(recordType &x, recordType &y){
	recordType tmp;
	tmp = x;
	x = y;
	y = tmp;
}

void SelectionSort(recordType a[], int n){
	int i, j, lowIndex;
	keyType lowKey;
	for(i=0; i<=n-2; i++){
		lowKey = a[i].key;
		lowIndex = i;
		for(j=i+1; j<=n-1; j++){
			if(a[j].key < lowKey){
				lowKey = a[j].key;
				lowIndex = j;
			}
		}
		
		Swap(a[i], a[lowIndex]);
		
	}
}

main(){
	recordType a[100];
	int n, i;
	FILE *file = fopen("./number.txt", "r");
	//n = so luong phan tu 
	fscanf(file, "%d", &n);
	
	for(i = 0; i <= n-1; i++){
		fscanf(file, "%d", &a[i]);
	}
	
	//day so ban dau
	printf("day so ban dau \n");
	for(i=0; i<=n-1; i++){
		printf("%d  ", a[i]);
	}
	printf("\n");
	//day sau khi selection sort
	printf("day sau khi sap xep chon \n");
	SelectionSort(a, n);
	for(i = 0; i<=n-1; i++){
		printf("%d  ", a[i]);
	}
	
}




