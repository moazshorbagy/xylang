digit [0-9]
letter [A-Za-z]

%%
    /* Identifier */
{letter}({letter}|{digit})*  {printf("vname\n");}

%%

