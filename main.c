#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	setlocale(LC_ALL,"Turkish");
	int boy=0, kilo=0, yas=0, aktivite_duzey=0, kalori=0, secim=0, gunluk=0, cinsiyet=0, secim2=0;
	float katsayi=0;
	printf("HOSGELD�N�Z\n\n");
	printf("Hesap islemini yapmak icin boy, kilo ve yasinizi sirasiyla giriniz.\n(Boyunuzu santimetre cinsinden , kilonuzu kilogram cinsinden giriniz.)\n");
	scanf("%d,",&boy);
	scanf("%d,",&kilo);
	scanf("%d,",&yas);
	
	dongu:
	printf("Aktivite s�kl���n�z� giriniz.\n\n 1-Hi� aktif de�il\n 2-Az aktif \n 3-Aktif, 3-4 g�n antrenman \n 4-�ok aktif, 6-7 g�n antrenman \n 5-Fazlas�yla aktif ,a��r i�ler,y�ksek tempolu sporlar vs.\n");
	scanf("%d",&aktivite_duzey);
	
	
	if(aktivite_duzey==1)
	 katsayi = 1.2;
	else if(aktivite_duzey==2)
	 katsayi=1.375;	
	else if(aktivite_duzey==3)
	 katsayi=1.55;
	else if(aktivite_duzey==4)
	 katsayi= 1.725;
	else if(aktivite_duzey==5)
	 katsayi=1.9;
	else
	{
		printf("Ge�ersiz de�er girdiniz. L�tfen tekrar giriniz.\n");
		goto dongu;
	}
	dongu2:
	printf("Cinsiyetinizi giriniz.\n(Erkek i�in 1, Kad�n i�in 2)\n");
	scanf("%d",&cinsiyet);
	
	if(cinsiyet==1)
		kalori=66+(6.2*kilo*2.204)+(12.7*boy*0.393)-(6.76*yas);
	else if(cinsiyet==2)
		kalori=665+(4,35*kilo*2.204)+(4.7*boy*0.393)-(4,7*yas);
	else	
	{
		printf("Ge�ersiz de�er girdiniz. L�tfen tekrar giriniz.\n");
		goto dongu2;
	}
	
	dongu3:
	printf("Kilo almay� hedefliyorsan�z 1 , kilo vermeyi hedefliyorsan�z 2, kilonuzu korumay� hedefliyorsan�z 3'e bas�n�z.\n");
	scanf("%d",&secim);
	
	if(secim==1)
		gunluk=(kalori*katsayi)+300;
	else if(secim==2)
		gunluk=(kalori*katsayi)-300;	
	else if(secim==3)
		gunluk=(kalori*katsayi);
	else	
	{
		printf("Ge�ersiz de�er girdiniz. L�tfen tekrar giriniz.\n");
		goto dongu3;
	}
		
	printf("G�nl�k alman�z gereken kalori miktar� = %d\n",gunluk);
	
	
	FILE *kayit;
	kayit=fopen("kayit.txt","a");
	fprintf(kayit,"\nBoyunuz: %d\nKilonuz: %d\nYa��n�z: %d\nAlman�z Gereken Kalori: %d\n",boy,kilo,yas,gunluk);
	printf("Sizin i�in de�erlerinizi ve alman�z gereken kalori miktar�n� kay�t ediyoruz.\n (kayit.txt ye girerek kontrol edebilirisiniz.)");

	
	return 0;
}
