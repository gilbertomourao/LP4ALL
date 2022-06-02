/* cacapalavras */
#define cacapalavras_doc "##########################################\n\
Função cacapalavras\n\
\n\
Procura por palavras em um texto e as destaca em outro arquivo\n\
de destino.\n\
\n\
Argumentos:\n\
\n\
src: string contendo o caminho para o arquivo texto de referência.\n\
dst: string contendo o caminho para o arquivo texto de destino.\n\
palavras: lista de palavras que serão procuradas em src.\n\
dir: direção da procura. Este parametro aceita somente as strings abaixo.\n\
	\"L\": procura nas linhas\n\
	\"C\": procura nas colunas\n\
	\"P\": procura na direcao da diagonal principal\n\
	\"S\": procura na direcao da diagonal secundaria\n\
	\"LC\": procura nas direcoes L e C\n\
	\"LP\": procura nas direcoes L e P\n\
	\"LS\": procura nas direcoes L e S\n\
	\"CP\": procura nas direcoes C e P\n\
	\"CS\": procura nas direcoes C e S\n\
	\"PS\": procura nas direcoes P e S\n\
	\"LCP\": procura nas direcoes L, C e P\n\
	\"LCS\": procura nas direcoes L, C e S\n\
	\"LPS\": procura nas direcoes L, P e S\n\
	\"CPS\": procura nas direcoes C, P e S\n\
	\"LCPS\": procura nas direcoes L, C, P e S\n\n\
	O usuario pode inserir o caractere '-' antes da direcao para indicar que \
nao deseja procurar na sentido oposto (string invertida). Por exemplo:\n\n\
	\"-LCPS\": procura nas direcoes L, C, P e S, mas nao procura a string invertida.\n\n\
ignch: string contendo os caracteres a serem ignorados.\n\
	   Para ignorar todos os caracteres não alfabéticos, utilizar a string \"!alfabet\".\n\
	   Para ignorar todos os caracteres não alfanuméricos, utilizar a string \"!alfanum\".\n\
igncs: True ou False. Indica se cacapalavras deve considerar letras maiúsculas e minúsculas como iguais ou diferentes.\n\
\n\
Exemplo de aplicação:\n\
\n\
import pylinp as pl\n\
\n\
src_file = 'desafio.txt'\n\
dst_file = 'gabarito.txt'\n\
\n\
L = ['Aterramento',\n\
'SPDA',\n\
'Protecao',\n\
'Transformador',\n\
'Subestacao',\n\
'Fotovoltaico',\n\
'Disjuntor',\n\
'Projeto',\n\
'Residencial',\n\
'Predial']\n\
\n\
pl.cacapalavras(src = src_file, \n\
	dst = dst_file, \n\
	palavras = L, \n\
	dir = \"LCPS\", \n\
	ignch = \"\", \n\
	igncs = True)\n\
\n\
##########################################\n"
