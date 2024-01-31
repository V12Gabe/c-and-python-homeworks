#include <iostream>
#include <string>

using namespace std;


class Rajz {
    string szin;
    unsigned meret;

public:
    Rajz(const string& szin, unsigned meret): szin(szin), meret(meret == 0 ? 1 : meret) {}

    Rajz operator&(const Rajz& masik) const {
        Rajz uj = *this;

        if (this->szin == masik.szin) {
            uj.meret += masik.meret;
        }

        return uj;
    }

    operator string() const {
        return szin;
    }

    virtual ~Rajz() = default;
};

class Felho {
    bool szomoru;

public:
    Felho(bool szomoru): szomoru(szomoru) {}

    Felho& operator!() {
        szomoru = !szomoru;
        return *this;
    }

    virtual ~Felho() {}
};

class FelhoRajz: public Felho, public Rajz {
protected:
    bool specialis;

public:
    FelhoRajz(): Felho(false), Rajz("feher", 1) {}

    FelhoRajz(const string& szin, unsigned int meret, bool specialis):
            Felho(false), Rajz(szin, meret), specialis(specialis) {}
};

class Tabla {
    FelhoRajz* felhok;

public:
    unsigned aktualis_felhok;
    unsigned max_felhok;

    unsigned eredeti;

public:
    Tabla(unsigned max_felhok): aktualis_felhok(0), max_felhok(max_felhok), eredeti(max_felhok) {
        felhok = new FelhoRajz[max_felhok];
    }

    Tabla& operator+=(const FelhoRajz& rajz) {
        if (aktualis_felhok == max_felhok) {
            return *this;
        }

        felhok[aktualis_felhok] = rajz;
        aktualis_felhok++;

        return *this;
    }

    Tabla& operator++() {
        FelhoRajz* uj_felhok = new FelhoRajz[max_felhok + eredeti];
        max_felhok += eredeti;

        for (unsigned i = 0; i < aktualis_felhok; i++) {
            uj_felhok[i] = felhok[i];
        }

        delete[] felhok;
        felhok = uj_felhok;

        return *this;
    }

    Tabla operator++(int) {
        Tabla regi = *this;
        operator++();
        return regi;
    }

    virtual ~Tabla() {
        delete[] felhok;
    }

    Tabla(const Tabla& masik) {
        aktualis_felhok = masik.aktualis_felhok;
        max_felhok = masik.max_felhok;
        eredeti = masik.eredeti;

        felhok = new FelhoRajz[max_felhok];
        for (unsigned i = 0; i < aktualis_felhok; i++) {
            felhok[i] = masik.felhok[i];
        }
    }

    Tabla& operator=(const Tabla& masik) {
        if (this == &masik) {
            return *this;
        }

        delete[] felhok;

        aktualis_felhok = masik.aktualis_felhok;
        max_felhok = masik.max_felhok;
        eredeti = masik.eredeti;

        felhok = new FelhoRajz[max_felhok];
        for (unsigned i = 0; i < aktualis_felhok; i++) {
            felhok[i] = masik.felhok[i];
        }

        return *this;
    }
};

void rajzokkal_provokal(Tabla& tabla, FelhoRajz** felhok) {
    int db = 0;
    for (int i = 0; felhok[i] != nullptr; i++) {
        if (tabla.aktualis_felhok == tabla.max_felhok) {
            if (db == 2) {
                return;
            }

            ++tabla;
            db++;
        }

        tabla += *felhok[i];
    }
}