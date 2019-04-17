yacc -d x.y
flex x.l
cc y.tab.c lex.yy.c
./a.out in.xy
