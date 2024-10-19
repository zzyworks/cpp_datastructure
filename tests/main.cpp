#include "test_string_pm.hpp"

int
main(int argc, char* argv[]) {
  if(3 > argc) {
    fprintf(stderr,
            "\nUsage: %s <Pattern> <Text>\n\nFor example %s people \"now is "
            "the time for all good people to come\"\n\n",
            argv[0], argv[0]);
    return -1;
  }
  for(int i = 0; i < (argc - 1) / 2 * 2; i += 2) {
    /*DSA*/ printf("####################################################\n");
    /*DSA*/ printf("Text:     ");
    printString(argv[i + 2]);
    printf("\n");
    /*DSA*/ printf("Pattern:  ");
    printString(argv[i + 1]);
    printf("\n");
    int pos = match3(argv[i + 2], argv[i + 1]);
    /*DSA*/ if(strlen(argv[i + 2]) < pos + strlen(argv[i + 1]))
      printf("No matching found\n");
    /*DSA*/ else
      printf("Matching found at #%d\n", pos);
  }
  return 0;
}