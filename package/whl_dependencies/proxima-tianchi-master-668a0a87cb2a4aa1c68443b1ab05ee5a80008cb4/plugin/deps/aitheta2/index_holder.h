/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_holder.h
 *   \author   Alibaba-tianchi
 *   \date     July 2020
 *   \version  2.0.0
 *   \brief    Interface of AiTheta Index Holder
 */

#ifndef __AITHETA2_INDEX_HOLDER_H__
#define __AITHETA2_INDEX_HOLDER_H__

#include "index_meta.h"
#include "index_params.h"
#include <list>
#include <memory>
#include <utility>
#include <vector>

namespace aitheta2 {

/*! Index Holder
 */
struct IndexHolder
{
    //! Index Holder Pointer
    typedef std::shared_ptr<IndexHolder> Pointer;

    /*! Index Holder Iterator
     */
    struct Iterator
    {
        //! Index Holder Iterator Pointer
        typedef std::unique_ptr<Iterator> Pointer;

        //! Destructor
        virtual ~Iterator(void) {}

        //! Retrieve pointer of data
        virtual const void *data(void) const = 0;

        //! Test if the iterator is valid
        virtual bool is_valid(void) const = 0;

        //! Retrieve primary key
        virtual uint64_t key(void) const = 0;

        //! Next iterator
        virtual void next(void) = 0;
    };

    //! Destructor
    virtual ~IndexHolder(void) {}

    //! Retrieve count of elements in holder (-1 indicates unknown)
    virtual size_t count(void) const = 0;

    //! Retrieve dimension
    virtual size_t dimension(void) const = 0;

    //! Retrieve type information
    virtual IndexMeta::FeatureTypes type(void) const = 0;

    //! Retrieve element size in bytes
    virtual size_t element_size(void) const = 0;

    //! Retrieve if it can multi-pass
    virtual bool multipass(void) const = 0;

    //! Create a new iterator
    virtual Iterator::Pointer create_iterator(void) = 0;

    //! Test if matchs the meta
    bool is_matched(const IndexMeta &meta) const
    {
        return (this->type() == meta.type() &&
                this->dimension() == meta.dimension() &&
                this->element_size() == meta.element_size());
    }
};

} // namespace aitheta2

#endif // __AITHETA2_INDEX_HOLDER_H__
