
from mudancadebase import Binario, Decimal

class AcessoMB:

    def menu(self):
        escolha = int(input("Digite 1: Para transformar o valor de decimal para binário ou hexadecimal:\n"
                            "Digite 2: Para transformar o valor de binario ou hexadecimal em decimal(2): \n"))
        if escolha == 1:
            valor = input("Digite o valor do número decimal: ")
            base = input("Digite o valor da base que deseja converter: ")
            print("Valor em binário:")
            Binario().calcula_binario_int(valor, base)

        elif escolha == 2:
            valor = (input("Digite o valor do número em binário ou hexadecimal: "))
            base = int(input("Digite o valor da base: "))
            print("Valor em decimal:")
            print(Decimal().calcula_decimal(valor, base))

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
