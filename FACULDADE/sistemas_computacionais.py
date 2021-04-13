from sistemas.mudancadebase import Binario, Decimal

class Teoria:
    import re
    def le_arquivo(self):
        with open("sistemas/mudancadebase.txt", "r", encoding='utf-8') as f:
            self._texto = f.read()

        print(self._texto)

class Sistemas:
    def __init__(self, assunto):
        self.__assunto = assunto

        if self.__assunto == '2':

            escolha = int(input("Digite 1: Para transformar o valor de decimal para binário ou hexadecimal:\n"
                                "Digite 2: Para transformar o valor de binario ou hexadecimal em decimal(2): \n"))
            if escolha == 1:
                valor = int(input("Digite o valor do número decimal: "))
                base = int(input("Digite o valor da base que deseja converter: "))
                print("Valor em binário:")
                Binario().calcula_binario(valor, base)

            elif escolha == 2:
                valor = (input("Digite o valor do número em binário ou hexadecimal: "))
                base = int(input("Digite o valor da base: "))
                print("Valor em decimal:")
                print(Decimal().calcula_decimal(valor, base))

            else:
                print("Número não suportado")

            retorno = input("Deseja pesquisar novo valor? (S/N): ")
            retorno = retorno.capitalize()


