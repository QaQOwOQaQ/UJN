#ifndef ADDRESS_GUARD
#define ADDRESS_GUARD

#include <stdint.h>

#define SRAM_CACHE_TAG_LENGTH    (4)
#define SRAM_CACHE_INDEX_LENGTH  (6)
#define SRAM_CACHE_OFFSET_LENGTH (6)

#define PHYSICAL_ADDRESS_LENGTH     (16)
#define PHYSICAL_PAGE_NUMBER_LENGTH (4)     // 4 路组相连
#define PHYSICAL_PAGE_OFFSET_LENGTH (12)

#define VIRTUAL_ADDRESS_LENGTH     (48)
#define VIRTUAL_PAGE_NUMBER_LENGTH (9)      // 9 + 9 + 9 + 9 = 36
#define VIRTUAL_PAGE_OFFSET_LENGTH (12)     // 4 KB

#define TLB_CACHE_TAG_LENGTH        (32)
#define TLB_CACHE_INDEX_LENGTH      (4)
#define TLB_CACHE_OFFSET_LENGTH     (12)


/*
+--------+--------+--------+--------+---------------+
|  VPN2  |  VPN2  |  VPN3  |  VPN04 |               |
+--------+--------+--------+-+------+      VPO      |
|    TLBT                    | TLBI |               |
+---------------+------------+------+---------------+
                |        PPN        |      PPO      |
                +-------------------+--------+------+
                |        CT         |   CI   |  CO  |
                +-------------------+--------+------+
*/

/*因为cache是组相连映射，所在index用来找到在cache中的那个组，
因为可以匹配任意一行，所以只能类似for循环暴力查找位于哪一行，
在每一行匹配valid是否有效，并且tag是否相同。tag就是用来让我们知道这个数据是否匹配的
offset用来找块偏移，（其实就是字节偏移？）*/

typedef union
{
    uint64_t address_value;
    
    // physical address : 52
    struct 
    {
        union 
        {
            uint64_t paddr_value : PHYSICAL_ADDRESS_LENGTH;
            struct 
            {
                uint64_t ppo : PHYSICAL_PAGE_OFFSET_LENGTH;
                uint64_t ppn : PHYSICAL_PAGE_NUMBER_LENGTH;    
            }; 
        };
        
    };

    // sram cache: 48
    struct 
    {
        uint64_t co : SRAM_CACHE_OFFSET_LENGTH;
        uint64_t ci : SRAM_CACHE_INDEX_LENGTH;
        uint64_t ct : SRAM_CACHE_TAG_LENGTH;
    };

        
    // virtual address : 48
    struct 
    {
        union 
        {
            uint64_t vaddr_value : VIRTUAL_ADDRESS_LENGTH;
            struct 
            {
                uint64_t vpo  : VIRTUAL_PAGE_OFFSET_LENGTH;
                uint64_t vpn4 : VIRTUAL_PAGE_NUMBER_LENGTH;    
                uint64_t vpn3 : VIRTUAL_PAGE_NUMBER_LENGTH; 
                uint64_t vpn2 : VIRTUAL_PAGE_NUMBER_LENGTH; 
                uint64_t vpn1 : VIRTUAL_PAGE_NUMBER_LENGTH; 
            }; 
        };
    };

    // TLB cache: 48
    struct 
    {
        uint64_t tlbo : TLB_CACHE_OFFSET_LENGTH;   // virtual page offset
        uint64_t tlbi : TLB_CACHE_INDEX_LENGTH;    // TLB set index
        uint64_t tlbt : TLB_CACHE_TAG_LENGTH;      // TLB line tag
    };

} address_t;


#endif 