import os


class Acesso:

    aulas = os.listdir('aulas')
    lista_aula = []
    for entry in aulas:
        lista_aula.append(entry)
        for indice, aula in enumerate(lista_aula):
            print(indice, aula)

    def __init__(self):
        self.__entrada = input("Qual aula deseja acessar? ")

        self.le_arquivo()

    def le_arquivo(self):
        with open("aulas/"+ self.__entrada, "r", encoding='utf-8') as f:
            self._texto = f.read()

        print(self._texto)

if __name__ == '__main__':
    Acesso()