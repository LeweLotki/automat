
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void help();

void stan();

void automat_monety();

int instruction();

void klient_monety();

float kupno();

void wydanie(float x);

struct automat
{

char nazwa[20];

float cena;

int ilosc;

};

struct automat  produkt[10];

int monety[12];

float value[6] = { 0.1 , 0.2 , 0.5 , 1.0 , 2.0 , 5.0 };


int main()
{
int cord, losowa, i;
float roznica;

srand(time(NULL));
losowa=rand()%11;

for(i=0;i<13;i++)
{
	losowa=rand()%50;
	monety[i]=losowa;
}

strcpy(produkt[0].nazwa,"cola");
strcpy(produkt[1].nazwa,"chipsy");
strcpy(produkt[2].nazwa,"woda");
strcpy(produkt[3].nazwa,"lizak");
strcpy(produkt[4].nazwa,"batonik");
strcpy(produkt[5].nazwa,"fois gras");

for(i=0;i<7;i++)
{
	losowa=rand()%10;
	produkt[i].ilosc=losowa;
}

produkt[0].cena=2.5;
produkt[1].cena=4.0;
produkt[2].cena=2.0;
produkt[3].cena=1.5;
produkt[4].cena=3.5;
produkt[5].cena=100.0;


while(1>0)
{
if(cord==0)
{
	help();
	cord=instruction();
}

if(cord==1)
{
	stan();
	cord=instruction();
}

if(cord==2)
{
	automat_monety();
	cord=instruction();
}

if(cord==3)
{
	klient_monety();
	cord=instruction();
}

if(cord==4)
{
	roznica=kupno();
	if(roznica > 0)
	{
		wydanie(roznica);
	}
	cord=instruction();
}

}
return 0;
}



void help()
{
printf("Wprowadz: \n 0 - aby wyswietlic pomoc \n 1 - aby wyswietlic informacje o produktach \n 2 - aby pokazac monety w automacie \n 3 - aby pokazac swoje monety \n 4 - aby dokonac zakupu \n");
}

void stan()
{

int i;

for(i=0;i<6;i++)
{
	printf("nazwa: %s \t ilosc: %d \t cena: %.2f \t symbol to: %d \n", produkt[i].nazwa, produkt[i].ilosc, produkt[i].cena, i+1);
}

}

int instruction()
{
int i=5;

while(i!=0 && i!=1 && i!=2 && i!=3 && i!=4)
{
printf("Wprowadz polecenie: \n");
scanf(" %d", &i);
if(i!=0 && i!=1 && i!=2 && i!=3 && i!=4)
{
	printf("Niepoprawne polecenie \n");
}
}

return i;
} 

void automat_monety()
{
	int i;
	float suma=0;
	printf("Stan monet w automacie: \n");
	for(i=0;i<7;i++)
	{
		suma=suma+(monety[i]*value[i]);
	}

	printf("ilosc 10-ogroszowek to: %d \t symbol to: 10 \n ilosc 20-groszowek to: %d \t symbol to: 20 \n ilosc 50-groszowek to: %d \t symbol to: 50  \n ilosc 1-zlotowek to: %d \t symbol to: 1  \n ilosc 2-zlotowek to: %d \t symbol: to 2  \n ilosc 5-zlotowek to: %d \t symbol to: 5 \n \n suma: %.2f \n", monety[0],monety[1],monety[2],monety[3],monety[4],monety[5],suma);
}

void klient_monety()
{
        int i;
        float suma=0;
	printf("Stan monet klienta: \n");
        for(i=0;i<7;i++)
        {
                suma=suma+(monety[i+6]*value[i]);
        }

	 printf("ilosc 10-ogroszowek to: %d \t symbol to: 10 \n ilosc 20-groszowek to: %d \t symbol to: 20 \n ilosc 50-groszowek to: %d \t symbol to: 50  \n ilosc 1-zlotowek to: %d \t symbol to: 1  \n ilosc 2-zlotowek to: %d \t symbol: to 2  \n ilosc 5-zlotowek to: %d \t symbol to: 5 \n \n suma: %.2f \n", monety[6],monety[7],monety[8],monety[9],monety[10],monety[11],suma);
}

float kupno()
{
int sym, temp;
float suma,reszta;
printf("Wprowadz symbol produktu, ktory chcesz kupic: ");
scanf(" %d", &sym);
sym=sym-1;
if(produkt[sym].ilosc > 0)
{
	printf("Wybrales %s \n",produkt[sym].nazwa);
}
else
{
	printf("Wybrany produkt jest niedostepny \n");
}
printf("Po kolei wprowadz symbole wrzucanych monet: \n");
while(produkt[sym].cena > suma)
{
	scanf("%d", &temp);
	if(temp==10)
	{
	if(monety[6] > 0)
	{
	suma=suma+value[0];
	monety[6]=monety[6]-1;
	monety[0]=monety[0]+1;
	}
	else
	{
	printf("Nie masz tylu monet \n");
	}
	}

        if(temp==20)
        {
        if(monety[7] > 0)
        {
        suma=suma+value[1];
        monety[7]=monety[7]-1;
        monety[1]=monety[1]+1;
        }
        else
        {
        printf("Nie masz tylu monet \n");
        }
        }
	
        if(temp==50)
        {
        if(monety[8] > 0)
        {
        suma=suma+value[2];
        monety[8]=monety[8]-1;
        monety[2]=monety[2]+1;
        }
        else
        {
        printf("Nie masz tylu monet \n");
        }
        }

        if(temp==1)
        {
        if(monety[9] > 0)
        {
        suma=suma+value[3];
        monety[9]=monety[9]-1;
        monety[3]=monety[3]+1;
        }
        else
        {
        printf("Nie masz tylu monet \n");
        }
        }

        if(temp==2)
        {
        if(monety[10] > 0)
        {
        suma=suma+value[4];
        monety[10]=monety[10]-1;
        monety[4]=monety[4]+1;
        }
        else
        {
        printf("Nie masz tylu monet \n");
        }
        }

        if(temp==5)
        {
        if(monety[11] > 0)
        {
        suma=suma+value[5];
        monety[11]=monety[11]-1;
        monety[5]=monety[5]+1;
        }
        else
        {
        printf("Nie masz tylu monet \n");
        }
        }


	if(temp!=10 && temp!=20 && temp!=50 && temp!=1 && temp!=2 && temp!=5)
	{
		printf("Niepoprawny symbol \n");

	}
printf("suma jest rowna: %.2f \n",suma);
}
printf("Kupiles %s \n", produkt[sym].nazwa);
printf("Stan twojego konta \n");
reszta=suma-produkt[sym].cena;
produkt[sym].ilosc=produkt[sym].ilosc-1;
klient_monety();
return reszta; 
}

void wydanie(float x)
{
int cord_1=0;

printf("reszta wyniosla %.2f \n", x);

while(monety[0] > 0 && x > 0)
{
x=x-value[0];
monety[0]=monety[0]-1;
monety[6]=monety[6]+1;
}
while(monety[1] > 0 && x > 0)
{
x=x-value[1];
monety[1]=monety[1]-1;
monety[7]=monety[7]+1;
}
while(monety[2] > 0 && x > 0)
{
x=x-value[2];
monety[2]=monety[2]-1;
monety[8]=monety[8]+1;
}
automat_monety();
}
