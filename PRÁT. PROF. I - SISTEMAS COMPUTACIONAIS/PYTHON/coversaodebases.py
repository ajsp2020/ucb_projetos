"""
Conversão de bases

Binário -> Decimal

"""

from mudancadebase import Decimal

if __name__ == '__main__':
    valor = int(input("Digite o valor do número em binário: "))
    base = int(input("Digite o valor da base que deseja converter: "))
    print("Valor em decimal:")
    print(Decimal().calcula_decimal(valor, base))