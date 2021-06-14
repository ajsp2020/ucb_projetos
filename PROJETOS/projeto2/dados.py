from urllib.request import urlopen, urlretrieve
from bs4 import BeautifulSoup
import pandas as pd


response_tam = urlopen('https://www.latam.com/vamos/pt_br/artigos/na-estrada/conheca-a-frota-avioes-LATAM/')
html_tam = response_tam.read().decode('utf-8')
soup_tam = BeautifulSoup(html_tam, 'html.parser')

h3_tam = (soup_tam.find_all('h3'))
h4_tam = (soup_tam.find_all('h4'))

lista_passageiros_tam = []
for item in h4_tam:
    lista_passageiros_tam.append(item.getText())

avioes_tam = []
for item in h3_tam:
    avioes_tam.append(item.getText())

avioes = [aviao for aviao in avioes_tam[1:]]

passageiros_tam = []
for dado in lista_passageiros_tam:
    valor = dado.find('Capacidade')
    if valor == 0:
        dado = dado.split()
        passageiros_tam.append(dado[2])

lista = []
for i in range(len(avioes)):
    lista.append({'companhia': 'Latam', 'modelo': str(avioes[i]), 'capacidade': passageiros_tam[i]})


dataset = pd.DataFrame(lista)
dataset.to_csv("avioes.csv", index=False)

print(dataset)

response_gol = urlopen('https://pt.wikipedia.org/wiki/Frota_de_aeronaves_da_Gol_Linhas_A%C3%A9reas_Inteligentes')
html_gol = response_gol.read().decode('utf-8')
soup_gol = BeautifulSoup(html_tam, 'html.parser')

