# 🌳 binaryTreeSearch

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

Implementação de uma **árvore binária de busca** em C, com suporte a pesquisa por prefixo.

---

## 📖 Descrição

Projeto desenvolvido para praticar estruturas de dados.  
Permite inserir elementos em uma árvore binária e realizar buscas por prefixo, retornando todos os itens que começam com determinada sequência de caracteres.

---

## 🎯 Objetivos

- Exercitar implementação de árvores binárias em C  
- Permitir inserção e busca eficiente de dados  
- Demonstrar a aplicação de busca por prefixo  

---

## ✨ Funcionalidades

- Inserção de elementos na árvore  
- Busca por prefixo em todos os nós  
- Impressão dos resultados encontrados  

---

## ⚙️ Detalhes Técnicos

- Estrutura baseada em **árvore binária simples** (não balanceada)  
- Cada nó contém um valor e ponteiros para filho esquerdo/direito  
- Busca percorre a árvore comparando o prefixo com os valores armazenados  

---

## 💻 Exemplo de Uso

```c
// Inserindo valores
insert(root, "apple");
insert(root, "ape");
insert(root, "banana");
insert(root, "band");

// Buscando por prefixo
searchByPrefix(root, "ba"); // retorna "banana", "band"
