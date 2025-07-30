
MEPA_DRV(LIB_NAME mepa_drv_dp83869
         SRCS     src/dp83869.c
         INCL_PUB ../../../me/include ../../include
         INCL_PRI dp83869)

option(MEPA_dp83869 "Add DP83869 support in libmeba" OFF)
if (${MEPA_dp83869})
    set(mepa_drvs ${mepa_drvs} mepa_drv_dp83869 CACHE INTERNAL "")
    set(mepa_defs ${mepa_defs} -DMEPA_HAS_dp83869 CACHE INTERNAL "")
endif()
