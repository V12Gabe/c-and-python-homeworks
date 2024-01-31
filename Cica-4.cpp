//
// Created by Gábor on 2023. 10. 09..
//
#include <iostream>
using namespace std;

class Cica {
    string szin;
    bool aranyos;

    //getters
public:
    const string &get_szin() const {
        return szin;
    }

    bool is_aranyos() const {
        return aranyos;
    }

    //setter
    void set_szin(const string &szin) {
        Cica::szin = szin;
    }

    //constructors
    Cica():szin("Tarka"), aranyos(true) {}

    Cica(const string &szin, bool aranyos) : szin(szin), aranyos(aranyos) {}

    operator string() const {
        string aranyossag = aranyos ? "nagyon" : "";
        return "A " + szin + " szinu cica, ami " + aranyossag + " aranyos.";
    }

    Cica operator!() {
        aranyos = !aranyos;
        return *this;
    }

};

class Gazdi {
    string nev;
    Cica haziallatok[5];
    unsigned haziallatszam;

    //getters
public:
    const string &get_nev() const {
        return nev;
    }

    const Cica *get_haziallatok() const {
        return haziallatok;
    }

    unsigned int get_haziallatszam() const {
        return haziallatszam;
    }

    Gazdi(const string& nev): nev(nev), haziallatszam(0){}

    Gazdi& operator+=(const Cica& cica) {
        if(haziallatszam < 5) {
            haziallatok[haziallatszam] = cica;
            haziallatszam++;
        }
        return *this;
    }
};


