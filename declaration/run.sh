flex x.l
yacc -d x.y
cc y.tab.c lex.yy.c
./a.out
