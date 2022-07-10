/*
#include<vector>
void vfun3(std::vector<int> x)    // takes pass-by-value + modification
{
    std::vector<int> r{1,2,3,4,5};
    x = r;
    return;
}
int main(){return 0;}


|-FunctionDecl 0x166f020 <./tests/test3.cpp:2:1, line:7:1> line:2:6 vfun3 'void (std::vector<int>)'
| |-ParmVarDecl 0x166ef10 <col:12, col:29> col:29 used x 'std::vector<int>':'std::vector<int, std::allocator<int>>' destroyed
| `-CompoundStmt 0x1692aa8 <line:3:1, line:7:1>
|   |-DeclStmt 0x16925a8 <line:4:5, col:34>
|   | `-VarDecl 0x1691570 <col:5, col:33> col:22 used r 'std::vector<int>':'std::vector<int, std::allocator<int>>' listinit destroyed
|   |   `-ExprWithCleanups 0x1692590 <col:22, col:33> 'std::vector<int>':'std::vector<int, std::allocator<int>>'
|   |     `-CXXConstructExpr 0x1692558 <col:22, col:33> 'std::vector<int>':'std::vector<int, std::allocator<int>>' 'void (initializer_list<std::vector<int, std::allocator<int>>::value_type>, const std::vector<int, std::allocator<int>>::allocator_type &)' list std::initializer_list
|   |       |-CXXStdInitializerListExpr 0x1692380 <col:23, col:33> 'initializer_list<std::vector<int, std::allocator<int>>::value_type>':'std::initializer_list<int>'
|   |       | `-MaterializeTemporaryExpr 0x1692368 <col:23, col:33> 'const int [5]' xvalue
|   |       |   `-InitListExpr 0x1692300 <col:23, col:33> 'const int [5]'
|   |       |     |-IntegerLiteral 0x16915d8 <col:24> 'int' 1
|   |       |     |-IntegerLiteral 0x16915f8 <col:26> 'int' 2
|   |       |     |-IntegerLiteral 0x1691618 <col:28> 'int' 3
|   |       |     |-IntegerLiteral 0x1691638 <col:30> 'int' 4
|   |       |     `-IntegerLiteral 0x1691658 <col:32> 'int' 5
|   |       `-CXXDefaultArgExpr 0x1692538 <<invalid sloc>> 'const std::vector<int, std::allocator<int>>::allocator_type':'const std::allocator<int>' lvalue
|   |-CXXOperatorCallExpr 0x1692a58 <line:5:5, col:9> 'std::vector<int, std::allocator<int>>' lvalue '='
|   | |-ImplicitCastExpr 0x1692a40 <col:7> 'std::vector<int, std::allocator<int>> &(*)(const std::vector<int, std::allocator<int>> &)' <FunctionToPointerDecay>
|   | | `-DeclRefExpr 0x16929f0 <col:7> 'std::vector<int, std::allocator<int>> &(const std::vector<int, std::allocator<int>> &)' lvalue CXXMethod 0x1684eb0 'operator=' 'std::vector<int, std::allocator<int>> &(const std::vector<int, std::allocator<int>> &)'
|   | |-DeclRefExpr 0x16925c0 <col:5> 'std::vector<int>':'std::vector<int, std::allocator<int>>' lvalue ParmVar 0x166ef10 'x' 'std::vector<int>':'std::vector<int, std::allocator<int>>'
|   | `-ImplicitCastExpr 0x16929a0 <col:9> 'const std::vector<int, std::allocator<int>>' lvalue <NoOp>
|   |   `-DeclRefExpr 0x16925e0 <col:9> 'std::vector<int>':'std::vector<int, std::allocator<int>>' lvalue Var 0x1691570 'r' 'std::vector<int>':'std::vector<int, std::allocator<int>>'
|   `-ReturnStmt 0x1692a98 <line:6:5>

*/

/*
#include<string>
void sfun3(std::string x)    // takes pass-by-value + modification
{
    x = "hello";
    return;
}
int main(){return 0;}


|-FunctionDecl 0x20a4430 <./tests/test3.cpp:37:1, line:41:1> line:37:6 sfun3 'void (std::string)'
| |-ParmVarDecl 0x20a4320 <col:12, col:24> col:24 used x 'std::string':'std::__cxx11::basic_string<char>' destroyed
| `-CompoundStmt 0x20a47d8 <line:38:1, line:41:1>
|   |-CXXOperatorCallExpr 0x20a4788 <line:39:5, col:9> 'std::__cxx11::basic_string<char>' lvalue '='
|   | |-ImplicitCastExpr 0x20a4770 <col:7> 'std::__cxx11::basic_string<char> &(*)(const char *)' <FunctionToPointerDecay>
|   | | `-DeclRefExpr 0x20a46e8 <col:7> 'std::__cxx11::basic_string<char> &(const char *)' lvalue CXXMethod 0x1f6b090 'operator=' 'std::__cxx11::basic_string<char> &(const char *)'
|   | |-DeclRefExpr 0x20a44d8 <col:5> 'std::string':'std::__cxx11::basic_string<char>' lvalue ParmVar 0x20a4320 'x' 'std::string':'std::__cxx11::basic_string<char>'
|   | `-ImplicitCastExpr 0x20a46d0 <col:9> 'const char *' <ArrayToPointerDecay>
|   |   `-StringLiteral 0x20a44f8 <col:9> 'const char [6]' lvalue "hello"
|   `-ReturnStmt 0x20a47c8 <line:40:5>

*/

/*
void ifun3(int x)
{
    x = 3;
    return;
}
int main(){return 0;}


|-FunctionDecl 0x20caea0 <./tests/test3.cpp:61:1, line:65:1> line:61:6 ifun3 'void (int)'
| |-ParmVarDecl 0x20cadd0 <col:12, col:16> col:16 used x 'int'
| `-CompoundStmt 0x20cb000 <line:62:1, line:65:1>
|   |-BinaryOperator 0x20cafd0 <line:63:5, col:9> 'int' lvalue '='
|   | |-DeclRefExpr 0x20caf90 <col:5> 'int' lvalue ParmVar 0x20cadd0 'x' 'int'
|   | `-IntegerLiteral 0x20cafb0 <col:9> 'int' 3
|   `-ReturnStmt 0x20caff0 <line:64:5>

*/

#include <string>
#include <iostream>
using namespace std;
class Car {
private:
    int weight;
    string color;

public:
    int maxSpeed;
    // constructor
    Car() {
        weight = 1000;
        color = "red";
        maxSpeed = 80;
    }
    Car(int weight, std::string color) {
        this->weight = weight;
        this->color = color;
    }

    // other functions
    void printColor() {
        cout << "Color of car is: " << this->color << endl;
    }
    int getWeight() {
        return this->weight;
    }
};
void someFun(Car mycar) {
    mycar.maxSpeed = 200;
}
int main(){return 0;}
/*

CUSTOM_CLASS
|-FunctionDecl 0x2341eb0 <line:109:1, line:111:1> line:109:6 someFun 'void (Car)'
| |-ParmVarDecl 0x2341de0 <col:14, col:18> col:18 used mycar 'Car' destroyed
| `-CompoundStmt 0x2342450 <col:25, line:111:1>
|   `-BinaryOperator 0x2341fc8 <line:110:5, col:22> 'int' lvalue '='
|     |-MemberExpr 0x2341f78 <col:5, col:11> 'int' lvalue .maxSpeed 0x23369f0
|     | `-DeclRefExpr 0x2341f58 <col:5> 'Car' lvalue ParmVar 0x2341de0 'mycar' 'Car'
|     `-IntegerLiteral 0x2341fa8 <col:22> 'int' 200


INT
|-FunctionDecl 0x20caea0 <./tests/test3.cpp:61:1, line:65:1> line:61:6 ifun3 'void (int)'
| |-ParmVarDecl 0x20cadd0 <col:12, col:16> col:16 used x 'int'
| `-CompoundStmt 0x20cb000 <line:62:1, line:65:1>
|   |-BinaryOperator 0x20cafd0 <line:63:5, col:9> 'int' lvalue '='
|   | |-DeclRefExpr 0x20caf90 <col:5> 'int' lvalue ParmVar 0x20cadd0 'x' 'int'
|   | `-IntegerLiteral 0x20cafb0 <col:9> 'int' 3
|   `-ReturnStmt 0x20caff0 <line:64:5>
*/

/*
|-FunctionDecl 0x1bd4e60 <line:125:1, line:128:1> line:125:6 class_modify_fun3 'void (Car)'
| |-ParmVarDecl 0x1bd4d90 <col:24, col:28> col:28 used mycar 'Car' destroyed
| `-CompoundStmt 0x1bd5d28 <col:35, line:128:1>
|   |-DeclStmt 0x1bd57a8 <line:126:5, col:41>
|   | `-VarDecl 0x1bd4f40 <col:5, col:40> col:10 used myNewcar 'Car *':'Car *' cinit
|   |   `-ExprWithCleanups 0x1bd5790 <col:21, col:40> 'Car *'
|   |     `-CXXNewExpr 0x1bd5690 <col:21, col:40> 'Car *' Function 0x10f96d8 'operator new' 'void *(std::size_t)'
|   |       `-CXXConstructExpr 0x1bd5658 <col:25, col:40> 'Car' 'void (int, std::string)'
|   |         |-IntegerLiteral 0x1bd4fa8 <col:29> 'int' 2000
|   |         `-CXXBindTemporaryExpr 0x1bd5638 <col:35> 'std::string':'std::__cxx11::basic_string<char>' (CXXTemporary 0x1bd5638)
|   |           `-CXXConstructExpr 0x1bd5600 <col:35> 'std::string':'std::__cxx11::basic_string<char>' 'void (std::__cxx11::basic_string<char> &&) noexcept' elidable
|   |             `-MaterializeTemporaryExpr 0x1bd55e8 <col:35> 'std::string':'std::__cxx11::basic_string<char>' xvalue
|   |               `-CXXBindTemporaryExpr 0x1bd55c8 <col:35> 'std::string':'std::__cxx11::basic_string<char>' (CXXTemporary 0x1bd55c8)
|   |                 `-ImplicitCastExpr 0x1bd55a8 <col:35> 'std::string':'std::__cxx11::basic_string<char>' <ConstructorConversion>
|   |                   `-CXXConstructExpr 0x1bd5570 <col:35> 'std::string':'std::__cxx11::basic_string<char>' 'void (const char *, const std::allocator<char> &)'
|   |                     |-ImplicitCastExpr 0x1bd5488 <col:35> 'const char *' <ArrayToPointerDecay>
|   |                     | `-StringLiteral 0x1bd4fc8 <col:35> 'const char [4]' lvalue "red"
|   |                     `-CXXDefaultArgExpr 0x1bd5550 <<invalid sloc>> 'const std::allocator<char>':'const std::allocator<char>' lvalue
|   `-CXXOperatorCallExpr 0x1bd5ce8 <line:127:5, col:14> 'Car' lvalue '='
|     |-ImplicitCastExpr 0x1bd5cd0 <col:11> 'Car &(*)(const Car &) noexcept(false)' <FunctionToPointerDecay>
|     | `-DeclRefExpr 0x1bd5848 <col:11> 'Car &(const Car &) noexcept(false)' lvalue CXXMethod 0x1bca520 'operator=' 'Car &(const Car &) noexcept(false)'
|     |-DeclRefExpr 0x1bd57c0 <col:5> 'Car' lvalue ParmVar 0x1bd4d90 'mycar' 'Car'
|     `-ImplicitCastExpr 0x1bd5830 <col:13, col:14> 'const Car' lvalue <NoOp>
|       `-UnaryOperator 0x1bd5818 <col:13, col:14> 'Car' lvalue prefix '*' cannot overflow
|         `-ImplicitCastExpr 0x1bd5800 <col:14> 'Car *':'Car *' <LValueToRValue>
|           `-DeclRefExpr 0x1bd57e0 <col:14> 'Car *':'Car *' lvalue Var 0x1bd4f40 'myNewcar' 'Car *':'Car *'
*/