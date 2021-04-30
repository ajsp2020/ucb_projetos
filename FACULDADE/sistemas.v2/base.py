
class Base:

    def __init__(self, valor):
        self.__valor = valor
        if ',' in self.__valor:
            self.__inteiro, self.__fracao = self.__valor.split(',')

        else:
            self.__inteiro = self.__valor


    @property
    def inteiro(self):
        return self.__inteiro

    @property
    def fracao(self):
        return self.__fracao

    @inteiro.setter
    def inteiro(self, inteiro):
        self.__inteiro = inteiro

    @fracao.setter
    def fracao(self, fracao):
        self.__fracao = fracao

