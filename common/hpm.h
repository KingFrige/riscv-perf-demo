#ifndef _HPM_H
#define _HPM_H

#define SET_PERFCNT(mhpmcnt, eventid, enventclass) \
  write_csr(mhpmcounter ## mhpmcnt, 0); \
  write_csr(mhpmevent ## mhpmcnt, HPM_EVENTID_ ## eventid|HPM_EVENTCLASS_ ## enventclass);

#define SHOW_PERFCNT(fmt, mhpmcnt) \
  printf(fmt, (int)(read_csr(mhpmcounter ## mhpmcnt)));

/*! @brief Macros for valid Event IDs */
#define HPM_EVENTID_8  (1UL << 8)
#define HPM_EVENTID_9  (1UL << 9)
#define HPM_EVENTID_10 (1UL << 10)
#define HPM_EVENTID_11 (1UL << 11)
#define HPM_EVENTID_12 (1UL << 12)
#define HPM_EVENTID_13 (1UL << 13)
#define HPM_EVENTID_14 (1UL << 14)
#define HPM_EVENTID_15 (1UL << 15)
#define HPM_EVENTID_16 (1UL << 16)
#define HPM_EVENTID_17 (1UL << 17)
#define HPM_EVENTID_18 (1UL << 18)
#define HPM_EVENTID_19 (1UL << 19)
#define HPM_EVENTID_20 (1UL << 20)
#define HPM_EVENTID_21 (1UL << 21)
#define HPM_EVENTID_22 (1UL << 22)
#define HPM_EVENTID_23 (1UL << 23)
#define HPM_EVENTID_24 (1UL << 24)
#define HPM_EVENTID_25 (1UL << 25)
#define HPM_EVENTID_26 (1UL << 26)
#define HPM_EVENTID_27 (1UL << 27)
#define HPM_EVENTID_28 (1UL << 28)
#define HPM_EVENTID_29 (1UL << 29)
#define HPM_EVENTID_30 (1UL << 30)
#define HPM_EVENTID_31 (1UL << 31)
#define HPM_EVENTID_32 (1UL << 32)
#define HPM_EVENTID_33 (1UL << 33)
#define HPM_EVENTID_34 (1UL << 34)
#define HPM_EVENTID_35 (1UL << 35)
#define HPM_EVENTID_36 (1UL << 36)
#define HPM_EVENTID_37 (1UL << 37)
#define HPM_EVENTID_38 (1UL << 38)
#define HPM_EVENTID_39 (1UL << 39)
#define HPM_EVENTID_40 (1UL << 40)

/*! @brief Macros for valid Event Class */
#define HPM_EVENTCLASS_0 (0UL)
#define HPM_EVENTCLASS_1 (1UL)
#define HPM_EVENTCLASS_2 (2UL)
#define HPM_EVENTCLASS_3 (3UL)
#define HPM_EVENTCLASS_4 (4UL)
#define HPM_EVENTCLASS_5 (5UL)
#define HPM_EVENTCLASS_6 (6UL)
#define HPM_EVENTCLASS_7 (7UL)
#define HPM_EVENTCLASS_8 (8UL)

#endif
