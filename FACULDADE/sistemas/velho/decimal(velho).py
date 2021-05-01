class Decimal: # Transforma qualquer valor Decimal para binário ou hexadecimal
    """
    - Decimal -> Base
    - Sucessivas divisões dentro do conjunto dos naturais

        Dividendo / Divisor = Quociente + Resto
        Ex:
            * 15 / 2 = 7 + 1
            * 18 / 2 = 9 + 0

        Onde:

        - Dividendo: O decimal a ser convertido
        - Divisor: Base
        - Quociente: O resutado da divisão a cada etapa
        - Resto: Resto
        - Interromper as sucessivas divisões quando o quociente for menor que dois
        - O Binário correspondente ao decimal, é formada pelo último quociente sequido dos restos das etapas das
            divisões anteriores, em sentido contrário.
    """
    def __init__(self, decimal):
        self.__decimal = decimal

        if ',' in self.__decimal:
            self.__inteiro , self.__fracao = self.__decimal.split(',')

        else:
            self.__inteiro = self.__decimal

    def __hexadecimal(self, algoritmo):

        hexa = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

        i = 0
        for resto in algoritmo:
            for valores in hexa.keys():
                if resto == valores:
                    algoritmo[i] = hexa[valores]
            i += 1



    def calcula_binario_int(self, base):

        print("PARTE INTEIRA:\n")

        self.__algoritmo = []

        self._tamanho = len(self.__inteiro)


        while self.__decimal > 0:
            resto = self.__decimal % 2
            quociente = self.__decimal // 2
            print(f"Valor: {self.__decimal} / Divisor: {2} = Quociente: {quociente} +  Resto: {resto}")
            self.__decimal = self.__decimal // 2
            self.__algoritmo.append(resto)

        print(self.__algoritmo)



            self.__valor_fracionario = float("0." + self.__fracao)
            self.calcula_binario_fracionario(16)

        self.imprime_resultado()
        self.apagalistas()

    def calcula_binario_fracionario(self, base):
        print("PARTE FRACIONÁRIA:\n")
        n=0
        self.__parte_fracionaria =[]
        while (self._fracao != 0 and n < 8):

            self.__intermediario = self._fracao * base

            if self.__intermediario > 0:
                self._inteiro = int(self.__intermediario)
                self.__parte_fracionaria.append(self._inteiro)
                print("{:.5f}".format(self._fracao, 4), f" * {base} =",
                      "{:.5f}".format(self.__intermediario),
                      f"-> {self._inteiro}")

                self._fracao = self.__intermediario - self._inteiro
            else:
                self.__parte_fracionaria.append(0)
                print("{:.5f}".format(self._fracao, 4), f" * {base} =",
                      "{:.5f}".format(self.__intermediario),
                      f"-> {0}")
            n += 1

        if self.__base == 16:
            self.__hexadecimal(self.__parte_fracionaria)


        print(f"{self.__parte_fracionaria}\n")


    def imprime_resultado(self):
        if self.__base == 2:
            print("O VALOR EQUIVALENTE EM BINÁRIO É:\n")
        elif self.__base == 16:
            print("O VALOR EQUIVALENTE EM HEXADECIMAL É:\n")

        for i in self.__algoritmo:
            print(i, end="")

        if self.__tamanho > 1:
            print(",", end="")
            for i in self.__parte_fracionaria:
                print(i, end="")
        print("\n")

    def apagalistas(self):
        self.__algoritmo.clear()
        if self.__tamanho > 1:
            self.__parte_fracionaria.clear()


if __name__ == '__main__':

    Decimal(10).calcula_binario_int(2)