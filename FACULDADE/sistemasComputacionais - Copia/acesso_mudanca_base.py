from binario import Binario
from decimal import Decimal
from hexadecimal import Hexadecimal



class AcessoMB:


    def menu(self):
        escolha = int(input("Digite 1: Para transformar o valor de DECIMAL em BINÁRIO ou HEXADECIMAL:\n"
                            "Digite 2: Para transformar o valor de BINÁRIO em DECIMAL ou HEXADECIMAL:\n"
                            "Digite 3: Para transformar o valor de HEXADECIMAL em BINÁRIO ou DECIMAL:\n"
                            "Digite 4: Para sair:\n"))
        if escolha == 1:
            valor = input("Digite o número em decimal: ")
            base = int(input("Digite 1 para valor em binário:\nDigite 2 para valor em hexadecimal:\n"))
            if (base == 1):
                print("Valor em binário:")
                Decimal(valor).binario()

            elif (base == 2):
                Decimal(valor).hexadecimal()

        elif escolha == 2:
            valor = (input("Digite o número em binário: "))
            base = int(input("Digite 1 para valor em decimal:\nDigite 2 para valor em hexadecimal:\n"))
            if (base == 1):
                print("Valor em decimal:")
                Binario(valor).decimal()

            elif (base == 2):
                print("Valor em hexadecimal:")
                Binario(valor).hexadecimal()

        elif escolha == 3:
            valor = (input("Digite o número em hexadecimal: "))
            base = int(input("Digite 1 para valor em decimal:\nDigite 2 para valor em binário:\n"))
            if (base == 1):
                print("Valor em decimal:")
                Hexadecimal(valor).decimal()

            elif (base == 2):
                print("Valor em hexadecimal:")
                Hexadecimal(valor).binario()

        elif escolha == 4:
            sair = ""
            resp_valida = sair == 'S' or sair == 'N'
            while not resp_valida:
                sair = (input("Deseja sair? (S/N)")).capitalize()
                resp_valida = sair == 'S' or sair == 'N'

            if sair == 'S':
                exit()

            elif sair == 'N':
                self.menu() # Volta para o menu


        else:
            print("Número não suportado")

            self.menu()

        retorno = input("Deseja pesquisar novo valor? (S/N): ")
        retorno= retorno.capitalize()
        if retorno == 'S':
            self.menu()

        else:
            exit()

    def clear(self): #  Rever a implementação da função clear -> Nao funciona
        import os
        clear = lambda: os.system('cls' if os.name == 'nt' else 'clear')
        clear()


if __name__ == '__main__':

    AcessoMB().menu()
