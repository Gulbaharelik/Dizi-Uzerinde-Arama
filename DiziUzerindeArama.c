#include <stdio.h>
#include <stdlib.h>


// Binary search s�ral� dizilerde kullan�l�r. Ve bubble sort algoritmas�da s�ralama i�lemini ger�ekle�tirir.
void bubbleSort(int dizi[], int n) {
    
	int i, j,temp; // B�t�n de�erleri s�ralamak i�in de�i�ken belirlendi.
    
	for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (dizi[j] > dizi[j+1]) {
                temp = dizi[j]; // Temp ge�ici de�i�kendir .
                dizi[j] = dizi[j+1];
                dizi[j+1] = temp;
            }
        }
    }
}

int binarySearch(int dizi[],int sol,int sag,int x){
	
	while(sol<=sag){
		int bakilan=sol+(sag-sol)/2; // Bakilan olarak ge�en de�er orta de�eri temsil eder .Bu de�er sayesinde kar��la�t�rmalar yap�l�r.
		
		if(dizi[bakilan]==x)
			return bakilan;
		else if(dizi[bakilan]<x)
			sol =bakilan+1;
		else
			sag=bakilan-1;		
	}
	return -1; // Aranan eleman bulunamad���nda bu mesaj kullan�l�r.
}

int main(){
    printf("Dizide bulunan elemanlar : {4,8,3,84,47,76,9,24,68}");
    printf("\n\n");
    
	int dizi[]={4,8,3,84,47,76,9,24,68};
	int n =sizeof(dizi) / sizeof(dizi[0]); // Burada dizi boyutunu ��renmek i�in kullan�l�r.
	int x ;
	
	printf("Aranan elemani giriniz:"); // Eleman kullan�c� taraf�ndan klavyeden al�n�r.
	scanf("%d",&x);
	
	bubbleSort(dizi,n); 
	int sonuc = binarySearch(dizi,0,n-1,x); // Burada algoritman�n son hali sonuc de�i�kenine atan�r.
	
	if(sonuc ==-1)
		printf("Eleman bulunamadi!!\n");
	else	
		printf("Eleman %d indeksinde bulundu.\n",sonuc);
		
	return 0;	
}
