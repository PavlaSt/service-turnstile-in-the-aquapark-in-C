#pragma once
#ifndef FCE_H
#define FCE_H
#define _CRT_SECURE_NO_WARNINGS

void dobit_jednorazovy(struct Chip *chip100);

void dobit_abonentni(struct Chip* chip200);

void vstup_do_aquaparku(struct Chip* chip100, struct Chip* chip200);

void vystup_z_aquaparku(struct Chip* chip100, struct Chip* chip200, int* pocet_lidi, int* obrat);

void menu();

char volba_menu();

void operace(struct Chip* chip100, struct Chip* chip200, int *pocet_lidi,  int *obrat);



#endif