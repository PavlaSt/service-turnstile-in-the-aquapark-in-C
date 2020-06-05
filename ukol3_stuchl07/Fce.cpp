
#include "Fce.h"
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

/* Deklarace struktury chip*/
struct Chip
{
	int cislo;
	int aktivni; // 0 - neaktivní, 1 - aktivní
	int typ; // 0 - jednorázový, 1 - abonentní
	int kredit;
	int pocet_hod;

};


void dobit_abonentni(struct Chip *chip200)
{
	char cislo[20];
	do
	{
		printf("Zadejte cislo abonentniho chipu (200): ");
		scanf("%s", cislo);		
	} while (!(atoi(cislo) == chip200->cislo));

	char castka[20];
	do
	{
		printf("Zadejte vkladanou castku: ");
		scanf("%s", castka);
	} while (!(atoi(castka) > 0));
	chip200->kredit += (atoi(castka));
	
	
	//printf("Zadejte vkladanou castku:");
	//scanf("%d", &chip200->kredit);
	
	printf("\nAktualni stav: \n---------------\n"
		"Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n\n",
		chip200->cislo,
		chip200->aktivni,
		chip200->typ,
		chip200->kredit);
}


void dobit_jednorazovy(struct Chip *chip100)
{
	
	
	
	char cislo[20];
	do
	{
		printf("Zadejte cislo jednorazoveho cipu (100): ");
		scanf("%s", cislo);		
	} while (!(atoi(cislo) == chip100->cislo));

	char hodiny[20];
	do
	{
		printf("Zadejte pocet hodin, na ktere chce zakaznik vstoupit (1, 2, nebo 3): ");
		scanf("%s", hodiny);
		
	} while (!((hodiny[0] == '1' || hodiny[0] == '2' || hodiny[0] == '3') && hodiny[1] == '\0'));
	
	
	if (hodiny[0] == '1') {
		chip100->kredit = 85;
		chip100->pocet_hod = 1;
	}
	else if(hodiny[0] == '2') {
		chip100->kredit = 145;
		chip100->pocet_hod = 2;

	}
	else {
		chip100->kredit = 200;
		chip100->pocet_hod = 3;
	}
	



	printf("\nAktualni stav: \n---------------\n"
		"Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n"
		"Pocet predplacenych hodin: %d\n\n",
		chip100->cislo,
		chip100->aktivni,
		chip100->typ,
		chip100->kredit,
		chip100->pocet_hod);

}

void vstup_do_aquaparku(struct Chip* chip100, struct Chip* chip200)
{
	char cislo[20];
	do
	{
		printf("\nVstup do aquaparku\nZadejte cislo chipu (100 nebo 200): ");
		scanf("%s", cislo);
	} while (!((atoi(cislo) == (chip100->cislo)) || (atoi(cislo) == chip200->cislo)));

	if (atoi(cislo) == chip200->cislo) {
		if (chip200->kredit >= 80) {
			chip200->aktivni = 1;
		}
		else {
			printf("\nNizky kredit. Nejdrive nabijte na minimalni castku 80 Kc.");			
		}		
	}
	else {
		if (chip100->kredit >= 85) {
			chip100->aktivni = 1;
		}
		else {
			printf("\nNizky kredit. Nejdrive nabijte na minimalni castku 85 Kc.");
		}		
	}

	printf("------------------------------\nAktualni stav vsech chipu:\n"
		"Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n",
		chip200->cislo,
		chip200->aktivni,
		chip200->typ,
		chip200->kredit);
	printf("------------------------------\n");
	printf("Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n"
		"Pocet predplacenych hodin: %d\n\n",
		chip100->cislo,
		chip100->aktivni,
		chip100->typ,
		chip100->kredit,
		chip100->pocet_hod);
}

void vystup_z_aquaparku(struct Chip* chip100, struct Chip* chip200, int* pocet_lidi, int* obrat)
{
	char cislo[20];
	int doplatek;
	
	do
	{
		printf("\nVystup do aquaparku\nZadejte cislo chipu (100 nebo 200): ");
		scanf("%s", cislo);
	} while (!((atoi(cislo) == (chip100->cislo)) || (atoi(cislo) == chip200->cislo)));

	if (atoi(cislo) == chip200->cislo) {
		if (chip200->aktivni == 1) {
			char minuty[20];
			do
			{
				printf("\nZadejte pocet minut (1-1080): ");
				scanf("%s", minuty);
			} while (!((atoi(minuty) > 0) && atoi(minuty) < 1080));
			if (atoi(minuty) <= 60) {
				printf("\n----KALKULACE-----\n");
				printf("Cena za vstup je 80 Kc.\n");
				chip200->kredit -= 80;
				printf("Zbyvajici kredit je %d Kc.\n", (int)chip200->kredit);
				(*pocet_lidi) += 1;
				(*obrat) += 80;
			}
			else {
				doplatek = (int)(atoi(minuty) - 60);
				if (doplatek <= (chip200->kredit - 80)) {
					printf("\n----KALKULACE-----\n");
					printf("Doplatek ve vysi  %d Kc uhrazen z kreditu\n", (int)doplatek);
					chip200->kredit -= (doplatek + 80);
					(*pocet_lidi)++;
					(*obrat) += (doplatek + 80);
				}
				else {
					doplatek = doplatek - (chip200->kredit - 80);
					printf("\n----KALKULACE-----\n");
					printf("Cast doplatku ve vysi  %d Kc uhrazena z kreditu\n", (int)(chip200->kredit - 80));
					if (doplatek <= 200) {
						doplatek = 0;
					}
					printf("Zbyva uhradit %d Kc. \n", doplatek);			
					(*pocet_lidi)++;
					(*obrat) += (doplatek + chip200->kredit);
					chip200->kredit = 0;

				}
			}
			chip200->aktivni = 0;
			printf("Zbyvajici kredit je %d Kc.\n", chip200->kredit);
		}
		else {
			printf("Tento chip neni aktivni. Nelze provest vystup. Zadejte spravne cislo chipu.\n");
		}
	}
	else {
		if (chip100->aktivni == 1) {
			char minuty[20];
			do
			{
				printf("\nZadejte pocet minut: ");
				scanf("%s", minuty);
				//printf("Minuty %d \n", atoi(minuty));
			} while (!((atoi(minuty) > 0) && atoi(minuty) < 1080));
			if (atoi(minuty) <= (chip100->pocet_hod * 60)) {
				printf("\n----KALKULACE-----\n");
				printf("Cena za vstup %d Kc uhrazena z kreditu.\n", chip100->kredit);
				(*pocet_lidi) += 1;
				(*obrat) += chip100->kredit;				
			}
			else {
				doplatek = (int)((atoi(minuty) - (chip100->pocet_hod * 60)) * 1.5);
				printf("\n----KALKULACE-----\n");
				printf("Predplacena doba prekrocena o %d minut. \n", (int)(atoi(minuty) - (chip100->pocet_hod * 60)));
				printf("Zbyva uhradit %d Kc. \n", doplatek);
				(*pocet_lidi) +=1;
				(*obrat) += (doplatek + chip100->kredit);
				
			}
			chip100->aktivni = 0;
			chip100->pocet_hod = 0;
			chip100->kredit = 0;
			printf("Zbyvajici kredit je %d Kc.\n", chip100->kredit);


	
		
		}
		else {
			printf("Tento chip neni aktivni. Nelze provest vystup.\n Zadejte spravne cislo chipu.");
		}

	}

	printf("------------------------------\nAktualni stav vsech chipu:\n "
		"Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n",
		chip200->cislo,
		chip200->aktivni,
		chip200->typ,
		chip200->kredit);
	printf("------------------------------\n");
	printf(
		"Cislo %d\n"
		"Aktivni: %d\n"
		"Abonentni: %d\n"
		"Kredit: %d Kc\n"
		"Pocet predplacenych hodin: %d\n\n",
		chip100->cislo,
		chip100->aktivni,
		chip100->typ,
		chip100->kredit,
		chip100->pocet_hod);
	//printf("\n---------------------------------\n"
		//"Prubezny stav: pocet lidi %d,  obrat\n Kc", *pocet_lidi, (*obrat));
	
	return ;
}

void menu()
{
	printf("\tMenu");
	printf("\n--------------------------------\n");
	printf("0 - KONEC\n1 - Dobit kredit na abonentni cip\n2 - Nastavit jednorazovy vstup do aquaparku\n3 - Vstup do aquaparku\n4 - Opusteni aquaparku\n");
	printf("\n--------------------------------\n");
}


char volba_menu() //naète øetìzec z klávesnice a zkontroluje zdali má správný formát
{
	char volba[20];
	do
	{
		printf("Volba menu (0-4): ");
		scanf("%s", volba);
	} while (!((volba[0] >= '0' && volba[0] <= '4') && volba[1] == '\0'));
	char znak = volba[0];

	return znak;
}



void operace(struct Chip* chip100, struct Chip* chip200, int* pocet_lidi, int* obrat)
{
	char znak;
	//int pocet_lidi = 0;
	double zisk;
	do
	{
		menu();
		znak = volba_menu();
		switch (znak)
		{
		case '1':
			dobit_abonentni(chip200);
			break;
		case '2':
			dobit_jednorazovy(chip100);
			break;
		case '3':
			vstup_do_aquaparku(chip100, chip200);
			break;
		case '4':
			vystup_z_aquaparku(chip100, chip200, pocet_lidi, obrat);
			break;
				
		default:
			break;
		}
	} while (znak != '0');
	
	zisk = (*obrat / *pocet_lidi);
	printf("\n--------STATISTIKY:---------------\n"		
		"Obrat je %d Kc.\n"
		"Celkovy pocet navstevniku je %d.\n"
		"Zisk na navstevnika je %5.2lf Kc.\n"
		"\n---------------------------------\n", *obrat, *pocet_lidi, zisk);




}

