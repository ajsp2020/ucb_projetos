

class Questao16:
    def __init__(self, qtd_nomes):
        self.__qtd_nomes = qtd_nomes

        self.__pessoas ={}
        for i in range(qtd_nomes):
            nome = input("Digite o nome: ")
            altura = input("Digite a altura: ")
            self.__pessoas[nome] = altura

    def pega_maior_altura(self):
        self.__pessoas = {k: v for k, v in sorted(self.__pessoas.items(), key=lambda item: item[1], reverse=True)}

    def __str__(self):
        self.pega_maior_altura()
        values_view = self.__pessoas.values()
        value_iterator = iter(values_view)
        first_value = next(value_iterator)
        return f'{first_value}'


if __name__ == '__main__':
    print(Questao16(3))