#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *word) {
    const char *keywords[] = {"int", "float", "char", "if", "else", "for", "while", "return"};
    for (int i = 0; i < 8; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isIdentifier(char *word) {
    if (!isalpha(word[0]) && word[0] != '_')
        return 0;
    for (int i = 1; word[i]; i++) {
        if (!isalnum(word[i]) && word[i] != '_')
            return 0;
    }
    return 1;
}

int isNumber(char *word) {
    int dot = 0, i = 0;
    if (word[0] == '-' || word[0] == '+')
        i = 1;
    for (; word[i]; i++) {
        if (word[i] == '.') {
            if (dot) return 0;
            dot = 1;
        } else if (!isdigit(word[i]))
            return 0;
    }
    return (i > 0);
}

int main() {
    char input[200];
    printf("Enter an expression: ");
    scanf("%[^\n]", input);

    char token[50];
    int j = 0, len = strlen(input);

    char keyword[50][50], identifier[50][50], constant[50][50];
    char oper[50][5], parenthesis[50][5], punctuation[50][5], invalid[50][50];
    int kw = 0, id = 0, con = 0, op = 0, par = 0, punc = 0, inv = 0;

    for (int i = 0; i <= len; i++) {
        char ch = input[i];

        if ((ch == '-' || ch == '+') && isdigit(input[i + 1]) &&
            (i == 0 || input[i - 1] == '(' || input[i - 1] == '=' ||
             input[i - 1] == '+' || input[i - 1] == '-' ||
             input[i - 1] == '*' || input[i - 1] == '/' || isspace(input[i - 1]))) {
            token[j++] = ch;
            continue;
        }

        if (isspace(ch) || ch == ';' || ch == ',' || ch == '(' || ch == ')' ||
            ch == '{' || ch == '}' || ch == '[' || ch == ']' ||
            ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == 0) {

            if (j != 0) {
                token[j] = '\0';
                j = 0;

                if (isdigit(token[0]) || ((token[0] == '-' || token[0] == '+') && isdigit(token[1]))) {
                    int k = 0;
                    while (isdigit(token[k]) || token[k] == '.' || token[k] == '+' || token[k] == '-') k++;
                    if (token[k] != '\0')
                        strcpy(invalid[inv++], token);
                    else if (isNumber(token))
                        strcpy(constant[con++], token);
                    else
                        strcpy(invalid[inv++], token);
                }
                else if (isKeyword(token))
                    strcpy(keyword[kw++], token);
                else if (isIdentifier(token))
                    strcpy(identifier[id++], token);
                else if (isNumber(token))
                    strcpy(constant[con++], token);
                else
                    strcpy(invalid[inv++], token);
            }

            if (ch == '=' || ch == '*' || ch == '/' || ch == '-') {

                if (!(isdigit(input[i + 1]) && (ch == '-' || ch == '+') &&
                      (i == 0 || input[i - 1] == '(' || input[i - 1] == '=' ||
                       input[i - 1] == '+' || input[i - 1] == '-' ||
                       input[i - 1] == '*' || input[i - 1] == '/' || isspace(input[i - 1])))) {
                    char temp[2] = {ch, '\0'};
                    strcpy(oper[op++], temp);
                }
            }
            else if (ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
                     ch == '[' || ch == ']') {
                char temp[2] = {ch, '\0'};
                strcpy(parenthesis[par++], temp);
            }
            else if (ch == ';' || ch == ',') {
                char temp[2] = {ch, '\0'};
                strcpy(punctuation[punc++], temp);
            }
        }
        else {
            token[j++] = ch;
        }
    }

    printf("\n------------------------------------------\n");
    printf("Token_Keyword [%d] = { ", kw);
    for (int i = 0; i < kw; i++) printf("%s%s", keyword[i], (i < kw - 1) ? ", " : " ");
    printf("}\n");

    printf("Token_Identifier [%d] = { ", id);
    for (int i = 0; i < id; i++) printf("%s%s", identifier[i], (i < id - 1) ? ", " : " ");
    printf("}\n");

    printf("Token_Operator [%d] = { ", op);
    for (int i = 0; i < op; i++) printf("%s%s", oper[i], (i < op - 1) ? ", " : " ");
    printf("}\n");

    printf("Token_Constant [%d] = { ", con);
    for (int i = 0; i < con; i++) printf("%s%s", constant[i], (i < con - 1) ? ", " : " ");
    printf("}\n");

    printf("Token_Parenthesis [%d] = { ", par);
    for (int i = 0; i < par; i++) printf("%s%s", parenthesis[i], (i < par - 1) ? ", " : " ");
    printf("}\n");

    printf("Token_Punctuation [%d] = { ", punc);
    for (int i = 0; i < punc; i++) printf("%s%s", punctuation[i], (i < punc - 1) ? ", " : " ");
    printf("}\n");

    printf("Token_Invalid [%d] = { ", inv);
    for (int i = 0; i < inv; i++) printf("%s%s", invalid[i], (i < inv - 1) ? ", " : " ");
    printf("}\n");
    printf("------------------------------------------\n");

    return 0;
}
