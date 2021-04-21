
class Hexadecimal: # Transforma classe de hexadecimal em Binario ou Decimal

    def calcula_decimal(self, valor): # Recebendo o valor em binário ou hexadecimal
        self.__valor = valor
        self.__base = 16
        self.__soma = 0

        hexa = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E':14, 'F': 15}
        numeros = [self.__valor for self.__valor in self.__valor] # Separando os valores e colocando numa lista

        for valor in hexa.keys(): # Substituindo os valores caso seja em A, B... F para de 10 a 15
            for i in range(len(numeros)):
                if valor == numeros[i]:
                    numeros[i] = hexa[valor]

        numeros = [int(numero) for numero in numeros] # Transformando os valores em inteiro
        n = len(numeros) - 1

        for numero in numeros: # Para cada numero o resultado será mutiplicado de acordo com a formula e impresso

            _ = numero * (self.__base ** n)
            print(f"({numero} * ({self.__base} ** {n})): ", _) # Impressão parcial
            self.__soma += numero * (self.__base ** n) # formula genérica, valida para base qualquer base
            n -= 1
        print("")
        print(f"O valor em decimal é: {self.__soma}") # impressão total
        return self.__soma
