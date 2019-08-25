#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define ALANBOYUT 8

int main() {
	setlocale(LC_ALL, "Turkish"); 
 int tahta[ALANBOYUT][ALANBOYUT];
 int tutSatir, tutSutun, tutSayi, gitSatir, gitSutun, alanla, kullanim;
 int yatay[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
 int dikey[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
 int i, j, k, a, b, x, y, eksik, eksikTut = 64, eksikYer,denemeTut = 0;
 int kontrol[12][12];
 int erisim[12][12] = {
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,2,3,4,4,4,4,3,2,0,0,
  0,0,3,4,6,6,6,6,4,3,0,0,
  0,0,4,6,8,8,8,8,6,4,0,0,
  0,0,4,6,8,8,8,8,6,4,0,0,
  0,0,4,6,8,8,8,8,6,4,0,0,
  0,0,4,6,8,8,8,8,6,4,0,0,
  0,0,3,4,6,6,6,6,4,3,0,0,
  0,0,2,3,4,4,4,4,3,2,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0};


 for (a = 0; a <= 7; a++) 
 {
  for (b = 0; b <= 7; b++) 
  {
    for (j = 0; j <= 11; j++)
      for (k = 0; k <= 11; k++)
      {
    	eksik = 0;
      	kontrol[j][k] = erisim[j][k];
	  }
    for (j = 0; j <= 7; j++)
      for (k = 0; k <= 7; k++) 
      {
      	tahta[j][k] = 0;
	  }
    kontrol[a + 2][b + 2] = 0;
    tahta[a][b] = 1;
    tutSatir = a;
    tutSutun = b;
    alanla = -1;
    i = 2;
    while (1) {
      kullanim = 10;
      for (tutSayi = 0; tutSayi <= 7; tutSayi++) {
      gitSatir = tutSatir + dikey[tutSayi];
      gitSutun = tutSutun + yatay[tutSayi];
      if (kontrol[gitSatir + 2][gitSutun + 2] != 0 && kontrol[gitSatir + 2][gitSutun + 2] < kullanim) {
        kullanim = kontrol[gitSatir + 2][gitSutun + 2];
        --kontrol[gitSatir + 2][gitSutun + 2];
        alanla = tutSayi;
      }
      }
      if (alanla == -1)
      break;
      tutSayi = alanla;
      tutSatir += dikey[tutSayi];
      tutSutun += yatay[tutSayi];
      tahta[tutSatir][tutSutun] = i;
      kontrol[tutSatir + 2][tutSutun + 2] = 0;
      alanla = -1;
      i++;
    }
    for (x = 2; x < 10; x++) {
      for (y = 2; y < 10; y++)
      {
    	printf("%4d", kontrol[x][y]);
	      if( kontrol[x][y] > 0)
		      { 
			  eksik++; 
			  }
	  }
      	printf("\n");
    }
    printf("\n");
    for (x = 0; x < 8; x++) 
	{
      for (y = 0; y < 8; y++)
      {
      printf("%4d", tahta[x][y]);
	  }
      printf("\n");
    }
    printf("Deneme: %d Kalan Kare: %d \n------------------------------------\n", ++denemeTut, eksik);
  if(eksik < eksikTut)
    {
	    eksikYer = denemeTut;
	    eksikTut = eksik;
	}
  }
 }
 if(eksikTut == 0)
 	printf("Tebrikler. Tüm karelere %d denemesinde ulaşıldı.\n", eksikYer);
 else
 	printf("En az %d kareye %d denemesinde ulaşıldı.\n",eksikTut,eksikYer);
 
getch();
puts("Talip ÇAKIR tarafından kodlanmıştır...");
return 0;
}
