# Nev: Petohazi Gabor
# Neptun: CNFYPH
# h: h162846


class Palack:
    def __init__(self, ital, max_urtartalom, jelenlegi_urtartalom=1):
        self.ital = ital
        self.max_urtartalom = max_urtartalom
        self._jelenlegi_urtartalom = jelenlegi_urtartalom

    @property
    def jelenlegi_urtartalom(self):
        return self._jelenlegi_urtartalom

    @jelenlegi_urtartalom.setter
    def jelenlegi_urtartalom(self, ertek):
        if ertek > self.max_urtartalom:
            self._jelenlegi_urtartalom = self.max_urtartalom
        else:
            self._jelenlegi_urtartalom = ertek

        if ertek == 0:
            self.ital = None

    def suly(self):
        palacksuly = self.max_urtartalom/35 + self._jelenlegi_urtartalom
        return palacksuly

    def __str__(self):
        return f"Palack, benne levo ital: {self.ital}, jelenleg {self._jelenlegi_urtartalom} ml van benne, maximum {self.max_urtartalom} ml fer bele."

    def __eq__(self, other):
        if self.ital == other.ital and self.max_urtartalom == other.max_urtartalom and self._jelenlegi_urtartalom == other._jelenlegi_urtartalom:
            return True
        else:
            return False

    def __iadd__(self, other):
        self._jelenlegi_urtartalom += other._jelenlegi_urtartalom


class VisszavalthatoPalack(Palack):
    def __init__(self, ital, max_urtartalom, jelenlegi_urtartalom=1, palackdij=25):
        super().__init__(ital, max_urtartalom, jelenlegi_urtartalom)
        self.palackdij = palackdij

    def __str__(self):
        return f"VisszavalthatoPalack, benne levo ital: {self.ital}, jelenleg {self.jelenlegi_urtartalom} ml van benne, maximum {self.max_urtartalom} ml fer bele."



