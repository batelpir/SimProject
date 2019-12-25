cmake_minimum_required(VERSION 3.15)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex3 main.cpp Parser.h Parser.cpp Singleton.h Var.h Singleton.cpp Sleep.cpp UpdatingCommand.h UpdatingCommand.cpp Print.cpp Expression.h BinaryOperator.h Variable.h Variable.cpp Plus.h Plus.cpp Minus.h Minus.cpp Mul.h Mul.cpp Div.h Div.cpp Value.h Value.cpp UnaryOperator.h UPlus.h UPlus.cpp UMinus.h UMinus.cpp Interpreter.h Interpreter.cpp DefineVarCommand.h DefineVarCommand.cpp Functions.h Functions.cpp OpenDataServerCommand.h OpenDataServerCommand.cpp ConnectControlClientCommand.h ConnectControlClientCommand.cpp)
