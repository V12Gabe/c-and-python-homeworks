# Nev: Petohazi Gabor
# Neptun: CNFYPH
# h: h162846

#def hogolyo_csata(lista):
#    szotar = {}
#    for i in lista:
#        for kulcs, ertek in i.items():
#            if "fejtalalat" not in szotar[kulcs]:
#                szotar[kulcs]["fejtalalat"] = 0
#            szotar[kulcs] = ertek







#    return szotar


def hogolyo_pontossag(szotar1):
    szotar2 = szotar1
    for kulcs, ertek in szotar1.items():
        szotar2[kulcs]["pontossag"] = szotar1[kulcs]["talalt"]/szotar1[kulcs]["eldobott_hogolyok"]

    return szotar2


def hogolyo_piros_lap(szotar):
    lista = []
    for kulcs, ertek in szotar.items():
        if szotar[kulcs]['pontossag'] >= 0.7 and (szotar[kulcs]['fejtalalat']/szotar[kulcs]['talalt']) >= 0.5:
            lista.append(kulcs)
    return lista


tesztszotar = {
    "Tamas": {
        "eldobott_hogolyok": 6,
        "talalt": 3,
        "fejtalalat": 0
    },
    "Ferenc": {
        "eldobott_hogolyok": 19,
        "talalt": 8,
        "fejtalalat": 2
    },
    "Csaba": {
        "eldobott_hogolyok": 32,
        "talalt": 2,
        "fejtalalat": 1
    }
}


#hogolyo_pontossag(tesztszotar)

