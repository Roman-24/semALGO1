//Roman Bitarovsk�
//Microsoft Visual Studio 2019
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

	char vojaci[1000] = {}, znak = 0;
	int pocet_mesiacov[1000] = {}, index_vstup = 0;

	//na��tanie vstupu
	while ( (znak = getchar()) != '\n' ) {
		if ( (isupper(znak))==1 ) { //na��tanie ve�k�ho p�smenka
			vojaci[index_vstup] = znak; //priradenie vojaka do pola s druhom vojakov
			scanf("%d", &pocet_mesiacov[index_vstup]); //na��tanie po�tu sk�senosti k pr�slu�n�mu vojakovi

			if (pocet_mesiacov[index_vstup] < 0 ) { //o�etrenie z�pornej hodnoty
				printf("Neplatny vstup: zaporna hodnota \n");
				return 0;
			}
			else { index_vstup++; }
		}	
	}
	
	int dlzka = strlen(vojaci); //zistenie dl�ky pola, obe polia s� v�dy rovnako dlh�

	int vymena = 0; //nasleduj dva loopy na prech�dzanie poliami a podmienky kedy sa maj� prehodi� hodnoty
	for( int index1=0; index1 <dlzka-1; index1++ )

		for( int index2= index1 +1; index2<dlzka; index2++ ) {

			if ( pocet_mesiacov[index1] > pocet_mesiacov[index2] ) { //zistenie �i m� nasta� v�mena vojakov

				if ( vojaci[index2] == vojaci[index1] ) { //hodnoty sa vymeniaa iba v pr�pade �e ak� na oboch miestach rovnak� vojaci
					vymena = pocet_mesiacov[index1]; //ulo�enie do premennej
					pocet_mesiacov[index1] = pocet_mesiacov[index2]; //pridelenie druhej hodnoty
					pocet_mesiacov[index2] = vymena; //pridelenie druhej hodnoty z druh�ho po�a pomocou premennej
				}
			}
		}

	int index_vypis = 0;
	while (index_vypis != dlzka) { //vyp�sanie v�stupu na obrazovku cez jeden index z oboch arrays ked�e �daje z rovnak�ho indexu v�dy patria jedn�mu vojakovi
		printf("%c%d ", vojaci[index_vypis], pocet_mesiacov[index_vypis]);
		index_vypis++;
	}

	return 0;
}