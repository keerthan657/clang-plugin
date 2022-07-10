# clang-plugin
Clang diagnostic plugin to warn users about modified pass-by-value arguments in function declarations

Credits to mahesh-hegde<br>
For more information, refer here: https://github.com/mahesh-hegde/clang_diag_plugin

For compiling, use this command:<br>
```console
cmake . && cmake --build .
clang-11 -lstdc++ -fplugin=./CS01.so ./tests/test1.cpp
```
