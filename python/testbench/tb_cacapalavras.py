import pylinp as pl

#print(pl.cacapalavras.__doc__)

src_file = 'desafio.txt'
dst_file = 'gabarito.txt'

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

pl.cacapalavras(src = src_file, 
	dst = dst_file, 
	palavras = L, 
	dir = "LCPS", 
	ignch = "", 
	igncs = True)