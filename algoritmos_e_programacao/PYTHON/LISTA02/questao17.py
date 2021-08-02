

class Questao17:
    def __init__(self, ano_atual, ano_nascimento):

        self.__ehvalido = ano_atual > 0 and ano_nascimento > 0 and ano_atual > ano_nascimento
        if self.__ehvalido:
            self.__ano_atual = ano_atual
            self.__ano_nascimento = ano_nascimento
        else:
            raise ValueError("Ano atual não pode ser negativo ou menor que ano nacimento")


    def calcula_dias(self):

        self.__dias = (self.__ano_atual - self.__ano_nascimento) * 360

    def __str__(self):
        self.calcula_dias()
        return f'A quantidade de dias vividos é de {self.__dias} dias'

if __name__ == '__main__':

    ano_atual = int(input("Digite o ano atual: "))
    ano_nascimento = int(input("Digite seu ano de nascimento: "))

    print(Questao17(ano_atual, ano_nascimento))