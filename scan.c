#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// SDK C-based
// Give me all available Wifi Networks -> SSIDs
// type of SSID = u32
// dummuy version: return [ 42, 43, 45]

bool SSIDDiscover(uint32_t **SSIDList, uint32_t *SSIDListSize)
{
	*SSIDList = (uint32_t *) malloc(3 * sizeof(uint32_t));
	*(*(SSIDList) + 0) = 42;
	*(*(SSIDList) + 1) = 43;
	*(*(SSIDList) + 2) = 45;

  *SSIDListSize = 3;

  return true;
}

int main()
{
  uint32_t *SSIDList = NULL;
  uint32_t SSIDListSize = 0;

  if (!SSIDDiscover(&SSIDList, &SSIDListSize))
  {
    printf("Unable to discover SSIDs\n");
    return -1;
  }

	if (SSIDListSize == 0) {
		printf("No SSIDs found\n");
		return 0;
	}

  for (int i = 0; i < SSIDListSize; i++)
  {
    printf("SSID: %u\n", SSIDList[i]);
  }

  free(SSIDList);

  return 0;
}
