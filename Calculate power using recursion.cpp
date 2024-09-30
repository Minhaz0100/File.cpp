#include <iostream>\n" +
                "using namespace std;\n" +
                "\n" +
                "int calculatePower(int, int);\n" +
                "\n" +
                "int main()\n" +
                "{\n" +
                "    int base, powerRaised, result;\n" +
                "\n" +
                "    cout << \"Enter base number: \";\n" +
                "    cin >> base;\n" +
                "\n" +
                "    cout << \"Enter power number(positive integer): \";\n" +
                "    cin >> powerRaised;\n" +
                "\n" +
                "    result = calculatePower(base, powerRaised);\n" +
                "    cout << base << \"^\" << powerRaised << \" = \" << result;\n" +
                "\n" +
                "    return 0;\n" +
                "}\n" +
                "\n" +
                "int calculatePower(int base, int powerRaised)\n" +
                "{\n" +
                "    if (powerRaised != 0)\n" +
                "        return (base*calculatePower(base, powerRaised-1));\n" +
                "    else\n" +
                "        return 1;\n" +
                "}
