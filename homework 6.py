from datetime import datetime

def zarojel(szoveg):
    nyito = 0
    zaro = 0
    ret = []
    egyseg = ""
    for i in szoveg:
        if i == "(":
            nyito += 1
            egyseg += i
        if i == ")":
            zaro += 1
            egyseg += i

        if nyito == zaro and nyito > 0 and zaro > 0:
            ret.append(egyseg)
            egyseg = ""
            nyito = 0
            zaro = 0
    return ret


print(zarojel('( ()) ((()()())) (()) ()'))


class BefozesException(Exception):
    def __init__(self, uzenet):
        self.uzenet = uzenet
        super().__init__(self.uzenet)


class Lekvar:
    def __init__(self, tartalom = [], lejarati_datum="2022-10-11"):
        self.tartalom = tartalom
        self.lejarati_datum = lejarati_datum


    @property
    def tartalom(self):
        return self._tartalom
    @tartalom.setter
    def tartalom(self, lista):
        self._tartalom = lista
        if len(set(self._tartalom)) == 1:
            self._nev = self._tartalom[0]
        elif len(self._tartalom) == 0:
            self._nev = "Meglepi"
        else:
            self._nev = "Vegyes"

    def __str__(self):
        if self._nev == "Vegyes":
            return f"{self._nev} (lejarati datum: {self.lejarati_datum}), melynek tartalma: {set(self._tartalom)}"
        else:
            return f"{self._nev} (lejarati datum: {self.lejarati_datum}), melynek tartalma: {self._tartalom}"


    def __lt__(self, other):
        if not isinstance(other, Lekvar):
            raise BefozesException("Nem lekvar!")
        else:
            if datetime.strptime(self.lejarati_datum, "%Y-%m-%d") < datetime.strptime(other.lejarati_datum, "%Y-%m-%d"):
                return True
            else:
                return False


    def __iadd__(self, other):
        if not isinstance(other, Lekvar):
            raise BefozesException("Nem lekvar!")
        else:
            if datetime.strptime(self.lejarati_datum, "%Y-%m-%d") > datetime.strptime(other.lejarati_datum, "%Y-%m-%d"):
                self.lejarati_datum = other.lejarati_datum

            self.tartalom = self.tartalom + other.tartalom

        return self

lekvar = Lekvar(["Eper", "Alma"])
print(lekvar)
lekvar2 = Lekvar(["Eper", "Eper"], "2022-11-25")
print(lekvar2)