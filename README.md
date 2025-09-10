# my-shell   

REPL - Read Eval Print Loop

* 1. Read User Input    
 
To read User Input, we can use the `linenoise` Library from antirez   
 https://github.com/antirez/linenoise   



* 2. Tokenize User Input   

(CMD ARG1 ARG2 ...)   

To read user input and break them into tokens, we can use the `strtok` function glibc   


* 3. Execute Commands   

To execute commands we can use `fork()` and `execv()` system calls.   


* 4. Support For Builtins 

