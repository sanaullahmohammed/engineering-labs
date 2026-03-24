### Execution Steps

1. `lex 1b.l`
2. `bison -dy 1b.y` (or) `yacc -d 1b.y`
3. `gcc lex.yy.c y.tab.c -ll`
4. `./a.out`