# 🚀 Campo Minado em C

Implementação do clássico jogo **Campo Minado** para terminal, desenvolvida em **linguagem C**.

O tabuleiro é gerado aleatoriamente a cada partida em uma grade **9x9** com **10 bombas escondidas**. O jogador informa as coordenadas de linha e coluna para revelar as casas. Se a posição estiver segura, o número de bombas adjacentes é exibido; caso não haja bombas nas vizinhanças, as casas ao redor são reveladas automaticamente em cascata.

O objetivo é descobrir todas as casas seguras sem explodir nenhuma bomba.

---

## ⚙️ Funcionalidades

✅ Grade com índices de linha e coluna para fácil navegação

✅ Geração aleatória do tabuleiro a cada nova partida

✅ Revelação em cascata utilizando **recursão (Flood Fill)**

✅ Cálculo automático de bombas adjacentes

✅ Detecção de vitória e derrota

✅ Validação de coordenadas inválidas

---

## 🛠️ Tecnologias Utilizadas

* Linguagem C
* Biblioteca padrão da linguagem C:

  * `stdio.h`
  * `stdlib.h`
  * `time.h`
* Compilador GCC
* Terminal / Console

---

## 📚 Conceitos Aplicados

Durante o desenvolvimento deste projeto foram praticados diversos conceitos fundamentais da programação:

* Programação Estruturada
* Modularização com Funções
* Matrizes Bidimensionais
* Estruturas de Repetição (`for` e `while`)
* Estruturas Condicionais (`if` e `else`)
* Geração de Números Aleatórios com `rand()`
* Recursão para revelação automática de áreas vazias
* Manipulação de Matrizes
* Entrada e Saída de Dados (`scanf()` e `printf()`)

---

## 🎮 Como Jogar

Ao iniciar o programa, um tabuleiro oculto é exibido no terminal.

O jogador deve informar:

* Linha (**0 a 8**)
* Coluna (**0 a 8**)

### Exemplo

```text
Digite a linha: 3
Digite a coluna: 5
```

Se a posição escolhida contiver uma bomba, o jogo termina imediatamente.

Caso contrário, a casa será revelada. Se ela possuir valor **0**, todas as casas vizinhas seguras serão abertas automaticamente.

---

## 🏆 Condições de Vitória

O jogador vence quando todas as posições que **não contêm bombas** forem reveladas.

---

## 💥 Condições de Derrota

O jogador perde ao selecionar qualquer posição contendo uma bomba.

Quando isso acontece, o tabuleiro completo é exibido mostrando todas as bombas e números gerados.

---

## 🎯 Objetivo do Projeto

Este projeto foi desenvolvido com o objetivo de aprofundar conhecimentos em **linguagem C** e **lógica de programação**, aplicando conceitos importantes utilizados no desenvolvimento de software, como:

* Manipulação de matrizes
* Algoritmos de busca
* Recursão
* Organização de código em funções
* Resolução de problemas computacionais

Além de reproduzir um jogo clássico, o projeto serviu como prática para a implementação de mecânicas interativas em ambiente de terminal.

---

## 👨‍💻 Autor

**Pedro Henrique Carlesso**

Projeto desenvolvido para fins de estudo, prática e aprimoramento das habilidades em programação na linguagem C.

