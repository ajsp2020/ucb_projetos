
"""
- Sistemas de numeração:

    Sistemas não posicionais: Os algarismos têm um valor fixo independente da posição que ocupem.
    (exemplo: Algarismos romanos)

    Sistemas posicionais: Os algarismos possuem um valor relativo à posição que ocupam no número.
"""

class Decimal:
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

class Binario: # Transforma um valor binário ou hexadecimal em decimal
    """
     - Formula geral:
        Nb = S(n ->1) an * b ** (n -1)

        * n = Posição do algoritmo
        * b = base
        * an = Algoritmo na posição n
    """
    def calcula_decimal(self, valor, base): # Recebendo o valor em binário ou hexadecimal
        self.__valor = valor
        self.__base = base # A base pode ser 2 ou 16
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

    def calcula_hexadecimal(self, binario):

        self.__binario = binario
        self.__inteiro, self.__fracao = self.__binario.split(',')

        self.adiciona_zero_int(self.__inteiro)
        self.adiciona_zero_fracao(self.__fracao)

        self.__inteiro = self.divide(self.__inteiro)
        self.__fracao = self.divide(self.__fracao)

        self.__inteiro = self.nova_lista(self.__inteiro)
        self.__fracao = self.nova_lista(self.__fracao)

        self.__inteiro= self.__hexadecimal(self.__inteiro)
        self.__fracao = self.__hexadecimal(self.__fracao)

        print(self.__inteiro, self.__fracao)
    def adiciona_zero_int(self, valor): # Adiciona zero a parte inteira
        valor = len(valor)
        if valor % 4 == 0:
            return self.__inteiro

        else:
            self.__inteiro = '0' + self.__inteiro
            return self.adiciona_zero_int(self.__inteiro)

    def adiciona_zero_fracao(self, valor): # Adiciona zero a parte fracionária
        valor = len(valor)
        if valor % 4 == 0:
            return self.__fracao

        else:
            self.__fracao = self.__fracao + '0'
            return self.adiciona_zero_fracao(self.__fracao)

    def divide(self, valor): # dividi as partes em intervalo de 4
        n = 4
        return [valor[i:i+n] for i in range(0, len(valor), n)]

    def nova_lista(self, valor):
        lista = []
        for v in valor:
            lista.append(Binario().calcula_decimal(v, 2))
        return lista

    def __hexadecimal(self, valor):
        lista = []
        hexadecimais = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

        for item in valor:
            for hexa in hexadecimais.keys():
                if item == hexa:
                    item = hexadecimais[hexa]

            lista.append(item)

        return lista


if __name__ == '__main__':

    Binario().calcula_hexadecimal('1011101100010100011111101,10111010101010111101')
