# Boletim de uma Pequena Turma

## Identificação

- **Aluna:** Yasmin da Silva Justino
- **Disciplina:** Introdução às Técnicas de Programação (ITP)
- **Projeto:** Opção 1 — Boletim de uma pequena turma
- **Linguagem:** C

## Descrição

Este projeto consiste em um programa desenvolvido em C para registrar as notas de estudantes e gerar um resumo do desempenho de uma turma.
O programa permite cadastrar de 1 a 10 estudantes, registrar três notas por estudante, calcular as médias individuais e a média geral da turma, informar a situação de cada estudante e identificar aqueles que obtiveram a maior média.

## Funcionalidades

- Cadastro de 1 a 10 estudantes.
- Registro dos nomes dos estudantes.
- Leitura e validação de três notas por estudante, entre 0 e 10.
- Cálculo das médias individuais e da média geral da turma.
- Classificação em "Atingiu a meta" para médias maiores ou iguais a 6 e "Abaixo da meta" para as demais.
- Identificação da maior média, incluindo todos os estudantes empatados.
- Utilização de matrizes, strings, funções, ponteiros e alocação dinâmica de memória.

## Tecnologias e conceitos utilizados

- Linguagem C.
- Matrizes e vetores.
- Strings e validação de entradas.
- Funções.
- Ponteiros.
- Alocação dinâmica de memória com `malloc` e liberação com `free`.
- Laços de repetição e estruturas condicionais.

## Compilação e execução

O programa pode ser compilado utilizando o GCC.

Comando para compilação:

O programa  pode ser executado no OnlineGDB, selecionando a linguagem C e clicando em Run.

## Testes

### Teste 1 — Funcionamento normal

**Entradas:**

- Quantidade de estudantes: 2
- Ana: notas 5, 6 e 7.
- Bruno: notas 8, 7 e 9.

**Resultados esperados:**

- Ana: média 6,00 — Atingiu a meta.
- Bruno: média 8,00 — Atingiu a meta.
- Média geral da turma: 7,00.
- Maior média: 8,00.
- Estudante com a maior média: Bruno.

### Teste 2 — Entrada inválida

**Entrada:** informar a nota 11.

**Resultado esperado:** o programa rejeita a nota e solicita um novo valor entre 0 e 10.

### Teste 3 — Empate na maior média

**Entradas:**

- Ana: notas 8, 8 e 8.
- Bruno: notas 7, 8 e 9.

**Resultado esperado:** ambos obtêm média 8,00 e aparecem na lista de estudantes com a maior média.

## Vídeo de apresentação

Link do vídeo no YouTube: https://youtu.be/Bo9rJq_WyiI

## Referências

- Material didático da disciplina ITP.
- Aulas sobre matrizes, tipos de dados, strings, estrutura de memória, memória estática e heap, ponteiros e alocação dinâmica.
