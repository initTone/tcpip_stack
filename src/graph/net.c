#include "net.h"
#include "graph.h"
#include "utility.h"

void intf_assign_mac_address(interface_t * intf)
{
  mac_addr_t * mac;
  mac = &intf->intf_props.mac_addr;

  for(int i = 0; i < MAC_ADDR_LEN; i++)
  {
      mac->mac[i] = random_nuber();
  }
}
