

class Questao15:

    def __init__(self, horas):
        self.__horas = horas

    def calcula_preco(self):

        if self.__horas <= 20 and self.__horas > 0:
            self.__preco = 30.0

        elif self.__horas > 20:
            self.__preco = 30 + (self.__horas - 20) * (0.1 * 30)

        else:
            raise ValueError("Não pode valores negativos")

    def __str__(self):

        self.calcula_preco()
        return f'O valor a ser pago será de R$ {self.__preco}'

if __name__ == '__main__':

    horas = float(input("Digite a quantidade de horas: "))
    print(Questao15(horas))