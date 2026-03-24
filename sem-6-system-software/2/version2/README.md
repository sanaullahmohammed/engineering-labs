### Execution Steps:

1. `lex 2.l`
2. `bison -dy 2.y` (or) `yacc -d 2.y`
3. `gcc lex.yy.c y.tab.c -ll`
4. `./a.out`