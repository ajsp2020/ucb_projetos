from binario import Binario
from decimal import Decimal
from hexadecimal import Hexadecimal

class AcessoMB:


    def menu(self):
        escolha = int(input("Digite 1: Para transformar o valor de DECIMAL em BINÁRIO ou HEXADECIMAL:\n"
                            "Digite 2: Para transformar o valor de BINÁRIO em DECIMAL ou HEXADECIMAL:\n"
                            "Digite 3: Para transformar o valor de HEXADECIMAL em BINÁRIO ou DECIMAL:\n"))
        if escolha == 1:
            valor = input("Digite o número em decimal: ")
            print("Valor em binário:")
            Decimal().calcula_binario_int(valor)

        elif escolha == 2:
            valor = (input("Digite o número em binário: "))
            print("Valor em decimal:")
            print(Binario().calcula_decimal(valor))

        elif escolha == 3:
            valor = (input("Digite o número em hexadecimal: "))
            print("Valor em decimal:")
            print(Hexadecimal().calcula_decimal(valor))


        else:
            print("Número não suportado")

            self.menu()

        retorno = input("Deseja pesquisar novo valor? (S/N): ")
        retorno= retorno.capitalize()
        if retorno == 'S':
            self.menu()

        else:
            exit()



if __name__ == '__main__':

    AcessoMB().menu()
