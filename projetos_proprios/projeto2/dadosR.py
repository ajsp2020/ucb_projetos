from urllib.request import urlopen, urlretrieve
from bs4 import BeautifulSoup
import pandas as pd


response = urlopen('https://www.latam.com/vamos/pt_br/artigos/na-estrada/conheca-a-frota-avioes-LATAM/')
html = response.read().decode('utf-8')
soup = BeautifulSoup(html, 'html.parser')

dados = soup.find('div', {"id": "container-text-h3"})

h3 = (soup.find_all('h3'))
h4 = soup.find_all('h4')

lista_passageiros = []
for item in h4:
    lista_passageiros.append(item.getText())

avioes = []
for item in h3:
    avioes.append(item.getText())

avioes = [aviao for aviao in avioes[1:]]

passageiros = []
for dado in lista_passageiros:
    valor = dado.find('Capacidade')
    if valor == 0:
        dado = dado.split()
        passageiros.append(dado[2])

lista = []
valores = {}
for i in range(len(avioes)):
    lista.append({'Companhia': 'Latam', 'Modelo': str(avioes[i]), 'Capacidade': passageiros[i]})


dataset = pd.DataFrame(lista)
print(dataset)

