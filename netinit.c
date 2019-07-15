#include <netinit.h>

void net_config(char *address, char *netmask, char *gateway)
{
    ip_addr_t addr, mask, gtway;
    struct netdev *netdev = RT_NULL;

    inet_aton(address, &addr);
    inet_aton(netmask, &mask);
    inet_aton(gateway, &gtway);

    /* 通过名称获取网卡对象 */
    netdev = netdev_get_by_name("e0");
    if (netdev == RT_NULL)
    {
        rt_kprintf("input network interface name(e0) error.\n");
        return;
    }

    netdev_set_ipaddr(netdev, &addr);
    netdev_set_netmask(netdev, &mask);
    netdev_set_gw(netdev, &gtway);
}