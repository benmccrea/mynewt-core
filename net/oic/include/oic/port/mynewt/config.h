/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef CONFIG_H
#define CONFIG_H


#ifdef __cplusplus
extern "C" {
#endif

/* Time resolution */
#include <inttypes.h>
#include "os/mynewt.h"

#include <log/log.h>

/* rather than change all their source files, just translate the mynewt
 * package defines into their defines here */
#if (MYNEWT_VAL(OC_SERVER) == 1)
#define OC_SERVER
#endif

#if (MYNEWT_VAL(OC_CLIENT) == 1)
#define OC_CLIENT
#endif

#if (MYNEWT_VAL(OC_DEBUG) == 1)
#define DEBUG 1
#endif

typedef os_time_t oc_clock_time_t;
#define OC_CLOCK_CONF_TICKS_PER_SECOND (OS_TICKS_PER_SEC)
#ifdef ARCH_sim
#define OC_CLK_FMT  "%u"
#else
#define OC_CLK_FMT  "%lu"
#endif

/* Server-side parameters */
/* Maximum number of server resources */
#define MAX_APP_RESOURCES MYNEWT_VAL(OC_APP_RESOURCES)

/* Common paramters */
/* Maximum number of concurrent requests */
#define MAX_NUM_CONCURRENT_REQUESTS MYNEWT_VAL(OC_CONCURRENT_REQUESTS)

/* Estimated number of nodes in payload tree structure */
#define EST_NUM_REP_OBJECTS MYNEWT_VAL(OC_NUM_REP_OBJECTS)

/* Maximum size of request/response PDUs */
#define MAX_PAYLOAD_SIZE    MYNEWT_VAL(OC_MAX_PAYLOAD_SIZE)

/* Number of devices on the OCF platform */
#define MAX_NUM_DEVICES     MYNEWT_VAL(OC_NUM_DEVICES)

/* Platform payload size */
#define MAX_PLATFORM_PAYLOAD_SIZE MYNEWT_VAL(OC_MAX_PAYLOAD)

/* Device payload size */
#define MAX_DEVICE_PAYLOAD_SIZE   MYNEWT_VAL(OC_MAX_PAYLOAD)

/* Security layer */
/* Maximum number of authorized clients */
//#define MAX_NUM_SUBJECTS (2)

/* Maximum number of concurrent DTLS sessions */
//#define MAX_DTLS_PEERS (1)

/* Max inactivity timeout before tearing down DTLS connection */
//#define DTLS_INACTIVITY_TIMEOUT (10)

#ifdef __cplusplus
}
#endif

#endif /* CONFIG_H */
