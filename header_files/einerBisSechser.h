/* 
 * File:   einerBisSechser.h
 * Author: IFI
 *
 * Created on 20. Mai 2014, 14:09
 */

#ifndef EINERBISSECHSER_H
#define	EINERBISSECHSER_H

#include "kategorie.h"

class EinerBisSechser : public Kategorie {

public:
	//Konstruktor:
	EinerBisSechser(int, std::string);
	//Destruktor:
	~EinerBisSechser();

	virtual int punkteBerechnen(const std::vector<int>&) override;
	int getGesetzteZahl() const;
	void setGesetzteZahl(int gesetzteZahl);

private:
	int gesetzteZahl;
};

#endif	/* EINERBISSECHSER_H */

