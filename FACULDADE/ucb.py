from materias import Materias

class Ucb:
    def __init__(self, nome, matricula):
        self.__nome = nome
        self.__matricula = matricula

        if self.__nome == 'Antonio' and self.__matricula == 'UC21106344':
            self.__materias = Materias()

        else:
            raise ValueError("Nome ou matrícula incorreto!")

if __name__ == '__main__':

    nome = input("Nome: ")
    matricula = input("Matrícula: ")
    Ucb(nome, 'UC21106344')