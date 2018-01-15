// Copyright (c) 2015-2016, tandasat. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

/// @file
/// Declares interfaces to the PageFaultRecord class.

#ifndef MEMORYMON_PAGEFAULTRECORD_H_
#define MEMORYMON_PAGEFAULTRECORD_H_

#include <fltKernel.h>
#undef _HAS_EXCEPTIONS
#define _HAS_EXCEPTIONS 0
#include <vector>

////////////////////////////////////////////////////////////////////////////////
//
// macro utilities
//

////////////////////////////////////////////////////////////////////////////////
//
// constants and macros
//

////////////////////////////////////////////////////////////////////////////////
//
// types
//

class PageFaultRecord {
 public:
  PageFaultRecord();

  void push(_In_ PETHREAD thread, _In_ void* guest_ip);
  bool has(_In_ PETHREAD thread) const;
  void* pop(_In_ PETHREAD thread);

 private:
  struct PageFaultRecordEntry {
    PETHREAD thread;
    void* guest_ip;
  };

  std::vector<PageFaultRecordEntry> record_;
  mutable KSPIN_LOCK record_spinlock_;
};

////////////////////////////////////////////////////////////////////////////////
//
// prototypes
//

////////////////////////////////////////////////////////////////////////////////
//
// variables
//

////////////////////////////////////////////////////////////////////////////////
//
// implementations
//

#endif  // MEMORYMON_PAGEFAULTRECORD_H_
