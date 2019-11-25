#include<stdio.h>
#include<conio.h>

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

void InsertionSort(recordType a[], int n){
	int i, j;
	for(i=0; i<=n-1; i++){
		j = i;
		while((j>0) && (a[j].key < a[j-1].key)){
			Swap(a[j], a[j-1]);
			j--;
		}
	}
}

void BubbleSort(recordType a[], int n){
	int i, j;
	for(i=0; i<n-2; i++){
		for(j=n-1; j>=i+1; j--){
			if(a[j].key < a[j-1].key){
				Swap(a[j], a[j-1]);
			}
		}
	}
}

main(){
	recordType a[100];
	int i, n;
	FILE *file = fopen("./number.txt", "r");
	fscanf(file, "%d", &n);
	for(i=0; i<=n-1; i++){
		fscanf(file, "%d", &a[i]);
	}
	
	printf("day so ban dau \n");
	for(i=0; i<=n-1; i++){
		printf("%d  ", a[i]);
	}
	printf("\n");
	SelectionSort(a, n);
	printf("day so sau khi SelectionSort \n");
	for(i=0; i<=n-1; i++){
		printf("%d  ", a[i]);
	}
	
	printf("\n");
	InsertionSort(a, n);
	printf("day so sau khi InsertionSort \n");
	for(i=0; i<=n-1; i++){
		printf("%d  ", a[i]);
	}
	
	printf("\n");
	BubbleSort(a, n);
	printf("day so sau khi Bubble \n");
	for(i=0; i<=n-1; i++){
		printf("%d  ", a[i]);
	}
}




