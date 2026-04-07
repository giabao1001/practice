#include <unistd.h>
#include <stdio.h>
#include <iostream>
char cwd[1024];
int main (){
if (getcwd(cwd, sizeof(cwd)) != NULL) {
    std::cout << "Current working dir: " << cwd << std::endl;
}
return 0;
}