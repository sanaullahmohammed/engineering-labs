### Execution Steps:

1. `lex 6b.l`
2. `yacc -d 6b.y`
3. `gcc lex.yy.c y.tab.c -lfl`
4. `./a.out`