

gcc -Wall -std=c99  -g     -c .\Config\Config.c -o obj\Debug\Config\Config.o
#dres.exe  -J rc -O coff -i D:\SOFTWA~1\_A_ADE~1\ADERCT~2.6_\CTools.rc -o obj\Debug\CTools.res
gcc -Wall -std=c99  -g     -c .\Global\CTools.c -o obj\Debug\Global\CTools.o
gcc -Wall -std=c99  -g     -c .\Lexical\BinaryTuple.c -o obj\Debug\Lexical\BinaryTuple.o
gcc -Wall -std=c99  -g     -c .\Lexical\Lexical.c -o obj\Debug\Lexical\Lexical.o
gcc -Wall -std=c99  -g     -c .\Parser\Grammar.c -o obj\Debug\Parser\Grammar.o

gcc -Wall -std=c99  -g     -c .\Parser\Parser.c -o obj\Debug\Parser\Parser.o
gcc -Wall -std=c99  -g     -c .\Parser\StateStack.c -o obj\Debug\Parser\StateStack.o
gcc -Wall -std=c99  -g     -c .\Parser\SyntaxQueue.c -o obj\Debug\Parser\SyntaxQueue.o
gcc -Wall -std=c99  -g     -c .\Parser\SyntaxStack.c -o obj\Debug\Parser\SyntaxStack.o
gcc -Wall -std=c99  -g     -c .\Parser\SyntaxTable.c -o obj\Debug\Parser\SyntaxTable.o
gcc -Wall -std=c99  -g     -c .\Parser\SyntaxTree.c -o obj\Debug\Parser\SyntaxTree.o

gcc -Wall -std=c99  -g     -c .\Preprocessor\Preprocessor.c -o obj\Debug\Preprocessor\Preprocessor.o

gcc -Wall -std=c99  -g     -c .\Prop\Prop.c -o obj\Debug\Prop\Prop.o

gcc -Wall -std=c99  -g     -c .\Prop\PropFor.c -o obj\Debug\Prop\PropFor.o
gcc -Wall -std=c99  -g     -c .\Prop\PropRed.c -o obj\Debug\Prop\PropRed.o

gcc -Wall -std=c99  -g     -c .\Prop\PropTable.c -o obj\Debug\Prop\PropTable.o

gcc -Wall -std=c99  -g     -c .\Table\LiteralTable.c -o obj\Debug\Table\LiteralTable.o
gcc -Wall -std=c99  -g     -c .\Table\SymbolTable.c -o obj\Debug\Table\SymbolTable.o
gcc -Wall -std=c99  -g     -c .\Tools\Buffer.c -o obj\Debug\Tools\Buffer.o
gcc -Wall -std=c99  -g     -c .\Tools\CodeProp.c -o obj\Debug\Tools\CodeProp.o
gcc -Wall -std=c99  -g     -c .\Tools\Errors.c -o obj\Debug\Tools\Errors.o
gcc -Wall -std=c99  -g     -c .\Tools\Files.c -o obj\Debug\Tools\Files.o
gcc -Wall -std=c99  -g     -c .\Tools\GenParsTable\LALR.c -o obj\Debug\Tools\GenParsTable\LALR.o
gcc -Wall -std=c99  -g     -c .\Tools\GenParsTable\LR.c -o obj\Debug\Tools\GenParsTable\LR.o
gcc -Wall -std=c99  -g     -c .\Tools\GenParsTable\SLR.c -o obj\Debug\Tools\GenParsTable\SLR.o
gcc  -o bin\Debug\AderCTools.exe obj\Debug\Config\Config.o obj\Debug\Global\CTools.o obj\Debug\Lexical\BinaryTuple.o obj\Debug\Lexical\Lexical.o obj\Debug\Parser\Grammar.o obj\Debug\Parser\Parser.o obj\Debug\Parser\StateStack.o obj\Debug\Parser\SyntaxQueue.o obj\Debug\Parser\SyntaxStack.o obj\Debug\Parser\SyntaxTable.o obj\Debug\Parser\SyntaxTree.o obj\Debug\Preprocessor\Preprocessor.o obj\Debug\Prop\Prop.o obj\Debug\Prop\PropFor.o obj\Debug\Prop\PropRed.o obj\Debug\Prop\PropTable.o obj\Debug\Table\LiteralTable.o obj\Debug\Table\SymbolTable.o obj\Debug\Tools\Buffer.o obj\Debug\Tools\CodeProp.o obj\Debug\Tools\Errors.o obj\Debug\Tools\Files.o obj\Debug\Tools\GenParsTable\LALR.o obj\Debug\Tools\GenParsTable\LR.o obj\Debug\Tools\GenParsTable\SLR.o  obj\Debug\CTools.res   
