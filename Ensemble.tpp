/**
 * @file Ensemble.tpp
 * @author DENMAT Marion et DE SAUVECANNE Lois
 * @brief Dans ce fichier nous implémentons les méthode déclarée dans la classe Ensemble.
**/

#include <iostream>
#include <string>
#include<sstream>


using namespace std;

/**
 * @brief constructeur de la classe Ensemble
 * 
 * @b Role : défini l'implémentation en chaînage simple vide
*/

template < typename Type >
Ensemble< Type >::Ensemble() {

	tete = nullptr;
	nb = 0; 
}

/**
 * @brief destructeur de la classe Ensemble
 * 
 * @b Role : detruit tous les maillons de l'ensemble pour le faire revenir à un chaî nage vide
*/

template < typename Type >
Ensemble< Type >::~Ensemble() {

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

/**
 * @brief fonction est_vide
 * 
 * @b Role : cette fonction renvoie vrai si l'ensemble est vide (si la taille (nb) = 0) sinon elle renvoie faux
 * 
 * @b Entrées : /
 * 
 * @b Sortie : true ou false
*/

template < typename Type >		
bool Ensemble< Type >::est_vide(){
		
	return (nb == 0) ? true:false;
}

/**
 * @brief fonction contient
 * 
 * @b Role : cette fonction permet de savoir si un un élément de type Type est présent dans l'ensemble (renvoie vrai ou faux).
 * 
 * @b Entrées : mot de type Type (nouveau type défini dans le fichier Ensemble.hpp)
 * 
 * @b Sortie : true ou false
 * 
 * @pre : l'ensemble n'est pas vide (testé)
*/

template < typename Type >
bool Ensemble< Type >::contient(Type mot){

	if(!est_vide()){
			
		Maillon* courant = tete;
		while (courant->suiv != NULL){
		
			if (courant->contenu == mot) return true;
			courant = courant->suiv;
		}
	}
	return false;
}

/**
 * @brief procédure ajoute
 * 
 * @b Role : cette procédure permet d'ajouter un élélment à la fin de notre chaînage, créer un nouveau maillon si l'ensemble est vide
 * 
 * @b Entrées : mot de type Type (nouveau type défini dans le fichier Ensemble.hpp)
 * 
 * @b Sortie : sortie utilisateur (message d'erreur) si l'élément est déjà inséré (une procédure ne retourne rien)  
 * 
 * @pre : l'élément n'est pas déjà dans l'ensemble (testé)
 * 
 * @post : est_vide == false et contient(élément) == true
*/

template < typename Type >
void Ensemble< Type >::ajoute(Type mot){

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

/**
 * @brief procédure retire
 * 
 * @b Role : cette procédure permet de retirer un élélment de l'ensemble
 * 
 * @b Entrées : mot de type Type (nouveau type défini dans le fichier Ensemble.hpp)
 * 
 * @b Sortie : sortie utilisateur (message d'erreur) si l'élément n'est pas présent (une procédure ne retourne rien)  
 * 
 * @pre : l'élément est présent dans l'ensemble (testé) 
 * 
 * @post : contient(élément) == false
*/

template < typename Type >
void Ensemble< Type >::retire(Type mot){

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

/**
 * @brief fonction contenu
 * 
 * @b Role : cette fonction affiche le contenu de l'ensemble via une chaîne de caractères
 * 
 * @b Entrées : /
 * 
 * @b Sortie : une chaîne de caractères  
 * 
 * @pre : 
 * 
 * @post : 
*/

template < typename Type >
string Ensemble< Type >::contenu(){

	if (!est_vide()) {
	
		stringstream res;
		Maillon* courant = tete;
		for(int i = 0 ; i < nb-1 ; ++i) {
		
			res << courant->contenu << " ";
			courant = courant->suiv;
		}
		return res.str();
	}
	cout<<"Rien a afficher"<<endl;
	return "";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
template < typename Type >
Ensemble<Type> intersection(Ensemble<Type> Ensa, Ensemble<Type> Ensb) {
	string mot, contenu=Ensa->contenu();
	bool estPresent;
	Ensemble<Type> Ens = new Ensemble<Type>();
	for (int i=0;i<(int)contenu.size();++i) {
		if (contenu[i]==' ') {
			estPresent=false;
			if(Ensb->contient( (Type)mot )) estPresent=true;
			if(estPresent) Ens.ajoute(Type(mot));
			mot="";
		} else {
			mot+=contenu[i];
		}
	}
	return Ens;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
template < typename Type >
Ensemble<Type> unionEns(Ensemble<Type> Ensa, Ensemble<Type> Ensb) {
	string mot, contenu=Ensb->contenu();
	bool estPresent;
	Ensemble<Type> Ens = Ensa;
	for (int i=0;i<(int)contenu.size();++i) {
		if (contenu[i]==' ') {
			estPresent=false;
			if(Ens.contient( (Type)mot )) estPresent=true;
			if(!estPresent) Ens.ajoute(Type(mot));
			mot="";
		} else {
			mot+=contenu[i];
		}
	}
	return Ens;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
template < typename Type >
Ensemble<Type> difference(Ensemble<Type> Ensa, Ensemble<Type> Ensb) {
	string mot, contenu1=Ensa->contenu(), contenu2=Ensb->contenu();
	bool estPresent;
	Ensemble<Type> Ens = new Ensemble<Type>();
	for (int i=0;i<(int)contenu1.size();++i) {
		if (contenu1[i]==' ') {
			estPresent=false;
			if(Ensb.contient( (Type)mot )) estPresent=true;
			if(!estPresent) Ens.ajoute(Type(mot));
			mot="";
		} else {
			mot+=contenu1[i];
		}
	}
	for (int i=0;i<(int)contenu2.size();++i) {
		if (contenu2[i]==' ') {
			estPresent=false;
			if(Ensa.contient( (Type)mot )) estPresent=true;
			if(!estPresent) Ens.ajoute(Type(mot));
			mot="";
		} else {
			mot+=contenu1[i];
		}
	}
	return Ens;
}
