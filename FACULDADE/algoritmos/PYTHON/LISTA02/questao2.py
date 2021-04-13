

class Questao2:

    def __init__(self, numero):
        self.__numero = numero

    @staticmethod
    def apresentacao():
        return ("Questão 2:\n\nEfetuar a leitura de um número e apresentá-lo como o seu módulo (somente seu valor"
                "absoluto) elaborando os cálculos matemáticos para isso.\n")

    def __str__(self):
        self.__numero = abs(self.__numero)
        return f"{self.__numero}"


if __name__ == '__main__':

    print(Questao2.apresentacao())
    numero = int(input("Digite um valor: "))
    print(Questao2(numero))