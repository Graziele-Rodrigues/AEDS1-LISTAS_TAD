#include <stdio.h>
#include <stdlib.h>
#include "lista.c"
#include "interface.c"

//include "interface.h"


int main() {
  TLista L1;
  FLVazia(&L1);
  MENU(&L1);
  return 0;
}