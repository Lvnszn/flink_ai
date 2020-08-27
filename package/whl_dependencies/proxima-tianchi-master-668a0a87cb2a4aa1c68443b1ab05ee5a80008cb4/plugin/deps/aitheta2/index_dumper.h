/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_dumper.h
 *   \author   Alibaba-tianchi
 *   \date     July 2020
 *   \version  2.0.0
 *   \brief    Interface of AiTheta Index Dumper
 */

#ifndef __AITHETA2_INDEX_DUMPER_H__
#define __AITHETA2_INDEX_DUMPER_H__

#include "index_meta.h"
#include "index_module.h"
#include "index_params.h"

namespace aitheta2 {

/*! Index Dumper
 */
class IndexDumper : public IndexModule
{
public:
    //! Index Dumper Pointer
    typedef std::shared_ptr<IndexDumper> Pointer;

    //! Destructor
    virtual ~IndexDumper(void) {}

    //! Initialize dumper
    virtual int init(const IndexParams &params) = 0;

    //! Cleanup dumper
    virtual int cleanup(void) = 0;

    //! Create a file for dumping
    virtual int create(const std::string &path) = 0;

    //! Close file
    virtual int close(void) = 0;

    //! Append a segment meta into table
    virtual int append(const std::string &id, size_t data_size,
                       size_t padding_size, uint32_t crc) = 0;

    //! Write data to the storage
    virtual size_t write(const void *data, size_t len) = 0;

    //! Retrieve Mutable Index Meta
    virtual IndexMeta *mutable_meta(void) = 0;

    //! Retrieve Index Meta
    virtual const IndexMeta &meta(void) const = 0;

    //! Retrieve magic number of index
    virtual uint32_t magic(void) const = 0;
};

} // namespace aitheta2

#endif // __AITHETA2_INDEX_DUMPER_H__
