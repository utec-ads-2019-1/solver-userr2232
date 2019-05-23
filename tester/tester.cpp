#include "tester.h"

void Tester::execute() {
    string equations[] = {
        "7/4*((3+1)*3)+3",
        "7/4*((2+-+--8)*2)+3",
        "2+(3)",
        "7/4*((1+2)^4*2)+3",
        "7*-1",
        "1-2*5/2+1-2^4+1",
        "19+-+++-++++++9",
        "((7*3)/4+6*(3^2)/2)*(-1)",
        "(5+-3)+(21/3*5)-(5^3-2)",
        "(19--45/16*100-(181^2-15*10))",
        "((7*3)/4+6*(a^2)/b)*(1)",
        "7/4*((a+-+--b)*a)+3"
    };  

    float results[] = {
        24 ,
        -18,
        5,
        286.5,
        -7,
        -18,
        28,
        -32.25,
        -86,
        -32310.75,
        205.25, //10 y 3
        -60 //3 y 15
    };

    const unsigned int size = sizeof(equations) / sizeof(string);
    for (int i = 0; i < size; ++i) {
        Operation* root = Implementation::buildFromEquation(equations[i]);
        float respuesta = root->operate();
        ASSERT(respuesta == results[i], "The solver is not working");
        cout << "Equation(" << i + 1 << ") solved" << endl;
    }
}
