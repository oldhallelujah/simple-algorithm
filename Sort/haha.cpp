//QuickSort
 int FindPivot(recordtype a[],int i,int j){
 	keytype firstkey;
 	int k;
 		k=i+1;
 		firstkey = a[i].key;
 	while ((k<= j)&& (a[k].key==firstkey)) k++;
 		if(k>j) return -1;
 		if(a[k].key>firstkey) return k;
 	return i;
 }
 int Partition(recordtype a[],int i ,int j,keytype pivot){
 	int L,R;
 		L=i;
 		R=j;
 	while (L<=R){
 		while (a[L].key < pivot) L++;
 			while (a[R].key >=pivot) R--;
 			  if(L<R) Swap(a[L],a[R]);
 	}
	 return L;	
 }
  void QuickSort(recordtype a[],int i, int j){
  	keytype pivot;
  	 int pivotindex,k;
  	  pivotindex = FindPivot(a,i,j);
  	 if(pivotindex !=-1){
  	 	pivot = a[pivotindex].key;
  	 	 k= Partition(a,i,j,pivot);
  	 	  QuickSort(a,i,k-1);
  	 	  QuickSort(a,k,j);
  	 }
  }
QuickSort(a,0,n-1);
  
//heapsort
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
heapsort(a,n)

//tham an
typedef struct {
	char TenDV[20];
	float TL, GT;
	int PA;
} DoVat;


//doc file
DoVat * ReadFormFile(float *W, int *n){
	FILE *f;
	f= fopen("CaiBalo1.inp", "r");
	fscanf(f, "%f", W); //Xac dinh tron luong balo
	DoVat *dsdv;
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(f)){
		fscanf(f, "%f %f",&dsdv[i].TL, &dsdv[i].GT);
		fgets(dsdv[i].TenDV, 20, f);
		dsdv[i].TenDV[strlen(dsdv[i].TenDV) - 1] = '\0';
		dsdv[i].PA = 0;
		i++;
		
		dsdv=(DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));	
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void Swap(DoVat *x, DoVat *y){
	DoVat tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}



void BubbleSort(DoVat*dsdv,int n){
		int i,j;
		for(i=0;i<=n-2;i++)
			for(j=n-1;j>=i+1;j--){
				float DGJ=dsdv[j].GT/dsdv[j].TL;
				float DGJ_1=dsdv[j-1].GT/dsdv[j-1].TL;
				if(DGJ>DGJ_1)
					Swap(&dsdv[j],&dsdv[j-1]);
				        
			}
	}

void HienThiDSDV(DoVat *dsdv, int n, float W){
	int i;
	int a[4];
	float TongTL=0.0,TongGT=0.0;
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	printf("|%-3s|%-20s|%-9s|%-9s|%-9s|%-9s|\n", "STT", " Ten Do Vat","T.Luong", "Gia Tri", "Don Gia", "P. An");
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	
	for(i=0;i<n;i++){
		printf("|%-3d",i+1);
		printf("|%-20s",dsdv[i].TenDV);
		printf("|%-9.1f",dsdv[i].TL);
		printf("|%-9.1f",dsdv[i].GT);
		printf("|%-9.1f",dsdv[i].GT/dsdv[i].TL);
		printf("|%-9d|\n",dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
		a[i] = dsdv[i].PA;	
	}
		printf("|---|--------------------|---------|---------|---------|---------|\n");
		printf("Trong luong cua ba lo= %3.1f\n\n",W);
		printf("Tong trong luong= %3.1f \n\nTong gia tri= %3.1f\n\n", TongTL,TongGT);
		printf("CBL1(%d, %d, %d, %d)", a[0], a[1], a[2], a[3]);
		
}

void Greedy(DoVat dsdv[], int n , float W){
	int i;
	for(i=0;i<n;i++){
		dsdv[i].PA = (W/dsdv[i].TL);
		W = W - dsdv[i].PA * dsdv[i].TL;
	}
}

int main(){
	int n;
	float W;
	DoVat *dsdv;
	dsdv = ReadFormFile(&W, &n);
	BubbleSort(dsdv, n);
	Greedy(dsdv, n, W);
	HienThiDSDV(dsdv, n, W);
	free(dsdv);
	return 0; 
}

//nhanh can
DoVat*dsdv;
int n;
int x[MAX];
float W;
float CT;
float TGT;
float GiaLNTT;
float TLConLai;

//khoi tao nut goc
void init(){
	TLConLai = W;
	CT = TLConLai * (dsdv[0].GT/dsdv[0].TL);
	GiaLNTT = 0.0;
	TGT = 0.0;
}

//ghi nhan CT lon nhat
void GhiNhanKyLuc(){
	int i;
	if(GiaLNTT < TGT){
		GiaLNTT = TGT;
		for(i=0;i<n;i++){
			dsdv[i].PA=x[i];
		}
	}
}

//
void Try(int i){
	int j;
	for(j=TLConLai/dsdv[i].TL; j>=0; j--){
		//kiem tra neu j > hon so luong cho truoc thi lay so luong
		if(j > dsdv[i].SL){
			j = dsdv[i].SL;
		}
		TGT = TGT + j*dsdv[i].GT;
		TLConLai = TLConLai - j*dsdv[i].TL;
		CT = TGT + TLConLai * (dsdv[i+1].GT/dsdv[i+1].TL);
		if(CT > GiaLNTT){
			x[i] = j;
			if((i==n-1) || (TLConLai == 0)){
				GhiNhanKyLuc();
			}
			else{
				Try(i+1);
			}
		}
		x[i] = 0;
		TGT=TGT-j*dsdv[i].GT; //tra ve TGT ban dau
		TLConLai=TLConLai+ j*dsdv[i].TL; //tra ve TLConLai ban dau
	}
}


int main(){
	dsdv=ReadFromFile(&W,&n);
	BubbleSort(dsdv,n);
	init ();
	Try(0);
	inDSDV(dsdv,n,W);
	free(dsdv);
	return 0;
}
