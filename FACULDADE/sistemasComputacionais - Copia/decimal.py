from base import Base

"""
- Sistemas de numeração:

    Sistemas não posicionais: Os algarismos têm um valor fixo independente da posição que ocupem.
    (exemplo: Algarismos romanos)

    Sistemas posicionais: Os algarismos possuem um valor relativo à posição que ocupam no número.
"""

class Decimal(Base):
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
        super().__init__(decimal)
        print(f"O VALOR EM DECIMAL É DE: {decimal}")

# CALCULA VALORES DE DECIMAL -> BINÁRIO:

    def binario(self):
        inteiro = self.calcula_binario_int()
        inteiro = "".join(inteiro)

        try:
            fracao = self.calcula_binario_fracionario()
            fracao = "".join(fracao)
            print(f"->> O VALOR EM BINÁRIO É DE: {inteiro},{fracao} <<-")
            return inteiro , fracao
        except:
            print(f"->> O VALOR EM BINÁRIO É DE: {inteiro} <<_")
            return inteiro


    def calcula_binario_int(self):

        self._inteiro = int(self._inteiro)
        print("PARTE INTEIRA:\n")
        self.__algoritmo = []


        while self._inteiro > 0:
            resto = self._inteiro % 2
            quociente = self._inteiro // 2
            print(f"Valor: {self._inteiro} / Divisor: {2} = Quociente: {quociente} +  Resto: {resto}")
            self._inteiro = self._inteiro // 2
            self.__algoritmo.append(str(resto))

        self.__algoritmo.reverse()

        return (self.__algoritmo)


    def calcula_binario_fracionario(self):

        print("PARTE FRACIONÁRIA:\n")
        self._fracao = float("0." + self._fracao)

        n = 0
        self.__parte_fracionaria = []
        while (self._fracao != 0 and n < 8):

            self.__intermediario = self._fracao * 2

            if self.__intermediario > 0:
                self.__parte_inteira = int(self.__intermediario)
                self.__parte_fracionaria.append(str(self.__parte_inteira))
                print("{:.5f}".format(self._fracao, 4), f" * {2} =",
                      "{:.5f}".format(self.__intermediario),
                      f"-> {self.__parte_inteira}")

                self._fracao = self.__intermediario - self.__parte_inteira
            else:
                self.__parte_fracionaria.append("0")
                print("{:.5f}".format(self._fracao, 4), f" * {2} =",
                      "{:.5f}".format(self.__intermediario),
                      f"-> {0}")
            n += 1

        return self.__parte_fracionaria

# CALCULA VALORES DE DECIMAL -> HEXADECIMAL

    def hexadecimal(self):
        inteiro = self.calcula_hexadecimal_int()
        inteiro = "".join(inteiro)

        try:
            fracao = self.calcula_hexadecimal_fracionario()
            fracao = "".join(fracao)
            print(f"->> O VALOR EM HEXADECIMAL É DE: {inteiro},{fracao} <<-")
            return inteiro , fracao
        except:
            print(f"->> O VALOR EM HEXADECIMAL É DE: {inteiro} <<-")
            return inteiro

    def calcula_hexadecimal_int(self):

        self._inteiro = int(self._inteiro)
        print("PARTE INTEIRA:\n")
        self.__algoritmo = []


        while self._inteiro > 0:
            resto = self._inteiro % 16
            quociente = self._inteiro // 16
            print(f"Valor: {self._inteiro} / Divisor: {16} = Quociente: {quociente} +  Resto: {resto}")
            self._inteiro = self._inteiro // 16
            self.__algoritmo.append((resto))

        self.__algoritmo.reverse()
        self.__algoritmo = self.transforma_hexadecimal(self.__algoritmo)
        return (self.__algoritmo)


    def calcula_hexadecimal_fracionario(self):
        if self._fracao != None:
            print("PARTE FRACIONÁRIA:\n")

        self._fracao = float("0." + self._fracao)

        n = 0
        self.__parte_fracionaria = []
        while (self._fracao != 0 and n < 8):

            self.__intermediario = self._fracao * 16

            if self.__intermediario > 0:
                self.__parte_inteira = int(self.__intermediario)
                self.__parte_fracionaria.append((self.__parte_inteira))
                print("{:.5f}".format(self._fracao, 4), f" * {16} =",
                      "{:.5f}".format(self.__intermediario),
                      f"-> {self.__parte_inteira}")

                self._fracao = self.__intermediario - self.__parte_inteira
            else:
                self.__parte_fracionaria.append("0")
                print("{:.5f}".format(self._fracao, 4), f" * {16} =",
                      "{:.5f}".format(self.__intermediario),
                      f"-> {0}")
            n += 1
        self.__parte_fracionaria = self.transforma_hexadecimal(self.__parte_fracionaria)
        return self.__parte_fracionaria


if __name__ == '__main__':

    Decimal('495,6731').binario()
    #Decimal('9125,31597').hexadecimal()
    #Decimal('54897').hexadecimal()