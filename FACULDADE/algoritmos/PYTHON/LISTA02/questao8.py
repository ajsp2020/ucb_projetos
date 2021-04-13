from questao4 import Questao4

class Questao8(Questao4):
    def __init__(self, altura):
        self.__peso = 0
        self.__altura = altura

    def calcula_peso_ideal(self):
        if self._sexo == 'M':
            self.__peso = (72.5 * self.__altura) - 58
        else:
            self.__peso = (62.1 * self.__altura) - 44.7

    def __str__(self):
        self.calcula_peso_ideal()
        if self._sexo == 'M':
            return "Ilmo Sr. {} seu peso ideal é de: {:.2f} kg.".format(self._nome, self.__peso)
        else:
            return "Ilmo Sra. {} seu peso ideal é de: {:.2f} kg.".format(self._nome, self.__peso)



if __name__ == '__main__':

    altura = float(input("Digite a sua altura: "))
    q = Questao8(altura)
    q.sexo = input("Digite o seu sexo (M/F): ")
    q.nome = input("Digite o seu nome: ")

    print(q)