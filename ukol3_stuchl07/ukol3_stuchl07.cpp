// ukol3_stuchl07.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

/*****************************************************************
* Nazev programu: Obslužný turniket v aquaparku				     *
*																 *
*				Autor: Pavla Stuchlíková						 *
*																 *
*					Datum: 3.1.2020							     *
******************************************************************/

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "Fce.h"


/* Deklarace struktury chip*/
struct Chip
{
	int cislo;
	int aktivni; // 0 - neaktivní, 1 - aktivní
	int typ; // 0 - jednorázový, 1 - abonentní
	int kredit;
	int pocet_hod;

};

/* Instanciace struktury chip

struct Chip chip100;
struct Chip chip200;
*/



int main()
{
	//tisk hlavicky
	printf("\n Pavla Stuchlikova, stuchl07:\n Ukol 3: Obsluzny turniket v aquaparku \n ");
	printf("-------------------------------------------------------------------------------------\n");

	/* Instanciace struktury chip*/
	struct Chip chip100;
	struct Chip chip200;

	/*Inicializace chipů*/
	chip100.cislo = 100;
	chip100.aktivni = 0; 
	chip100.typ = 0; 
	chip100.kredit = 0;
	chip100.pocet_hod = 0;

	chip200.cislo = 200;
	chip200.aktivni = 0;
	chip200.typ = 1;
	chip200.kredit = 0;
	chip200.pocet_hod = -1;

	int obrat = 0;
	int pocet_lidi = 0;
	

	operace(&chip100, &chip200, &pocet_lidi,  &obrat);


	/* Vypsáni informací o chipech

	printf("Vypsani informaci o chipech\n\n");
	printf("Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n"
		"Pocet predplacenych minut: %d\n\n",
		chip100.cislo,
		chip100.aktivni,
		chip100.typ,
		chip100.kredit,
		chip100.pocet_hod);

	
	printf("Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n"
		"Pocet predplacenych minut: %d\n\n",
		chip200.cislo,
		chip200.aktivni,
		chip200.typ,
		chip200.kredit,
		chip200.pocet_hod);
		*/

	/*dobit_abonentni(&chip200);*/

	/* 1 načte řetězec z klávesnice a zkontroluje zdali má správný formát
	char cislo[20];
	do
	{
		printf("Zadejte cislo abonentniho chipu (200): ");
		scanf("%s", cislo);
		//} while (!(cislo[0] == '1' && cislo[1] == '0' && cislo[2] == '0' && cislo[3] == '\0'));
	} while (!(atoi(cislo) == chip200.cislo));

	printf("Zadejte vkladanou castku:");
	scanf("%d", &chip200.kredit);
	chip200.aktivni = 1;
	*/

	/*dobit_jednorazovy(&chip100);*/

	/*char cislo[20];
	do
	{
		printf("\nVstup do aquaparku\nZadejte cislo chipu (100 nebo 200): ");
		scanf("%s", cislo);
	} while (!((atoi(cislo) == (chip100.cislo)) || (atoi(cislo) == chip200.cislo)));

	if (atoi(cislo) == chip200.cislo) {
		chip200.aktivni = 1;
	}
	else {
		chip100.aktivni = 1;
	}

	printf("\nAktualni stav: \n---------------\n"
		"Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n\n",
		chip200.cislo,
		chip200.aktivni,
		chip200.typ,
		chip200.kredit);


	printf("\nAktualni stav: \n---------------\n"
		"Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n"
		"Pocet predplacenych hodin: %d\n\n",
		chip100.cislo,
		chip100.aktivni,
		chip100.typ,
		chip100.kredit,
		chip100.pocet_hod);
		*/


	/*vstup_do_aquaparku(&chip100, &chip200);*/

	/*char cislo[20];
	int doplatek;
	do
	{
		printf("\nVystup do aquaparku\nZadejte cislo chipu (100 nebo 200): ");
		scanf("%s", cislo);
	} while (!((atoi(cislo) == (chip100.cislo)) || (atoi(cislo) == chip200.cislo)));

	if (atoi(cislo) == chip200.cislo) {
		if (chip200.aktivni == 1) {
			char minuty[20];
			do
			{
				printf("\nZadejte pocet minut (1-1080): ");
				scanf("%s", minuty);
			} while (!((atoi(minuty) > 0)&& atoi(minuty) < 1080));
			if (atoi(minuty) <= 60) {
				printf("Cena za vstup je 80 Kc.\n");
				chip200.kredit -= 80;
				printf("Zbyvajici kredit je %d Kc.", (int)chip200.kredit);
			}
			else {
				doplatek = (int)(atoi(minuty) - 60);
				if (doplatek <= (chip200.kredit-80)) {
					printf("Doplatek ve vysi  %d Kc uhrazen z kreditu\n", (int)doplatek);
					chip200.kredit -= (doplatek+80);
				}
				else {
					doplatek = doplatek -(chip200.kredit-80);
					printf("Doplatek ve vysi  %d Kč uhrazen z kreditu\n", (int)(chip200.kredit - 80));
					printf("Zbyva uhradit %d Kč. \n", doplatek);
					chip200.kredit = 0;					
				}				
			}
		chip200.aktivni = 0;
		printf("Zbyvajici kredit je %d Kc.", chip200.kredit);
		}
		else {
			printf("Tento chip neni aktivni. Nelze provest vystup.\n Zadejte spravne cislo chipu.");
		}
	}
	else {
		if (chip100.aktivni == 1) {
			char minuty[20];
			do
			{
				printf("\nZadejte pocet minut: ");
				scanf("%s", minuty);
				printf("Minuty %d \n", atoi(minuty));
			} while (!((atoi(minuty) > 0) && atoi(minuty) < 1080));
			if (atoi(minuty) <= (chip100.pocet_hod*60)) {
				printf("Cena za vstup %d Kc uhrazena z kreditu.\n", chip100.kredit);
			}
			else {				
				doplatek = (int)((atoi(minuty) - (chip100.pocet_hod * 60)) * 1.5);
				printf("Predplacena doba prekrocena o %d minut. \n", (int)(atoi(minuty) - (chip100.pocet_hod * 60)));
				printf("Zbyva uhradit %d Kc. \n", doplatek);				
			}
		chip100.aktivni = 0;
		chip100.pocet_hod = 0;
		chip100.kredit = 0;
		printf("Zbyvajici kredit je %d Kc.", chip100.kredit);

		}
		else {
			printf("Tento chip neni aktivni. Nelze provest vystup.\n Zadejte spravne cislo chipu.");
		}
		
	}
	
	printf("\nAktualni stav: \n---------------\n"
		"Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n\n",
		chip200.cislo,
		chip200.aktivni,
		chip200.typ,
		chip200.kredit);

	
	printf("\nAktualni stav: \n---------------\n"
		"Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n"
		"Pocet predplacenych hodin: %d\n\n",
		chip100.cislo,
		chip100.aktivni,
		chip100.typ,
		chip100.kredit,
		chip100.pocet_hod);
	*/	

	/*vystup_z_aquaparku(&chip100, &chip200);*/
	
	//2 načte řetězec z klávesnice a zkontroluje zdali má správný formát
	/*
	char cislo[20];
	do
	{
		printf("Zadejte cislo jednorazoveho cipu (100): ");
		scanf("%s", cislo);
	//} while (!(cislo[0] == '1' && cislo[1] == '0' && cislo[2] == '0' && cislo[3] == '\0'));
	} while (!(atoi(cislo) == chip100.cislo));
	
	printf("Zadejte pocet hodin, na ktere chce zakaznik vstoupit (1, 2, nebo 3): ");
	scanf("%d", &chip100.pocet_hod);

	printf("Zadejte vkladanou castku:");
	scanf("%d", &chip100.kredit);
	chip100.aktivni = 1;
	


	printf("Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n"
		"Pocet predplacenych hodin: %d\n\n",
		chip100.cislo,
		chip100.aktivni,
		chip100.typ,
		chip100.kredit,
		chip100.pocet_hod);
		
		*/

	


    
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
