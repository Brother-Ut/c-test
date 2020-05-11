typedef enum inputTypeName {
    NUMBER,
    OPERATION
} inputType;

int CheckForExit(char *outChar, inputType type);
int StrToNumber (char* buf, int len);
int Add (int a, int b);
int Subtract (int a, int b);
int Multiply (int a, int b);
int Divide (int a, int b);
