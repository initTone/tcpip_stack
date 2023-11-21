#ifndef NET_H
#define NET_H

#include <stdbool.h>
#include <memory.h>

#define IP_ADDR_LEN 16
#define MAC_ADDR_LEN 12

typedef struct interface_ interface_t;

typedef struct ip6_addr_
{
    unsigned char ip_addr[IP_ADDR_LEN];
} ip6_addr_t;

typedef struct mac_addr_
{
    unsigned char mac[MAC_ADDR_LEN];
} mac_addr_t;

typedef struct node_props_
{
  bool lb_addr_config;
  ip6_addr_t lb_ip6_addr;
} node_props_t;

typedef struct intf_props_
{
  mac_addr_t mac_addr;
  bool is_ipadd_config;
  ip6_addr_t ip6_addr;
  char mask;
} intf_props_t;

static inline void
init_node_prop(node_props_t * node_prop)
{
  node_prop->lb_addr_config = false;
  memset(node_prop->lb_ip6_addr.ip_addr, 0, IP_ADDR_LEN);
};

static inline void
init_intf_prop(intf_props_t * intf_prop)
{
  memset(intf_prop->mac_addr.mac, 0, MAC_ADDR_LEN);
  intf_prop->is_ipadd_config = false;
  memset(intf_prop->ip6_addr.ip_addr, 0, IP_ADDR_LEN);
  intf_prop->mask = 0;
};

void intf_assign_mac_address(interface_t * intf);

#define IF_MAC(intf_ptr) (intf_ptr->intf_props.mac_addr.mac)

#define IF_IP(intf_ptr) (intf_ptr->intf_props.ip6_addr.ip_addr)

#define NODE_LB_ADDR(node_ptr) (node_ptr->node_props.lb_ip6_addr.ip_addr)

#define IS_INTF_L3_MODE(intf_ptr) (intf_ptr->intf_props.is_ipadd_config == true)

#endif
