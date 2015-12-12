# Nail
Lexer, Parser, Interpreter, and Compiler (to nasm) writtin in nim for a incomplete language. This will not be finished but may demonstrate how to do some of these things.
<br>
Look at the code in tests to see how it works<br>
Any code with functions defined will only run in the interpreter<br>
Syntax<br>
-Space based<br>
- fn -> Create a function<br>
- + -> add<br>
- - -> subtract<br>
- := -> Bind the value of one variable to others which allows for reactive properties (Ex. a = 5, b = 3, c := a + b, a = 1, c's value will change)<br>
- echo -> print to screen<br>
- func_name() -> call a function<br>
