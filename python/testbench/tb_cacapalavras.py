import pylinp as pl

#print(pl.cacapalavras.__doc__)

# Arquivos texto
src = open('desafio.txt', 'r')
src_text = src.read()
src.close()

print('Texto de entrada: \n\n{}\n\n'.format(src_text))

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
dst_text = pl.cacapalavras(src = src_text, palavras = L, igncs = True)

print('Texto de saída: \n\n{}\n\n'.format(dst_text))

dst = open('gabarito.txt', 'w')
dst.write(dst_text)
dst.close()

