import csv

class Aviao:

    def escolhe_avioes(self):
        arquivo = open('avioes.csv', "r")
        avioes = csv.reader(arquivo)
        next(avioes)

        self.__companhia,self.__modelo,self.__capacidade = avioes

        print(self.__capacidade)

if __name__ == '__main__':

