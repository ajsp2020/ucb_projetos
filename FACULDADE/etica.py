


class Etica:
    def __init__(self, aula):
        self.__aula = aula


        if self.__aula == 'aula1':
            self.f = open('etica/aula1.txt', "r")
            print(self.f.read())




if __name__ == "__main__":

    #aula = input("Digite a aula que deseja: ")

    Etica("aula1")