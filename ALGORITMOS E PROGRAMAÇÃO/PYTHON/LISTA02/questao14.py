

class Questao14:

    def __init__(self, valor1, valor2, valor3):
        self.__valor1 = valor1
        self.__valor2 = valor2
        self.__valor3 = valor3

        self.__valores = [self.__valor1, self.__valor2, self.__valor3]

    def define_maior(self):
        self.__valores.sort(reverse=True)

    def __str__(self):
        self.define_maior()
        return f'{self.__valores[0]}'

if __name__ == '__main__':
    print(Questao14(2, 5, 1))
