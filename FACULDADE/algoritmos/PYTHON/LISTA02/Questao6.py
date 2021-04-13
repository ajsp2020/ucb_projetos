

class Questao6:
    def __init__(self, numero):
        self.__numero = int(numero)

    def ehpar(self):
        if (self.__numero % 2 == 0):
            return True
        return False

    def __str__(self):
        if self.ehpar():
            return "É par"
        return "É impar"


if __name__ == '__main__':
    valor = int(input("Digite um valor inteiro: "))
    print(Questao6(valor))