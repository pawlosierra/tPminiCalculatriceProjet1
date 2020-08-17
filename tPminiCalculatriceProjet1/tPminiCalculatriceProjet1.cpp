//tPminiCalculatriceProjet1
//TP-MINI CALCULATRICE/ PROJET 1
//Nom du Programmeur: JUAN PAWLO SIERRA ARIAS
//Version en cours:1.0
//Lieu de developpement: Institut Grasset

#include <iostream>	
#include<cstdlib>	//pour effacer le ecran
#include<conio.h>	//_getch
#include<string>	//pour chain de characters

using namespace std;

char etat, etat0;//option menu
const char E1 = '1';
const char E2 = '2';
const char E3 = '3';
const char E4 = 'Q';
char E5;
char car;
bool mauvaiseExpression;
int compteurDeNombre, resulta, compoperateur;
double resultat;


bool estChiffre(char car) {
	return ((car >= '0') && (car <= '9'));
	
}

bool estOperateur(char op) {
	return ((op == '+') || (op == '-') || (op == '*') || (op == '/'));
}

void compterLoperateur(char op) {
	switch (op) {
	case '+':compoperateur++; break;		
	case '-':compoperateur++; break;		
	case '*': compoperateur++; break;		
	case '/':compoperateur++; break;			
	}
}

void nouvelleOperation() {								//Cette procedure execute et affiche le resultat obtenu a partir de la version 1 de la calculatrice.
	string nombre;										//Definition des types de variables locales avec lesquelles nous allons travailler dans cette procedure.
	char operateur[50]= {};								//Initialisation variable.
	double numero[50] = {};
	compteurDeNombre = 0;
	mauvaiseExpression = false;
	resultat = 0;
	compoperateur = 0;
	double nombreentier = 0;
	car = '\0';
	int i = 0;
	int j = 0;
	cout << "\n PROJET1-MINI CALCULATRICE-VERSION (1)";
	cout << "\n -------------------------------------------" << endl;
	cout << "\n SAISIE DUNE OPERATION:";
	do {
		nombre = "";
		car = _getch();
		cout << car;
		while (estChiffre(car)){ //|| ((car >= 'a') && (car <= 'z'))  {
			nombre = nombre + car;
			car = _getch();
			cout << car;
		}
		if (nombre == ""); //mauvaiseExpression = true;	//true
		else {
			(compteurDeNombre++);
			if (compteurDeNombre > 0) {
				nombreentier = stoi(nombre);			//Fonction qui convertit une chaine de caracteres en entier.
				numero[i] = nombreentier;				//la variable numero, est une table dans laquelle je vais stocker des nombres que je vais convertir de chaine de caracteres en entier.
				i++;
			}
		}
		if (estOperateur(car)) {
			compterLoperateur(car);
			operateur[j] = car;							//la variable operateur est une table dans laquelle je vais stocker chacun des 4 caracteres qui sont valides pour faire une operation. Exemple:+,-,*,/.
			j++;
		}
		else {
			if (car != '=');//mauvaiseExpression = true;		
		}
	} while (car != '=');
	if (mauvaiseExpression) {
		cout << "\n-------------------------------------------\n";
		cout << "\n EXPRESSION INCORRECTE";
		cout << "\n-------------------------------------------\n";
	}
	else {
		int i = 0;
		for (int i = 0; i <= 1; i++) {					//le boucle for sera exexutee soulement 2 fois, puisque dans cette version du programme nous travaillerons avec 2 nombres entiers et un operateur.
			if (i == 0) {
				resultat = numero[i];

			}
			else {
				i = i - 1;
				switch (operateur[i]) {
				case '+':resultat = resultat + numero[i + 1]; i++; break;
				case '-':resultat = resultat - numero[i + 1]; i++; break;
				case '*':resultat = resultat * numero[i + 1]; i++; break;
				case '/':
					if (numero[i + 1] != 0) {
						resultat = resultat / numero[i + 1]; i++; break;
					}
					else {
						cout << "\n-------------------------------------------\n";
						cout << "\n EXPRESSION INCORRECTE";
						cout << "\n-------------------------------------------\n";
						resultat = 0;
					}
				default:i++; break;
				}
			}
		}
	}
	cout << resultat;
}

void prioriteParRang() {											//Cette procedure execute et affiche le resultat obtenu a partir de la version 2 de la calculatrice.		
	string nombre;													//Definition des types de variables locales avec lesquelles nous allons travailler dans cette procedure.
	char operateur[50] = {};										//Initialisation variable.
	double numero[50] = {};
	compteurDeNombre = 0;
	mauvaiseExpression = false;
	resultat = 0;
	compoperateur = 0;
	double nombreentier = 0;
	car = '\0';
	int i = 0;
	int j = 0;
	cout << "\n PROJET1-MINI CALCULATRICE-VERSION (2)";
	cout << "\n -------------------------------------------" << endl;
	cout << "\n SAISIE DUNE OPERATION:";
	do {
		nombre = "";
		car = _getch();
		cout << car;
		while (estChiffre(car)){ //|| ((car >= 'a') && (car <= 'z'))) {
			nombre = nombre + car;
			car = _getch();
			cout << car;
		}
		if (nombre == ""); //mauvaiseExpression = true;
		else {
			(compteurDeNombre++);
			if (compteurDeNombre > 0) {
				nombreentier = stoi(nombre);
				numero[i] = nombreentier;
				i++;
			}
		}
		if (estOperateur(car)) {
			compterLoperateur(car);
			operateur[j] = car;
			j++;
		}
		else {
			if (car != '='); //mauvaiseExpression = true;
		}
	} while (car != '=');
	if (mauvaiseExpression) {
		cout << "\n-------------------------------------------\n";
		cout << "\n EXPRESSION INCORRECTE";
		cout << "\n-------------------------------------------\n";
	}
	else {
		i = 0;
		for (int i = 0; i <= compteurDeNombre - 1; i++) {				//la variable compteurDenombre est un competeur qui determine le nombre de fois que le boucle for va faire une operation.
			if (i == 0) {												//c'est-a-dire avec le compteurDenombre, le boucle connaitra la quantite de nombres que nous avons dans la table numero.
				resultat = numero[i];
			}
			else {
				i = i - 1;
				switch (operateur[i]) {
				case '+':resultat = resultat + numero[i + 1]; i++; break;
				case '-':resultat = resultat - numero[i + 1]; i++; break;
				case '*':resultat = resultat * numero[i + 1]; i++; break;
				case '/':
					if (numero[i + 1] != 0) {
						resultat = resultat / numero[i + 1]; i++; break;
					}
					else {
						cout << "\n-------------------------------------------\n";
						cout << "\n EXPRESSION INCORRECTE";
						cout << "\n-------------------------------------------\n";
						resultat = 0;
						i = compteurDeNombre - 1;
					}
				default:i++; break;
				}
			}
		}
	}
	cout << resultat;
}

void seuleOperation() {												//Cette procedure appelle la procedure nouvelleOperation.
	do {															//C'est celui qui effectuera le calcul.
		system("cls");
		nouvelleOperation();										//Cette version gere uniquement 1 seule operation sur 2 nombres entiers.
		cout << "\n -------------------------------------------" << endl;
		cout << "\n Appuyez sur nimporte quelle touche pour continuer loperation" << endl;
		cout << "\n Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();
		etat = toupper(etat0);
	} while (etat != 'M');											//Le seul moyen de revenir au menu general est d'appuyer sur la lettre M.
}

void plusieursOperations() {										//Cette procedure appellera la procedure prioriteParRang.
	do {
		system("cls");
		prioriteParRang();
		cout << "\n -------------------------------------------" << endl;
		cout << "\n Appuyez sur nimporte quelle touche pour continuer loperation" << endl;
		cout << "\n Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();											//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);
	} while (etat != 'M');											//Le seul moyen de revenir au menu general est d'appuyer sur la lettre M.
}

void prioriteMultiplicationDivision() {								//Cette procedure est activee uniquement a titre informative. La version 3 de la calculatrice n'est pas prete.
	do {
		system("cls");												//Cette fonction vous permet de nettoyer l'ecran.
		cout << "\n PROJET1-MINI CALCULATRICE-VERSION (?)";
		cout << "\n -------------------------------------------" << endl;
		cout << "\n Bien vouloir attendre la version d'hivers 2020 du Logiciel" << endl;
		cout << "\n -------------------------------------------" << endl;
		cout << "\n Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();											//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);
	} while (etat != 'M');											//Le seul moyen de revenir au menu general est d'appuyer sur la lettre M.
}

void definirParametres() {											//Procedure utilisee pour le menu definirParametres.
	do {
		system("cls");												//Cette fonction vous permet de nettoyer l'ecran.
		cout << "\n  PROJET1-MINI CALCULATRICE";
		cout << "\n  -------------------------------------------" << endl;
		cout << "\n  PROPRIETES";
		cout << "\n  Nom du Programmeur: Juan Pawlo Sierra Arias";
		cout << "\n  Date de creation: 02/11/2019";
		cout << "\n  Lieu de de developpement: Institu Grasset";
		cout << "\n  Version en cours:1.0";
		cout << "\n  -------------------------------------------" << endl;
		cout << "\n  CHOISISSEZ LA VERSION DU LOGICIEL:" << endl;
		cout << "\n\t 1- Additionneuse a 1 seule operation";
		cout << "\n\t 2- Additionneuse Priorite par Rang de loperation";
		cout << "\n\t 3- Additionneuse Priorite * et /";
		cout << "\n\t choix:";
		cout << "\n";
		cout << "\n  Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();											//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);										//La fonction toupper permet de capitaliser les lettres escrites sur le clavier.
		switch (etat) {
		case E1:
			seuleOperation(); break;								//Cette option appelle la procedure seuleOperation. 
		case E2:
			plusieursOperations(); break;							//Cette option appelle la procedure plusOperations. 
		case E3:
			prioriteMultiplicationDivision(); break;				//Cette option appelle la procedure prioriteMultiplicationDivision.
		}
	} while (etat != 'M');											//Le seul moyen de revenir au menu general est d'appuyer sur la lettre M.
}

void aide() {														//Procedure utilisee pour le menu d'aide.
	do {
		system("cls");
		cout << "\n PROJET 1-MINI CALCULATRICE";
		cout << "\n -------------------------------------------" << endl;
		cout << "\n AIDE";
		cout << "\n Ce logiciel offre les fonctions de base d'une calculatrice";
		cout << "\n (Addition, Soustraction, Multiplication et Division)" << endl;
		cout << "\n 1- Le menu 1 vous amene a la saisie de l'operation";
		cout << "\n 2- Le menu 2 permet de definir les parametres du logiciel";
		cout << "\n 3- Le menu 3 vous propose l'aide que vous lisez actuellement";
		cout << "\n 4- La touche Q permet de quitter le programme" << endl;
		cout << "\n";
		cout << "\n Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();											//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);										//La fonction toupper permet de capitaliser les lettres escrites sur le clavier.
	} while (etat != 'M');
}

void quiterLogiciel() {												//Procedure utilisee pour Quiter le logiciel.										
	system("cls");													//Cette fonction vous permet de nettoyer l'ecran.
	cout << "\n PROJET 1-MINI CALCULATRICE";
	cout << "\n -------------------------------------------";
	cout << "\n FIN DU PROGRAM";
	cout << "\n Merci davoir utilise la MiniCalculatrice";
	cout << "\n -------------------------------------------";
	cout << "\n Appuyez sur une touche pour finir" << endl << endl;
	etat = _getch();												//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
	etat = E5;														//A la fin de cette procedure, la variable etat prend la valeur de E5. Cela vous permet de quitter le do-while.
}

void menu1(int option)												//Procedure utilisee pour le menu general.
{																	//Quand on lance le logiciel, le logiciel devrait afficher les menus suivants:
	do {
		system("cls");												//Cette fonction vous permet de nettoyer l'ecran.
		cout << "\n   PROJET 1-MINI CALCULATRICE";
		cout << "\n   -------------------------------------------";
		cout << "\n   MENU GENERAL";
		cout << "\n\t 1) Nouvelle operation";
		cout << "\n\t 2) Definir les parametres";
		cout << "\n\t 3) Aide";
		cout << "\n\t Q) Quitter le logiciel" << endl;
		cout << "\n   Choix:";
		etat0 = _getch();											//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);										//La fonction toupper permet de capitaliser les lettres escrites sur le clavier.
		switch (etat) {												//La variable etat0, stocke le caractere qui permettra de selectionner les options presentees dans le switch.
		case E1:
			seuleOperation();										//Cette option appelle la procedure seuleOperation.
			break;
		case E2:
			definirParametres();									//Cette option appelle la procedure definiParametres.
			break;
		case E3:
			aide();													//Cette option appelle la procedure aide.
			break;
		case E4:
			quiterLogiciel();										//Cette option appelle la procedure quiterLogiciel.		
			break;
		}
	} while (etat != E5);											
}

int main()															//Fonction principale. La fonction principale appelle la procedure du menu general.
{
	menu1(etat);
	return 0;
}
