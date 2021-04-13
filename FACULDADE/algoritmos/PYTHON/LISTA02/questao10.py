

class Questao10:
    def __init__(self, valor1, valor2, valor3):
        self.__valor1 = valor1
        self.__valor2 = valor2
        self.__valor3 = valor3

    def maior(self):
        self.__valores = [self.__valor1, self.__valor2, self.__valor3]

        self.__valores.sort(reverse=True)

    def __str__(self):
        self.maior()
        return f"{self.__valores[0]}"


if __name__ == '__main__':

    valor1 = float(input("Digite o primeiro valor: "))
    valor2 = float(input("Digite o segundo valor: "))
    valor3 = float(input("Digite o terceiro valor: "))
    print(Questao10(valor1,valor2,valor3))