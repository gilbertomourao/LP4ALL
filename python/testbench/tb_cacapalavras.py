import pylinp as pl

#print(pl.cacapalavras.__doc__)

# Arquivos texto
src_file = 'desafio.txt'
dst_file = 'gabarito.txt'

# Lista de palavras
L = ['Aterramento',
'SPDA',
'Protecao',
'Transformador',
'Subestacao',
'Fotovoltaico',
'Disjuntor',
'Projeto',
'Residencial',
'Predial']

"""
Procura por todas as palavras em L dentro de src. 
Destaca as palavras encontradas em dst. 
Procura nas linhas, colunas, diagonais no sentido 
da principal e no sentido da secundária (LCPS), 
nas duas direções. 
Não ignora nenhum caractere. 
Ignora case sensitive.
Caracteres não pertencentes às palavras são substituídos por ' '.
"""
pl.cacapalavras(src = src_file,
	dst = dst_file,
	palavras = L,
	igncs = True)
