

mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Config\Config.c -o obj\Debug\Config\Config.o
windres.exe  -J rc -O coff -i D:\SOFTWA~1\_A_ADE~1\ADERCT~2.6_\CTools.rc -o obj\Debug\CTools.res
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Global\CTools.c -o obj\Debug\Global\CTools.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Lexical\BinaryTuple.c -o obj\Debug\Lexical\BinaryTuple.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Lexical\Lexical.c -o obj\Debug\Lexical\Lexical.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Parser\Grammar.c -o obj\Debug\Parser\Grammar.o

mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Parser\Parser.c -o obj\Debug\Parser\Parser.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Parser\StateStack.c -o obj\Debug\Parser\StateStack.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Parser\SyntaxQueue.c -o obj\Debug\Parser\SyntaxQueue.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Parser\SyntaxStack.c -o obj\Debug\Parser\SyntaxStack.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Parser\SyntaxTable.c -o obj\Debug\Parser\SyntaxTable.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Parser\SyntaxTree.c -o obj\Debug\Parser\SyntaxTree.o

mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Preprocessor\Preprocessor.c -o obj\Debug\Preprocessor\Preprocessor.o

mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Prop\Prop.c -o obj\Debug\Prop\Prop.o

mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Prop\PropFor.c -o obj\Debug\Prop\PropFor.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Prop\PropRed.c -o obj\Debug\Prop\PropRed.o

mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Prop\PropTable.c -o obj\Debug\Prop\PropTable.o

mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Table\LiteralTable.c -o obj\Debug\Table\LiteralTable.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Table\SymbolTable.c -o obj\Debug\Table\SymbolTable.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Tools\Buffer.c -o obj\Debug\Tools\Buffer.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Tools\CodeProp.c -o obj\Debug\Tools\CodeProp.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Tools\Errors.c -o obj\Debug\Tools\Errors.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Tools\Files.c -o obj\Debug\Tools\Files.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Tools\GenParsTable\LALR.c -o obj\Debug\Tools\GenParsTable\LALR.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Tools\GenParsTable\LR.c -o obj\Debug\Tools\GenParsTable\LR.o
mingw32-gcc.exe -Wall -std=c99  -g     -c D:\SoftwareEngineer\[A]AderStep\AderCTools[0.5.6]\Tools\GenParsTable\SLR.c -o obj\Debug\Tools\GenParsTable\SLR.o
mingw32-g++.exe  -o bin\Debug\AderCTools.exe obj\Debug\Config\Config.o obj\Debug\Global\CTools.o obj\Debug\Lexical\BinaryTuple.o obj\Debug\Lexical\Lexical.o obj\Debug\Parser\Grammar.o obj\Debug\Parser\Parser.o obj\Debug\Parser\StateStack.o obj\Debug\Parser\SyntaxQueue.o obj\Debug\Parser\SyntaxStack.o obj\Debug\Parser\SyntaxTable.o obj\Debug\Parser\SyntaxTree.o obj\Debug\Preprocessor\Preprocessor.o obj\Debug\Prop\Prop.o obj\Debug\Prop\PropFor.o obj\Debug\Prop\PropRed.o obj\Debug\Prop\PropTable.o obj\Debug\Table\LiteralTable.o obj\Debug\Table\SymbolTable.o obj\Debug\Tools\Buffer.o obj\Debug\Tools\CodeProp.o obj\Debug\Tools\Errors.o obj\Debug\Tools\Files.o obj\Debug\Tools\GenParsTable\LALR.o obj\Debug\Tools\GenParsTable\LR.o obj\Debug\Tools\GenParsTable\SLR.o  obj\Debug\CTools.res   
Output size is 702.76 KB