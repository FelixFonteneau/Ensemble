/*************************************************************************
Ensemble  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <stdio.h>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Ensemble::EstEgal(const Ensemble & unEnsemble) const {

	if (cardActuelle != unEnsemble.cardActuelle) {
		return false;
	}

	bool isEgal = false;
	for (unsigned i(0); i<cardActuelle; i++) {
		for (unsigned j(0); j<cardActuelle; j++) {
			if (ensemble[i] == unEnsemble.ensemble[j]) {
				isEgal = true;
			}
		}
		if (!isEgal) return false;
		isEgal = false;
	}
	return true;
}
crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble) const {

	if (cardActuelle>unEnsemble.cardActuelle) {
		return NON_INCLUSION;
	}

	if (this->EstEgal(unEnsemble)) {
		return INCLUSION_LARGE;
	}

	bool estInclus = false;
	for (unsigned i(0); i<cardActuelle; i++)
	{
		for (unsigned j(0); j<unEnsemble.cardActuelle; j++)
		{
			if (ensemble[i] == unEnsemble.ensemble[j])
			{
				estInclus = true;
			}
		}
		if (!estInclus) return NON_INCLUSION;
		estInclus = false;
	}
	return INCLUSION_STRICTE;
}

crduAjouter Ensemble::Ajouter( int aAjouter )
{
	for(unsigned i(0); i < cardActuelle; i++ )
	{
		if (aAjouter == ensemble[i])
		{
			return DEJA_PRESENT;
		}
	}

	if (cardActuelle == cardMax)
	{
		return PLEIN;
	}

	ensemble[cardActuelle] = aAjouter;
	cardActuelle++;
	return AJOUTE;
}

unsigned int Ensemble::Ajuster ( int delta ) {
	if(cardMax+delta<cardActuelle){
		cardMax = cardActuelle;
		return cardMax;
	}
	
	if( delta < 0 && delta*-1 > (int) cardMax ){
		cardMax = cardActuelle;
		return cardMax;
	}
	cardMax = cardMax + delta; 
	return cardMax;
}

bool Ensemble::Retirer (int element){
	for(unsigned i(0);i<cardActuelle;i++){
		if(ensemble[i] == element){
			for(unsigned j (i);j<cardMax-1;j++){
				ensemble[j] = ensemble[j+1];
			}
			cardActuelle--;
			cardMax=cardActuelle;
			return true;
		}
	}
	cardMax=cardActuelle;
	return false;
}

unsigned int Ensemble::Retirer (const Ensemble & unEnsemble){
	unsigned int cptElemRetrait = 0;
	unsigned int cardMaxEnsemble = cardMax;
	for(unsigned i (0) ;i<unEnsemble.cardActuelle;i++)
	{
		if(Retirer(unEnsemble.ensemble[i])){
		 	cptElemRetrait++;
		 }
	}
	cardMax = cardMaxEnsemble;
	return cptElemRetrait;
}

int Ensemble::Reunir( const Ensemble & unEnsemble)
{
#ifdef MAP
	cout << "Appel de Reunir" << endl;
#endif
	int signe = 1;
	int nbAjout = 0;
	for( unsigned i(0); i < unEnsemble.cardActuelle; i++ ) 
	{
#ifdef MAP
	cout << "le " << i << " eme element est : " << unEnsemble.ensemble[i] << endl;
#endif
		int retourAjout = (int)  Ajouter(unEnsemble.ensemble[i]);
		if (retourAjout == 2 ) // cas element ajouté
		{
			nbAjout++;
		}
		else if( retourAjout == 1) // cas liste pleine
		{
			Ajuster(1);
			int verif = (int)  Ajouter(unEnsemble.ensemble[i]);
			signe = -1;
			nbAjout++;
#ifdef MAP
	cout << "Liste pleine sur l'element " << i << endl;
	cout << "verification : " << verif << endl;
#endif
		}
			
	}	

	return nbAjout*signe;

}



void Ensemble::Afficher() {
	cout << cardActuelle << "\r\n";
	cout << cardMax << "\r\n";
	triEnsembleCroissant();
	cout << "{";
	if (cardActuelle != 0)
	{
		cout << ensemble[0];
		for (unsigned i(1); i<cardActuelle; i++)
		{
			cout << "," << ensemble[i];
		}
	}
	cout << "}\r\n";
}




// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//Ensemble Ensemble::operator = ( const Ensemble & unEnsemble )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Ensemble::Ensemble ( const Ensemble & ensemble )
// Algorithme :
//
//{
#ifdef MAP
//  cout << "Appel au constructeur de copie de <Ensemble>" << endl;
#endif
//} //----- Fin de Ensemble (constructeur de copie)


Ensemble::Ensemble(unsigned int cardinalite)
// Algorithme :
//
{
	this->cardMax = cardinalite;
	this->cardActuelle = 0;
	this->ensemble = new int[cardinalite];
#ifdef MAP
	cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
} //----- Fin de Ensemble

Ensemble::Ensemble(int t[], unsigned int nbElements)
{
	cardMax = nbElements;
	ensemble = new int[cardMax];
	if (nbElements == 0) {
		cardActuelle = 0;
		return;
	}
	cardActuelle = 1;
	ensemble[0] = t[0];
	bool estDansLensemble;
	for (unsigned i = 0; i < nbElements; i++)
	{
		estDansLensemble = false;
		for (unsigned j = 0; j<cardActuelle; j++)
		{
			if (ensemble[j] == t[i])
			{
				estDansLensemble = true;
			}
		}
		if (!estDansLensemble)
		{
			ensemble[cardActuelle] = t[i];
			cardActuelle++;
		}
	}
}

Ensemble::~Ensemble()
// Algorithme :
//
{
	delete[] ensemble;
#ifdef MAP
	cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
} //----- Fin de ~Ensemble


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées
void Ensemble::triEnsembleCroissant(void) {

	for (unsigned i(0); i<cardActuelle; i++)
	{
		int minimum = ensemble[i];
		int indexMinimal = i;
		for (unsigned j(i); j<cardActuelle; j++)
		{
			if (ensemble[j]<minimum)
			{
				minimum = ensemble[j];
				indexMinimal = j;
			}
		}
		ensemble[indexMinimal] = ensemble[i];
		ensemble[i] = minimum;
	}
}


//Ensemble & Ensemble::operator = ( const Ensemble & unEnsemble )
