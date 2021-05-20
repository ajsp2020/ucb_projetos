

class Questao7:
    def __init__(self, valor1, valor2):
        self.__valor1 = valor1
        self.__valor2 = valor2
        self.diferenca = 0

    def calcula_diferenca(self):

        if self.__valor1 >= self.__valor2:
            self.diferenca = self.__valor1 - self.__valor2

        else:
            self.diferenca = self.__valor2 - self.__valor1

    def __str__(self):
        self.calcula_diferenca()
        return f"A diferença será de {self.diferenca}"


if __name__ == '__main__':
    valor1 = float(input("Digite o primeiro valor: "))
    valor2 = float(input("Digite o segundo valor: "))

    print(Questao7(valor1, valor2))