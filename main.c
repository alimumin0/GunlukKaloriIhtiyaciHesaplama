#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	setlocale(LC_ALL,"Turkish");
	int boy=0, kilo=0, yas=0, aktivite_duzey=0, kalori=0, secim=0, gunluk=0, cinsiyet=0, secim2=0;
	float katsayi=0;
	printf("HOSGELDÝNÝZ\n\n");
	printf("Hesap islemini yapmak icin boy, kilo ve yasinizi sirasiyla giriniz.\n(Boyunuzu santimetre cinsinden , kilonuzu kilogram cinsinden giriniz.)\n");
	scanf("%d,",&boy);
	scanf("%d,",&kilo);
	scanf("%d,",&yas);
	
	dongu:
	printf("Aktivite sýklýðýnýzý giriniz.\n\n 1-Hiç aktif deðil\n 2-Az aktif \n 3-Aktif, 3-4 gün antrenman \n 4-Çok aktif, 6-7 gün antrenman \n 5-Fazlasýyla aktif ,aðýr iþler,yüksek tempolu sporlar vs.\n");
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
		printf("Geçersiz deðer girdiniz. Lütfen tekrar giriniz.\n");
		goto dongu;
	}
	dongu2:
	printf("Cinsiyetinizi giriniz.\n(Erkek için 1, Kadýn için 2)\n");
	scanf("%d",&cinsiyet);
	
	if(cinsiyet==1)
		kalori=66+(6.2*kilo*2.204)+(12.7*boy*0.393)-(6.76*yas);
	else if(cinsiyet==2)
		kalori=665+(4,35*kilo*2.204)+(4.7*boy*0.393)-(4,7*yas);
	else	
	{
		printf("Geçersiz deðer girdiniz. Lütfen tekrar giriniz.\n");
		goto dongu2;
	}
	
	dongu3:
	printf("Kilo almayý hedefliyorsanýz 1 , kilo vermeyi hedefliyorsanýz 2, kilonuzu korumayý hedefliyorsanýz 3'e basýnýz.\n");
	scanf("%d",&secim);
	
	if(secim==1)
		gunluk=(kalori*katsayi)+300;
	else if(secim==2)
		gunluk=(kalori*katsayi)-300;	
	else if(secim==3)
		gunluk=(kalori*katsayi);
	else	
	{
		printf("Geçersiz deðer girdiniz. Lütfen tekrar giriniz.\n");
		goto dongu3;
	}
		
	printf("Günlük almanýz gereken kalori miktarý = %d\n",gunluk);
	
	
	FILE *kayit;
	kayit=fopen("kayit.txt","a");
	fprintf(kayit,"\nBoyunuz: %d\nKilonuz: %d\nYaþýnýz: %d\nAlmanýz Gereken Kalori: %d\n",boy,kilo,yas,gunluk);
	printf("Sizin için deðerlerinizi ve almanýz gereken kalori miktarýný kayýt ediyoruz.\n (kayit.txt ye girerek kontrol edebilirisiniz.)");

	
	return 0;
}
