# LINGUAGEM DE PROGRAMAÇÃO - UFMA

Este repositório contém diversos programas feitos por alunos já aprovados na cadeira Linguagem de Programação (LP) - EE e a biblioteca LINP (ainda em desenvolvimento). Se você já foi aprovado em LP, colabore enviando os programas que fez enquanto estudava para a disciplina, incluindo os que Ari cobrou nas avaliações.

## Colaboração

Para colaborar com LP4ALL, você pode:

1. Enviar uma pasta contendo o seu nome e o período em que cursou a disciplina contendo todos os arquivos que utilizou/desenvolveu na época para um dos colaboradores deste repositório.
2. Pedir para ser um colaborador (fale com um dos colaboradores).

Para ser um colaborador, você precisa ter uma conta no github. 

### Por que colaborar?

Infelizmente, muitos alunos atrasam o curso (ou fazem as cadeiras por outros cursos) ou ficam ansiosos com a disciplina de linguagem de programação. A falta de um material próprio da disciplina contendo o histórico da mesma e de suporte por parte dos já aprovados é uma das principais causas disso. O objetivo deste repositório é armazenar várias provas anteriores, bem como possíveis algoritmos que podem ajudar durante o estudo. Assim, quanto mais contribuidores, maior será o banco de dados disponível para os alunos que estão cursando a disciplina ou que ainda irão cursar e menor será a ansiedade causada pela cadeira. Além disso, programar é uma atividade extremamente divertida. Aprender C faz as outras linguagens como python, java e C++ ficarem mais simples. Portanto, esperamos que você se divirta programando. 

### Como colaborar

Se estiver usando o windows, instale o git bash.

Navegue até uma pasta de sua escolha. Copie este repositório para o seu computador. 

```
git clone url_do_repositório
git submodule init
git submodule update
```

Se já tiver uma pasta contendo LP4ALL, tente atualizá-la.

```
git pull
```

O script git_subupdate.sh pode ser utilizado para atualizar automaticamente o submódulo linp, sincronizando esse com o master do repositório linp. Para executar o script, basta executar o comando abaixo.

```
./git_subupdate.sh
```

Com o repositório clonado, faça as alterações que acha necessário e atualize LP4ALL. Após as alterações, você pode verificar que arquivos foram modificados através do comando abaixo.

```
git status
```

Agora, adicione as alterações através do comando git add "nome_do_arquivo". Para cada alteração, você deve adicionar um commit explicando brevemente o que foi feito. Por exemplo:

```
git add arquivo1.c
git commit -m "adicionada função func"
git add arquivo2.c
git commit -m "alterada descrição da função abc"
```

É possível adicionar todas as alterações ao mesmo tempo e criar apenas um commit para todas.

```
git add .
git commit -m "várias alterações"
```

Quando terminar, verifique se tudo ocorreu bem. Execute o comando git status novamente. Provavelmente uma mensagem dirá que há uma diferença de alguns commits entre o repositório e o seu trabalho atual. Agora, para adicionar as alterações que você fez, execute um git push.

```
git push -u origin master
```

Pronto! Você se tornou um colaborador oficial de LP4ALL.

### Desejo colaborar com LINP. O que fazer?

Se deseja ser um colaborador de LINP, fale com o criador da biblioteca Gilberto Mourão. Ele dará orientações sobre como proceder. Futuramente será criado um documento explicando alguns detalhes da biblioteca. 