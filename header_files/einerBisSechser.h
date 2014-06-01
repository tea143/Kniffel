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
	EinerBisSechser(int, std::string);
	~EinerBisSechser();

	int punkteBerechnen(const std::vector<int>&);
	int getGesetzteZahl() const;
	void setGesetzteZahl(int gesetzteZahl);

private:
	int gesetzteZahl;
};

#endif	/* EINERBISSECHSER_H */

