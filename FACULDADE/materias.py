from FACULDADE.sistemas.velho.teoria import Sistemas, Teoria


class Materias:
    def __init__(self):

        print("Qual Matéria deseja acessar? ")
        self.__materia = input("1 - PRÁT. PROF. I - SISTEMAS COMPUTACIONAIS:\n"
                               "2 - HUMANIDADE, SOCIEDADE E ÉTICA:\n"
                               "3 - ALGORITMOS E PROGRAMAÇÃO:\n")

        self.escolhas()

    def escolhas(self):
        if self.__materia == "1":
            self.sistemas_computacionais()
        elif self.__materia == "2":
            self.humanidade_sociedade_etica()
        elif self.__materia == "3":
            self.algoritmo_programacao()


    def sistemas_computacionais(self):
        print("Digite o assunto que deseja acessar: \n")
        print("1- Teoria sobre mudança de Base:\n"
              "2 -Exercício mudança de Base: ")
        self.__assunto = input()

        if self.__assunto == "1":
            Teoria().le_arquivo()

        elif self.__assunto == "2":
            Sistemas('2')

    def humanidade_sociedade_etica(self):
        pass

    def algoritmo_programacao(self):
        pass

if __name__ == '__main__':

    Materias()

'''
    #Materias()
    import os
    algoritmos = os.listdir('algoritmos/C/lista 1')
    for entry in algoritmos:
        print(entry)

    with os.scandir('algoritmos/C/lista 1') as entries:
        for entry in entries:
            print(entry.name)


    from pathlib import Path
    algoritmos = Path('algoritmos/C/lista 1')
    for entry in algoritmos.iterdir():
        print(entry.name)

        #Materias()
    import os
    algoritmos = os.listdir('algoritmos/C/lista 1')
    for entry in algoritmos:
        print(entry)

    with os.scandir('algoritmos/C/lista 1') as entries:
        for entry in entries:
            print(entry.name)


    from pathlib import Path
    algoritmos = Path('algoritmos/C/lista 1')
    for entry in algoritmos.iterdir():
        print(entry.name)
'''
