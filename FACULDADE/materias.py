from sistemas_computacionais import Sistemas
import algoritmos


class Materias:
    def __init__(self):

        print("Qual Matéria deseja acessar? ")
        self.__materia = input("1 - PRÁT. PROF. I - SISTEMAS COMPUTACIONAIS:\n"
                               "2 - HUMANIDADE, SOCIEDADE E ÉTICA:\n")

        print("Digite o assunto que deseja acessar: \n")
        if self.__materia == "1":
            self.__assunto = input("1 - Mudança de Base ")

        if self.__assunto == "1":
            Sistemas('1')


if __name__ == '__main__':

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

    