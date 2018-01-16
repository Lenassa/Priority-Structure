/**
 * @file EnsembleC.cpp
 * @author DENMAT Marion et DE SAUVECANNE Lois
 * @brief 
**/

#include <iostream>
#include <string>
#include "EnsembleC.hpp"

using namespace std;
	
EnsembleC::EnsembleC() {

	tete = nullptr;
	nb = 0; 
}

EnsembleC::~EnsembleC() {

	Maillon* courant = tete;
	Maillon* tampon; 
	for (int i = 0 ; i < nb ; i++){
	
		tampon = courant->suiv;
		delete courant;
		courant = tampon;
	}
	nb = 0;
	tete = nullptr;
}
		
bool EnsembleC::est_vide(){
		
	return (nb == 0) ? true:false;
}

bool EnsembleC::contient(string mot){

	if(!est_vide()){
			
		Maillon* courant = tete;
		while (courant->suiv != NULL){
		
			if (courant->contenu == mot) return true;
			courant = courant->suiv;
		}
	}
	return false;
}

void EnsembleC::ajoute(string mot){

	if(!est_vide()) {
		if(!contient(mot)){
	
			Maillon* courant = tete;
			while(courant->suiv != NULL) courant = courant->suiv;
			Maillon* inser = new Maillon(mot,nullptr);
			courant->suiv = inser;
			nb++;
		}else {
	
			//cout<<"Ce mot est déjà inséré !"<<endl;
		}
	} else {
		Maillon* inser = new Maillon(mot,nullptr);
		tete = inser;
		nb++;
	}
}

void EnsembleC::retire(string mot){

	if (contient(mot)){

		Maillon* courant = tete;
		Maillon* pred = courant; //initialisé au cas où le mot recherché serait en tete
		while(courant->contenu != mot) {
			
			pred = courant;
			courant = courant->suiv;
		}
		(courant == tete) ? (tete = courant->suiv):(pred->suiv = courant->suiv);
		delete courant;		
		nb -= 1;
	} else {
	
		cout<<"Ce mot n'est pas présent !"<<endl;
	}
}

string EnsembleC::contenu(){

	if (!est_vide()) {
	
		string res;
		Maillon* courant = tete;
		for(int i = 0 ; i < nb-1 ; ++i) {
		
			res += courant->contenu;
			res += ' ';
			courant = courant->suiv;
		}
		return res;
	}
	cout<<"Rien a afficher"<<endl;
	return "";
}
