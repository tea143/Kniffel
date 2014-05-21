/* 
 * File:   einerBisSechser.h
 * Author: ASUS
 *
 * Created on 20. Mai 2014, 14:09
 */

#ifndef EINERBISSECHSER_H
#define	EINERBISSECHSER_H

#include <string>
#include <vector>
#include "kategorie.h"

class EinerBisSechser : public Kategorie {

public:
	EinerBisSechser(int gesetzteZahl_, std::string name_);
	int punkteBerechnen(const std::vector<int> &augen);
	const std::string& getName() const;
	void setName(const std::string& name);
	//void setName();
	void setPunktzahl(int punktzahl);
	int getPunktzahl() const;
	int getGesetzteZahl() const;
	void setGesetzteZahl(int gesetzteZahl);

private:
	int gesetzteZahl;
	int punktzahl;
	std::string name;
	std::vector<int> wuerfelAugen;
	bool gesetzt;
};

#endif	/* EINERBISSECHSER_H */

