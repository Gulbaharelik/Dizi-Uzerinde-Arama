#include <stdio.h>
#include <stdlib.h>


// Binary search sýralý dizilerde kullanýlýr. Ve bubble sort algoritmasýda sýralama iþlemini gerçekleþtirir.
void bubbleSort(int dizi[], int n) {
    
	int i, j,temp; // Bütün deðerleri sýralamak için deðiþken belirlendi.
    
	for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (dizi[j] > dizi[j+1]) {
                temp = dizi[j]; // Temp geçici deðiþkendir .
                dizi[j] = dizi[j+1];
                dizi[j+1] = temp;
            }
        }
    }
}

int binarySearch(int dizi[],int sol,int sag,int x){
	
	while(sol<=sag){
		int bakilan=sol+(sag-sol)/2; // Bakilan olarak geçen deðer orta deðeri temsil eder .Bu deðer sayesinde karþýlaþtýrmalar yapýlýr.
		
		if(dizi[bakilan]==x)
			return bakilan;
		else if(dizi[bakilan]<x)
			sol =bakilan+1;
		else
			sag=bakilan-1;		
	}
	return -1; // Aranan eleman bulunamadýðýnda bu mesaj kullanýlýr.
}

int main(){
    printf("Dizide bulunan elemanlar : {4,8,3,84,47,76,9,24,68}");
    printf("\n\n");
    
	int dizi[]={4,8,3,84,47,76,9,24,68};
	int n =sizeof(dizi) / sizeof(dizi[0]); // Burada dizi boyutunu öðrenmek için kullanýlýr.
	int x ;
	
	printf("Aranan elemani giriniz:"); // Eleman kullanýcý tarafýndan klavyeden alýnýr.
	scanf("%d",&x);
	
	bubbleSort(dizi,n); 
	int sonuc = binarySearch(dizi,0,n-1,x); // Burada algoritmanýn son hali sonuc deðiþkenine atanýr.
	
	if(sonuc ==-1)
		printf("Eleman bulunamadi!!\n");
	else	
		printf("Eleman %d indeksinde bulundu.\n",sonuc);
		
	return 0;	
}
