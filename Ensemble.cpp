/*************************************************************************
Ensemble  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <stdio.h>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
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


crduAjouter Ensemble::Ajouter( int aAjouter )
{
	for(unsigned i(0); i < cardActuelle; i++ )
	{
		if ( aAjouter == ensemble[i])
		{
			return DEJA_PRESENT;
		}
	}

	if (cardActuelle == cardMax )
	{
		return PLEIN;
	}

	ensemble[cardActuelle] = aAjouter;
	return AJOUTE;
}


// type Ensemble::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
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

  //----------------------------------------------------- M�thodes prot�g�es
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
