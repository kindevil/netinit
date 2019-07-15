#include <netinit.h>

void net_config()
{
    ip_addr_t addr, mask, gtway;
    struct netdev *netdev = RT_NULL;

    cJSON* address = cJSON_GetObjectItem(network, "address");
    cJSON* netmask = cJSON_GetObjectItem(network, "netmask");
    cJSON* gateway = cJSON_GetObjectItem(network, "gateway");

    rt_kprintf("###########################\n");
    rt_kprintf("# address: %s \n", address->valuestring);
    rt_kprintf("# netmask: %s \n", netmask->valuestring);
    rt_kprintf("# gateway: %s \n", gateway->valuestring);
    rt_kprintf("###########################\n");

    inet_aton(address->valuestring, &addr);
    inet_aton(netmask->valuestring, &mask);
    inet_aton(gateway->valuestring, &gtway);

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