
from mudancadebase import Binario, Decimal

class AcessoMB:


    def menu(self):
        escolha = int(input("Digite 1: Para transformar o valor de DECIMAL para BINÁRIO ou HEXADECIMAL:\n"
                            "Digite 2: Para transformar o valor de BINÁRIO ou HEXADECIMAL em DECIMAL: \n"
                            "Digite 3: Para transformar de BINÁRIO para HEXADECIMAL:\n"))
        if escolha == 1:
            valor = input("Digite o valor do número decimal: ")
            base = input("Digite o valor da base que deseja converter: ")
            print("Valor em binário:")
            Decimal().calcula_binario_int(valor, base)

        elif escolha == 2:
            valor = (input("Digite o valor do número em binário ou hexadecimal: "))
            base = int(input("Digite o valor da base: "))
            print("Valor em decimal:")
            print(Binario().calcula_decimal(valor, base))

        elif escolha == 3:
            pass

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
