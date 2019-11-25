#include<stdio.h>;
#include<conio.h>;

typedef int keytype;
typedef float othertype;

typedef struct{
	keytype key;
	othertype other;
}recordtype;

void Swap(recordtype &x, recordtype &y){
	recordtype tmp;
	tmp = x;
	x = y;
	y = tmp;
}

//thu tuc pushdown
void PushDown(recordtype a[], int first, int last){
	int r = first;
	while(r <= (last - 1)/2){
		if(last == 2*r+1){
			if(a[r].key > a[last].key){
				Swap(a[r], a[last]);
			}
			r = last;
		}
		else if((a[r].key > a[2*r+1].key) && (a[2*r+1].key <= a[2*r+2].key)){
				Swap(a[r], a[2*r+1]);
				r = 2*r+1; 
		}
		else if((a[r].key > a[2*r+2].key) && (a[2*r+2].key < a[2*r+1].key)){
				Swap(a[r], a[2*r+2]);
				r = 2*r+2;
		}
		else r = last;
		}
	}


void HeapSort(recordtype a[], int n){
	int i;
	for(i = (n - 2) / 2; i >= 0; i--){
		PushDown(a, i, n-1);
	}
	for(i = n - 1; i >= 2; i--){
		Swap(a[0], a[i]);
		PushDown(a, 0, i-1);
	}
	Swap(a[0], a[1]);
}

main(){
	recordtype a[100];
	int i, n;
	FILE* file = fopen("./number.txt", "r");
	fscanf(file, "%d", &n);
	//printf("%d", n);
	for(i = 0; i <= n-1; i++){
		fscanf(file, "%d", &a[i]);
	}
	printf("day so ban dau \n");
	for(i = 0; i <= n-1; i++){
		printf("%d  ", a[i]);
	}
	printf("\n");
	printf("day so sai khi HeapSort \n");
	HeapSort(a,n);
	for(i = 0; i <= n-1; i++){
		printf("%d  ", a[i]);
	}
}
