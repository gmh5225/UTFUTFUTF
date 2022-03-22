#include "UTF.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_utf16_to_utf8() {
  // only for testing
  printf("hello test utf16->utf8\n");
  auto pfread = fopen("E:\\Dbg\\dokany\\sys\\util\\ioctl.inc", "rb");
  if (pfread) {
    fseek(pfread, 0, SEEK_END);
    auto fileSize = (size_t)ftell(pfread);
    fseek(pfread, 0, SEEK_SET);
    printf("fileSize=%d\n", fileSize);
    auto fileBuf = calloc(1, fileSize + 10);
    if (fileBuf) {
      do {
        if (0 == fread(fileBuf, 1, fileSize, pfread)) {
          break;
        }

        char *outBuf = (char *)calloc(1, fileSize);
        UTF utf;
        utf.utf16To8_z((wchar_t *)fileBuf, outBuf);
        size_t outLen = strlen(outBuf);
        if (outLen) {
          auto pfwrite =
              fopen("E:\\Dbg\\dokany\\sys\\util\\ioctl.md.inc", "wb");
          if (pfwrite) {
            fwrite(outBuf, 1, outLen, pfwrite);
            fclose(pfwrite);
          }
        }

      } while (0);

      free(fileBuf);
    }
    fclose(pfread);
  }
}

int main() {

  test_utf16_to_utf8();
  return 0;
}
