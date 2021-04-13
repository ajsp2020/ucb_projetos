
"""
- Sistemas de numeração:

    Sistemas não posicionais: Os algarismos têm um valor fixo independente da posição que ocupem.
    (exemplo: Algarismos romanos)

    Sistemas posicionais: Os algarismos possuem um valor relativo à posição que ocupam no número.
"""

class Binario:
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

    def __hexadecimal(self, algoritmo):

        hexa = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

        i = 0
        for resto in algoritmo:
            for valores in hexa.keys():
                if resto == valores:
                    algoritmo[i] = hexa[valores]
            i += 1



    def calcula_binario_int(self, valor, base):

        print("PARTE INTEIRA:\n")
        self.__valor = valor
        self.__base = int(base)
        self.__algoritmo = []
        self.__valor_raw = self.__valor.split(',')

        self.__valor = int(self.__valor_raw[0])
        self.__tamanho = len(self.__valor_raw)

        while self.__valor > 0:
            resto = self.__valor % self.__base
            quociente = self.__valor // self.__base
            print(f"Valor: {self.__valor} / Divisor: {self.__base} = Quociente: {quociente} +  Resto: {resto}")
            self.__valor = self.__valor // self.__base
            self.__algoritmo.append(resto)

        self.__algoritmo.reverse()

        if self.__base == 16:
            self.__hexadecimal(self.__algoritmo)

        print(self.__algoritmo)
        print("")

        if self.__tamanho > 1:
            self.__valor_fracionario = float("0." + self.__valor_raw[1])
            self.calcula_binario_fracionario(self.__base)

        self.imprime_resultado()
        self.apagalistas()

    def calcula_binario_fracionario(self, base):
        print("PARTE FRACIONÁRIA:\n")
        n=0
        self.__parte_fracionaria =[]
        while (self.__valor_fracionario != 0 and n < 8):

            self.__intermediario = self.__valor_fracionario * base

            if self.__intermediario > 0:
                self.__inteiro = int(self.__intermediario)
                self.__parte_fracionaria.append(self.__inteiro)
                print("{:.5f}".format(self.__valor_fracionario, 4), f" * {base} =",
                      "{:.5f}".format(self.__intermediario),
                      f"-> {self.__inteiro}")

                self.__valor_fracionario = self.__intermediario - self.__inteiro
            else:
                self.__parte_fracionaria.append(0)
                print("{:.5f}".format(self.__valor_fracionario, 4), f" * {base} =",
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

class Decimal:
    """
     - Formula geral:
        Nb = S(n ->1) an * b ** (n -1)

        * n = Posição do algoritmo
        * b = base
        * an = Algoritmo na posição n
    """
    def calcula_decimal(self, valor, base):
        self.__valor = valor
        self.__base = base
        self.__soma = 0

        hexa = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E':14, 'F': 15}
        numeros = [self.__valor for self.__valor in self.__valor]

        for valor in hexa.keys():
            for i in range(len(numeros)):
                if valor == numeros[i]:
                    numeros[i] = hexa[valor]

        numeros = [int(numero) for numero in numeros]
        n = len(numeros) - 1

        for numero in numeros:

            _ = numero * (self.__base ** n)
            print(f"({numero} * ({self.__base} ** {n})): ", _)
            self.__soma += numero * (self.__base ** n)
            n -= 1
        print("")
        print(f"O valor em decimal é: {self.__soma}")

