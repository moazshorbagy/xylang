# xylang
A new programming language project.

Xylan represents third most abundant biopolymer on Earth. It's a yellow, water-soluble, gummy polysaccharide found in plant cell walls and yielding xylose upon hydrolysis.

# to compile the compiler do the following
flex x.l
yacc -d x.y
cc y.tab.c lex.yy.c
./a.out

or simply do this

./run.sh
