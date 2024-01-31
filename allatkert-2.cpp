#include <iostream>
#include <string>
using namespace std;

class Allat {
  unsigned jollakott;
  string nev;
public:
  Allat(string n  = "allat", unsigned j = 10) : jollakott(j), nev(n) { }
  
  const string& get_nev() const {
    return nev;
  }

  unsigned operator!() const {
    return jollakott;
  }

  Allat operator++(int) {
    Allat a(*this);
    jollakott++;
    return a;
  }
};

class Allatkert {
  Allat allatok[10];
  size_t a_db = 0, max_db;

public:
  Allatkert(unsigned max = 5) : max_db(max < 10 ? max : 10) { }

  Allat& operator[](size_t i) {
    if (i < a_db)
      return allatok[i];
    throw out_of_range("Rossz index");
  }

  Allatkert operator+(const Allat& allat) const {
    Allatkert allakert(*this);
    if (allakert.a_db < allakert.max_db)
      allakert.allatok[allakert.a_db++] = allat;
    else
      cout << "Az allatkert tele van" << endl;

    return allakert;
  }

  unsigned operator+() {
    unsigned ret = 0;
    for (size_t i = 0; i < a_db; i++) {
      (*this)[i]++;
      if (ret < !allatok[i])
        ret = !allatok[i];
    }
    return ret;
  }
};