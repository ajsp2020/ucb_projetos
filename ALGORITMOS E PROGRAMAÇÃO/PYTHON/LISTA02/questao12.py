

class Questao12:

    def __init__(self, ddd):
        self.__cidades = {'61': 'Brasília', '71': 'Salvador', '11': 'São Paulo', '21': 'Rio de janeiro',
                          '32': 'Juiz de fora', '19': 'Campinas', '27': 'Vitoria', '31': 'Belo Horizonte'}

        self.__ddd = ddd

    def devolve_cidade(self):
        for key, values in self.__cidades.items():
            if self.__ddd == key:
                return values

    def __str__(self):
        cidade = self.devolve_cidade()
        if cidade == None:
            return "Cidade sem identificação"
        return f"Cidade : {cidade}"


if __name__ == '__main__':
    ddd = input("Digite o ddd: ")

    print(Questao12(ddd))