/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_provider.h
 *   \author   Alibaba-tianchi
 *   \date     July 2020
 *   \version  1.0.0
 *   \brief    Interface of AiTheta Index Provider
 */

#ifndef __AITHETA2_INDEX_PROVIDER_H__
#define __AITHETA2_INDEX_PROVIDER_H__

#include "index_holder.h"

namespace aitheta2 {

/*! Index Provider
 */
struct IndexProvider
{
    //! Index Provider Pointer
    typedef std::shared_ptr<IndexProvider> Pointer;

    //! Index Provider Iterator
    typedef IndexHolder::Iterator Iterator;

    //! Destructor
    virtual ~IndexProvider(void) {}

    //! Create a new iterator
    virtual Iterator::Pointer create_iterator(void) const = 0;

    //! Retrieve count of elements in provider
    virtual size_t count(void) const = 0;

    //! Retrieve dimension of vector
    virtual size_t dimension(void) const = 0;

    //! Retrieve type of vector
    virtual IndexMeta::FeatureTypes vector_type(void) const = 0;

    //! Retrieve vector size in bytes
    virtual size_t vector_size(void) const = 0;

    //! Retrieve a vector using a primary key
    virtual const void *get_vector(uint64_t key) const = 0;

    //! Retrieve an attachment using a primary key
    virtual const void *get_attachment(uint64_t key, size_t *len) const = 0;

    //! Retrieve the owner class
    virtual const std::string &owner_class(void) const = 0;
};

} // namespace aitheta2

#endif // __AITHETA2_INDEX_PROVIDER_H__
