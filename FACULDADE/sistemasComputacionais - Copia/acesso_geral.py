from FACULDADE.sistemas.velho.teoria import Teoria
from acesso_mudanca_base import AcessoMB

class Acesso:

    def sistemas_computacionais(self):
        print("Digite o assunto que deseja acessar: \n")
        print("1- Teoria sobre mudança de Base:\n"
              "2 -Exercício mudança de Base: "
              "3 - Para sair: ")
        self.__assunto = input()

        if self.__assunto == "1":
            Teoria().le_arquivo()

        elif self.__assunto == "2":
            AcessoMB().menu()


if __name__ == '__main__':

    Acesso().sistemas_computacionais()