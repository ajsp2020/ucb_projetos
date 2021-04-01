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

        print(numeros)

        numeros = [int(numero) for numero in numeros]
        n = len(numeros) - 1

        for numero in numeros:

            _ = numero * (self.__base ** n)
            print(f"({numero} * ({self.__base} ** {n})): ", _)
            self.__soma += numero * (self.__base ** n)
            n -= 1
        print("")
        print(f"O valor em decimal é: {self.__soma}")

if __name__ == '__main__':

    Decimal().calcula_decimal('AB23F',16)