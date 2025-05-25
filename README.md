# Jogo Batalha Naval com Habilidades Especiais (C)

Este projeto é uma implementação simples do clássico jogo Batalha Naval em linguagem C, com um toque a mais: habilidades especiais com áreas de efeito distintas.

---

## Funcionalidades

- Tabuleiro fixo de tamanho 10x10 representado por uma matriz bidimensional.
- Posicionamento fixo de navios no tabuleiro (valores 3).
- Criação dinâmica de áreas de efeito para três habilidades especiais:
    - **Cone**: área em forma de cone, expandindo para baixo.
    - **Cruz**: área em forma de cruz, centrada.
    - **Octaedro**: área em forma de losango, centrada.
- Sobreposição das áreas de efeito ao tabuleiro, marcando as posições afetadas com valor 5.
- Impressão do tabuleiro no console, mostrando água (0), navios (3) e áreas afetadas (5).

---

## Estrutura do Código

- `inicializaTabuleiro()`: Inicializa o tabuleiro com água (0).
- `posicionaNavioHorizontal()` e `posicionaNavioVertical()`: Posicionam navios fixos no tabuleiro.
- `criaMatrizCone()`, `criaMatrizCruz()` e `criaMatrizOctaedro()`: Geram matrizes 5x5 representando as áreas das habilidades especiais usando loops e condicionais.
- `aplicaHabilidade()`: Sobrepõe a matriz da habilidade ao tabuleiro, marcando a área de efeito.
- `imprimeTabuleiro()`: Imprime o tabuleiro com valores legíveis no console.

---

## Como Executar

1. Compile o código fonte com um compilador C, por exemplo:

```bash
gcc batalha_naval.c -o batalha_naval
```
2. Execute o programa:

```bash
./batalha_naval
```

3. Veja a saída no console com o tabuleiro mostrando navios e áreas de efeito das habilidades.

## Exemplo de Saída

``` bash
Tabuleiro (0=Agua, 3=Navio, 5=Habilidade):
0 0 0 0 0 0 0 0 0 0 
0 0 3 3 3 0 0 0 0 0 
0 3 3 3 3 3 0 0 0 0 
0 0 3 3 3 3 3 0 0 0 
0 0 0 5 5 5 3 5 5 5 
0 0 0 0 5 5 3 5 5 5 
0 0 0 0 0 5 5 5 5 5 
0 5 5 5 5 5 5 5 3 5 
0 0 5 0 0 5 0 0 3 5 
0 0 0 0 0 5 0 0 0 0 
```

## Notas
As posições dos navios e pontos de origem das habilidades são fixas e definidas diretamente no código.

A validação de sobreposição é simplificada, mas impede que habilidades sobrescrevam navios.

O programa foca em representar visualmente o tabuleiro e as áreas das habilidades, sem lógica de ataque ou dano.

## Autor
Desenvolvido por Marcos Braga

