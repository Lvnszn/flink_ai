/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_container.h
 *   \author   Alibaba-tianchi
 *   \date     July 2020
 *   \version  2.0.0
 *   \brief    Interface of AiTheta Index Container
 */

#ifndef __AITHETA2_INDEX_CONTAINER_H__
#define __AITHETA2_INDEX_CONTAINER_H__

#include "index_module.h"

namespace aitheta2 {

/*! Index Container
 */
class IndexContainer : public IndexModule
{
public:
    //! Index Container Pointer
    typedef std::shared_ptr<IndexContainer> Pointer;

    /*! Index Container Segment Data
     */
    struct SegmentData
    {
        //! Constructor
        SegmentData(void) : offset(0u), length(0u), data(nullptr) {}

        //! Constructor
        SegmentData(size_t off, size_t len)
            : offset(off), length(len), data(nullptr)
        {
        }

        //! Members
        size_t offset;
        size_t length;
        const void *data;
    };

    /*! Index Container Segment
     */
    struct Segment
    {
        //! Index Container Pointer
        typedef std::shared_ptr<Segment> Pointer;

        //! Destructor
        virtual ~Segment(void) {}

        //! Retrieve size of data
        virtual size_t data_size(void) const = 0;

        //! Retrieve crc of data
        virtual uint32_t data_crc(void) const = 0;

        //! Retrieve size of padding
        virtual size_t padding_size(void) const = 0;

        //! Read data from segment
        virtual size_t read(size_t offset, const void **data, size_t len) = 0;

        //! Read data from segment
        virtual bool read(SegmentData *iovec, size_t count) = 0;

        //! Clone the segment
        virtual Pointer clone(void) = 0;
    };

    //! Destructor
    virtual ~IndexContainer(void) {}

    //! Initialize container
    virtual int init(const IndexParams &params) = 0;

    //! Cleanup container
    virtual int cleanup(void) = 0;

    //! Load a index file into container
    virtual int load(const std::string &path) = 0;

    //! Unload all indexes
    virtual int unload(void) = 0;

    //! Retrieve a segment by id
    virtual Segment::Pointer get(const std::string &id) const = 0;

    //! Retrieve all segments
    virtual std::map<std::string, Segment::Pointer> get_all(void) const = 0;

    //! Retrieve Index Meta
    virtual const IndexMeta &meta(void) const = 0;

    //! Retrieve magic number of index
    virtual uint32_t magic(void) const = 0;
};

} // namespace aitheta2

#endif // __AITHETA2_INDEX_CONTAINER_H__
