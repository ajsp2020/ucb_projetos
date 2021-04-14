import os


class Acesso:

    aulas = os.listdir('aulas')
    for entry in aulas:
        print(entry)

    def __init__(self):
        self.__entrada = input("Qual aula deseja acessar? ")

        self.le_arquivo()

    def le_arquivo(self):
        with open("aulas/"+ self.__entrada, "r", encoding='utf-8') as f:
            self._texto = f.read()

        print(self._texto)

if __name__ == '__main__':
    Acesso()